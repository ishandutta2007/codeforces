#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (20) Greg and Friends (Difficulty: 5) (http://codeforces.com/problemset/problem/295/C)

using namespace std;

constexpr uint32_t MOD = 1e9 + 7;
static array<uint32_t, 51> FAC = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 227020758, 178290591, 674358851, 789741546, 425606191, 660911389, 557316307, 146326063, 72847302, 602640637, 860734560, 657629300, 440732388, 459042011, 394134213, 35757887, 36978716, 109361473, 390205642, 486580460, 57155068, 943272305, 14530444, 523095984, 354551275, 472948359, 444985875, 799434881, 776829897, 626855450, 954784168, 10503098, 472639410, 741412713, 846397273, 627068824, 726372166, 318608048};
static array<uint32_t, 51> FAC_INV = {1, 1, 500000004, 166666668, 41666667, 808333339, 301388891, 900198419, 487524805, 831947206, 283194722, 571199524, 380933296, 490841026, 320774361, 821384963, 738836565, 514049213, 639669405, 402087866, 120104394, 862862120, 130130097, 179570875, 799148792, 791965957, 761229465, 917082579, 282752951, 699405279, 123313510, 649139150, 957785605, 604781386, 958964165, 170256120, 671396008, 261389083, 243720767, 211377457, 230284438, 469031331, 654024560, 317535457, 393580354, 297635121, 202122504, 366002609, 861791727, 854322286, 57086446};

struct Dp {
    array<uint32_t, 51 * 51 * 101 * 2> data;

    uint32_t& operator()(size_t c1, size_t c2, size_t trips_left, bool over) {
        return data[c1 * 51*101*2 + c2 * 101*2 + trips_left * 2 + (size_t)over];
    }
};

uint32_t mod_mul(uint32_t a, uint32_t b) {
    return ((uint64_t)a * (uint64_t)b) % MOD;
}

uint32_t choose(size_t n, size_t k) {
    return mod_mul(mod_mul(FAC[n], FAC_INV[k]), FAC_INV[n - k]);
}

void mod_add_mul(uint32_t& target, uint32_t a, uint32_t b, uint32_t c) {
    target = (target + mod_mul(mod_mul(a, b), c)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;
    k /= 50;

    array<size_t, 2> counts = {0};
    for (size_t i = 0; i < n; ++i) {
        uint32_t j;
        cin >> j;
        counts[(j / 50) - 1]++;
    }

    if (counts[1] > 0 && k < 2) {
        cout << "-1\n0\n";
        return 0;
    }

    Dp dp;
    for (size_t c1 = 0; c1 <= counts[0]; ++c1) {
        for (size_t c2 = 0; c2 <= counts[1]; ++c2) {
            dp(c1, c2, 0, false) = 0;
            dp(c1, c2, 0, true) = 0;
        }
    }
    dp(0, 0, 0, true) = 1;

    for (size_t trips = 1; trips <= 101; ++trips) {
        for (size_t c1 = 0; c1 <= counts[0]; ++c1) {
            for (size_t c2 = 0; c2 <= counts[1]; ++c2) {
                uint32_t pos = 0;
                for (size_t c1p = 0; c1p <= min(c1, k); ++c1p) {
                    auto c1_pos = choose(c1, c1p);
                    for (size_t c2p = (c1p == 0 ? 1 : 0); c2p <= min(c2, (k - c1p) / 2); ++c2p) {
                        auto c2_pos = choose(c2, c2p);
                        mod_add_mul(pos,
                                    dp(c1 - c1p, c2 - c2p, trips - 1, true),
                                    c1_pos, c2_pos);
                    }
                }

                dp(c1, c2, trips, false) = pos;
            }
        }

        if (dp(counts[0], counts[1], trips, false) != 0) {
            cout << (2 * trips - 1) << '\n' << dp(counts[0], counts[1], trips, false) << '\n';
            return 0;
        }

        for (size_t c1 = 0; c1 <= counts[0]; ++c1) {
            for (size_t c2 = 0; c2 <= counts[1]; ++c2) {
                auto c1_over = counts[0] - c1;
                auto c2_over = counts[1] - c2;
                uint32_t pos = 0;
                for (size_t c1p = 0; c1p <= min(c1_over, k); ++c1p) {
                    auto c1_pos = choose(c1_over, c1p);
                    for (size_t c2p = (c1p == 0 ? 1 : 0); c2p <= min(c2_over, (k - c1p) / 2); ++c2p) {
                        auto c2_pos = choose(c2_over, c2p);
                        mod_add_mul(pos, dp(c1 + c1p, c2 + c2p, trips, false), c1_pos, c2_pos);
                    }
                }

                dp(c1, c2, trips, true) = pos;
            }
        }
    }

    cout << "-1\n0\n";
    return 0;
}