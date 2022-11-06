#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    auto impos = -1;

    array<int64_t, 10> dp;
    array<int64_t, 10> dp_prev = {0,impos,impos,impos,impos,impos,impos,impos,impos,impos};

    for (size_t turn = 0; turn < n; ++turn) {
        array<int64_t, 3> best_1 = {0, 0, 0};
        int64_t best_2 = 0;
        int64_t best_3 = 0;

        size_t k;
        cin >> k;
        for (size_t i = 0; i < k; ++i) {
            int c;
            int64_t d;
            cin >> c >> d;

            if (c == 1) {
                array<int64_t, 1> d_arr = {d};
                array<int64_t, 4> merged;
                merge(begin(best_1), end(best_1), begin(d_arr), end(d_arr), begin(merged), std::greater{});
                best_1 = {merged[0], merged[1], merged[2]};
            } else if (c == 2) {
                best_2 = max(best_2, d);
            } else {
                best_3 = max(best_3, d);
            }
        }

        dp = {impos,impos,impos,impos,impos,impos,impos,impos,impos,impos};
        for (size_t i = 0; i < 10; ++i) {
            if (dp_prev[i] == impos) {
                continue;
            }

            dp[i] = max(dp[i], dp_prev[i]);

            auto best_one_card = max({best_1[0], best_2, best_3});
            dp[(i + 1) % 10] = max(dp[(i + 1) % 10], dp_prev[i] + (i == 9 ? best_one_card * 2 : best_one_card));

            int64_t best_a, best_b;
            if (best_2 > best_1[0]) {
                best_a = best_2;
                best_b = best_1[0];
            } else if (best_2 > best_1[1]) {
                best_a = best_1[0];
                best_b = best_2;
            } else {
                best_a = best_1[0];
                best_b = best_1[1];
            }
            if (best_b > 0) {
                auto gain = i == 8 || i == 9 ? 2 * best_a + best_b : best_a + best_b;
                dp[(i + 2) % 10] = max(dp[(i + 2) % 10], dp_prev[i] + gain);
            }

            if (best_1[2] > 0) {
                auto gain = (i == 7 || i == 8 || i == 9 ? best_1[0] * 2 : best_1[0]) + best_1[1] + best_1[2];
                dp[(i + 3) % 10] = max(dp[(i + 3) % 10], dp_prev[i] + gain);
            }
        }

        swap(dp, dp_prev);
    }

    int64_t max = 0;
    for (size_t i = 0; i < 10; ++i) {
        if (dp_prev[i] != impos) {
            max = std::max(max, dp_prev[i]);
        }
    }
    cout << max << '\n';

    return 0;
}