// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <mp-units/bits/module_macros.h>

// IWYU pragma: begin_exports
#include <mp-units/systems/isq/base_quantities.h>

#ifndef MP_UNITS_IN_MODULE_INTERFACE
#include <mp-units/framework/quantity_spec.h>
#endif
// IWYU pragma: end_exports

MP_UNITS_EXPORT
namespace mp_units::isq {

// space and time
QUANTITY_SPEC(width, length);
inline constexpr auto breadth = width;
QUANTITY_SPEC(radius, width);  // differs from ISO 80000
QUANTITY_SPEC(path_length, length);
inline constexpr auto arc_length = path_length;
QUANTITY_SPEC(area, pow<2>(length));
QUANTITY_SPEC(angular_measure, dimensionless, arc_length / radius, is_kind);
QUANTITY_SPEC(solid_angular_measure, dimensionless, area / pow<2>(radius), is_kind);
QUANTITY_SPEC(period_duration, duration);
inline constexpr auto period = period_duration;
QUANTITY_SPEC(frequency, inverse(period_duration));

// mechanics
QUANTITY_SPEC(energy, mass* pow<2>(length) / pow<2>(time));  // differs from ISO 80000 (defined in thermodynamics)

// atomic_and_nuclear_physics
QUANTITY_SPEC(activity, inverse(duration));
QUANTITY_SPEC(absorbed_dose, energy / mass);
QUANTITY_SPEC(ionizing_radiation_quality_factor, dimensionless);
QUANTITY_SPEC(dose_equivalent, absorbed_dose* ionizing_radiation_quality_factor);

}  // namespace mp_units::isq
