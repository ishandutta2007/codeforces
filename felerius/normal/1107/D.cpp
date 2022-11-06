#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

static constexpr array<array<uint8_t, 4>, 16> BIN = {{
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1},
    {1,0,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {1,1,0,1},
    {1,1,1,0},
    {1,1,1,1},
}};

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<uint32_t> rect_sums;
    rect_sums.reserve(n * n);
    for (size_t y = 0; y < n; ++y) {
        cin.get();
        uint32_t line_sum = 0;
        for (size_t x = 0; x < n / 4; ++x) {
            char c = cin.get();
            auto& bins = c >= 'A' ? BIN[10 + (c - 'A')] : BIN[c - '0'];
            for (size_t dx = 0; dx < 4; ++dx) {
                line_sum += bins[dx];
                rect_sums.emplace_back(line_sum);
                if (y > 0) {
                    rect_sums.back() += rect_sums[rect_sums.size() - n - 1];
                }
            }
        }
    }

    uint32_t max = 1;
    for (uint32_t d = 2; d <= n; ++d) {
        if (n % d != 0) {
            continue;
        }

        bool valid = true;
        for (size_t y = d - 1; valid && y < n; y += d) {
            for (size_t x = d - 1; valid && x < n; x += d) {
                auto sum = rect_sums[y * n + x];
                if (x > d && y > d) {
                    sum += rect_sums[(y - d) * n + x - d];
                }
                if (x > d) {
                    sum -= rect_sums[y * n + x - d];
                }
                if (y > d) {
                    sum -= rect_sums[(y - d) * n + x];
                }

                valid &= (sum == 0 || sum == d * d);
            }
        }

        if (valid) {
            max = d;
        }
    }

    cout << max << '\n';

    return 0;
}