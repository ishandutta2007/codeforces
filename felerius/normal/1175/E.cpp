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

// Contest: Educational Codeforces Round 66 (Rated for Div. 2) (https://codeforces.com/contest/1175)
// Problem: E: Minimal Segment Cover (https://codeforces.com/contest/1175/problem/E)

using namespace std;

constexpr size_t MAXVAL = 500'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    vector<pair<size_t, size_t>> intervals(n);
    for (auto& ii : intervals) {
        cin >> ii.first >> ii.second;
    }

    sort(begin(intervals), end(intervals));
    vector<array<size_t, 19>> dp(MAXVAL + 1);

    auto it = begin(intervals);
    size_t interval_right = 0;
    for (size_t i = 0; i <= MAXVAL; ++i) {
        while (it != end(intervals) && it->first == i) {
            interval_right = max(interval_right, (it++)->second);
        }

        dp[i][0] = interval_right;
        if (interval_right == i) {
            interval_right = 0;
        }
    }

    for (size_t exp = 1; exp < 19; ++exp) {
        for (int i = MAXVAL; i >= 0; --i) {
            dp[i][exp] = dp[dp[i][exp - 1]][exp - 1];
        }
    }

    while (m--) {
        size_t x, y;
        cin >> x >> y;

        int exp = 0;
        while (exp < 19 && dp[x][exp] < y) {
            ++exp;
        }

        if (exp == 19) {
            cout << "-1\n";
            continue;
        }

        --exp;
        size_t count = 0;
        size_t left = x;
        while (left < y && exp >= 0) {
            left = dp[left][exp];
            count += 1u << exp;
            while (exp >= 0 && dp[left][exp] >= y) {
                --exp;
            }
        }

        if (left < y) {
            ++count;
        }

        cout << count << '\n';
    }

    return 0;
}