#pragma once

#include "esphome/components/climate_ir/climate_ir.h"

namespace esphome {
    namespace mhi {
        // Temperature
        const uint8_t MHI_TEMP_MIN = 18; // Celsius
        const uint8_t MHI_TEMP_MAX = 30; // Celsius

        class MhiClimate : public climate_ir::ClimateIR {
            protected:
                void transmit_state() override;
                /// Handle received IR Buffer
                bool on_receive(remote_base::RemoteReceiveData data) override;
                ClimateTraits traits() override {
                    auto traits = climate::ClimateTraits();
                    traits.set_supported_modes(
                    {
                        climate::CLIMATE_MODE_OFF,
                        climate::CLIMATE_MODE_COOL,
                        climate::CLIMATE_MODE_HEAT,
                        climate::CLIMATE_MODE_FAN_ONLY,
                        climate::CLIMATE_MODE_DRY,
                        climate::CLIMATE_MODE_AUTO
                    });
                    traits.set_supported_fan_modes(
                    {
                        climate::CLIMATE_FAN_AUTO, climate::CLIMATE_FAN_LOW,
                        climate::CLIMATE_FAN_MEDIUM, climate::CLIMATE_FAN_HIGH,
                        climate::CLIMATE_FAN_MIDDLE, climate::CLIMATE_FAN_FOCUS,
                        climate::CLIMATE_FAN_DIFFUSE
                    });
                    traits.set_supported_swing_modes(
                    {
                        climate::CLIMATE_SWING_OFF, climate::CLIMATE_SWING_VERTICAL,
                        climate::CLIMATE_SWING_HORIZONTAL, climate::CLIMATE_SWING_BOTH
                    });
                    traits.set_visual_min_temperature(MHI_TEMP_MIN);
                    traits.set_visual_max_temperature(MHI_TEMP_MAX);
                    traits.set_visual_temperature_step(1.0f);
                    return traits;
                }
        };
    } // namespace mhi
} // namespace esphome
