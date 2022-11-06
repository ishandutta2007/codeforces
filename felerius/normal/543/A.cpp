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

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (22) Writing Code (Difficulty: 4) (http://codeforces.com/problemset/problem/543/A)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, m, b;
    uint32_t mod;
    cin >> n >> m >> b >> mod;

    vector<vector<uint32_t>> dp(m + 1, vector<uint32_t>(b + 1, 0));
    dp[0][0] = 1;
    for (size_t i = 0; i < n; ++i) {
        size_t ai;
        cin >> ai;

        for (size_t j = 1; j <= m; ++j) {
            for (size_t k = ai; k <= b; ++k) {
                dp[j][k] = (dp[j][k] + dp[j - 1][k - ai]) % mod;
            }
        }
    }

    uint32_t total = 0;
    for (auto i : dp[m]) {
        total = (total + i) % mod;
    }
    cout << total << '\n';

    return 0;
}