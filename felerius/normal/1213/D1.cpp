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

// Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
// Problem: D2: Equalizing by Division (hard version) (https://codeforces.com/contest/1213/problem/D2)

using namespace std;

array<array<size_t, 19>, 200'001> dp;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    for (auto& dpi : dp) {
        dpi.fill(0);
    }

    for (size_t i = 0; i < n; ++i) {
        uint32_t ai; cin >> ai;
        size_t d = 0;
        while (ai > 0) {
            dp[ai][d]++;
            ai /= 2;
            ++d;
        }

        dp[ai][d]++;
    }

    size_t mi = 1'000'000'000;
    for (auto & dpi : dp) {
        size_t cost = 0;
        auto rem = k;
        for (size_t i = 0; rem > 0 && i < 19; ++i) {
            auto add = min(rem, dpi[i]);
            rem -= add;
            cost += i * add;
        }

        if (rem == 0) {
            mi = min(mi, cost);
        }
    }

    cout << mi << '\n';

    return 0;
}