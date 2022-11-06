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

// Contest: Codeforces Round #568 (Div. 2) (https://codeforces.com/contest/1185)
// Problem: G1: Playlist for Polycarp (easy version) (https://codeforces.com/contest/1185/problem/G1)

using namespace std;

struct Counts {
    array<uint32_t, 3 * 16 * 16 * 16> data = {0};

    uint32_t& operator()(int prev, int c1, int c2, int c3) {
        return data[prev * 16*16*16 + c1 * 16*16 + c2 * 16 + c3];
    }
};

constexpr uint32_t MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    uint32_t t;
    cin >> n >> t;

    vector<pair<int, int>> songs(n);
    for (auto& si : songs) {
        cin >> si.first >> si.second;
        --si.second;
    }

    Counts c;
    c(0, 0, 0, 0) = 1;
    c(1, 0, 0, 0) = 1;
    c(2, 0, 0, 0) = 1;
    for (int c1 = 0; c1 <= 15; ++c1) {
        for (int c2 = 0; c2 <= 15; ++c2) {
            for (int c3 = 0; c3 <= 15; ++c3) {
                for (int prev = 0; prev <= 2; ++prev) {
                    if (c1 + c2 + c3 == 0) {
                        continue;
                    }

                    uint64_t t = 0;
                    if (prev != 0 && c1 > 0) {
                        t += (uint64_t)c1 * c(0, c1 - 1, c2, c3);
                        t %= MOD;
                    }
                    if (prev != 1 && c2 > 0) {
                        t += (uint64_t)c2 * c(1, c1, c2 - 1, c3);
                        t %= MOD;
                    }
                    if (prev != 2 && c3 > 0) {
                        t += (uint64_t)c3 * c(2, c1, c2, c3 - 1);
                        t %= MOD;
                    }

                    c(prev, c1, c2, c3) = t;
                }
            }
        }
    }

    uint64_t ot = 0;
    for (uint32_t i = 1; i < (uint32_t)1 << n; ++i) {
        int total_length = 0;
        array<uint64_t, 3> gc = {0, 0, 0};
        for (size_t j = 0; j < n; ++j) {
            if (i & (1u << j)) {
                total_length += songs[j].first;
                gc[songs[j].second]++;
            }
        }

        if (total_length != t) {
            continue;
        }

        if (gc[0] > 0) {
            ot += gc[0] * c(0, gc[0] - 1, gc[1], gc[2]);
            ot %= MOD;
        }
        if (gc[1] > 0) {
            ot += gc[1] * c(1, gc[0], gc[1] - 1, gc[2]);
            ot %= MOD;
        }
        if (gc[2] > 0) {
            ot += gc[2] * c(2, gc[0], gc[1], gc[2] - 1);
            ot %= MOD;
        }
    }

    cout << ot << '\n';

    return 0;
}