#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2) (https://codeforces.com/contest/1209)
// Problem: E1: Rotate Columns (easy version) (https://codeforces.com/contest/1209/problem/E1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto& row : a)
            for (auto& aij : row)
                cin >> aij;

        vector<int> dp(1u << n), dp_prev(1u << n);
        for (int i = 0; i < m; ++i) {
            dp.assign(dp.size(), 0);
            for (uint32_t j = 0; j < (1u << n); ++j) {
                for (uint32_t k = 0; k < (1u << n); ++k) {
                    if (k & ~j)
                        continue;
                    auto here_bits = j & ~k;
                    for (int r = 0; r < n; ++r) {
                        int here = 0;
                        for (int x = 0; x < n; ++x) {
                            here += ((here_bits >> x) & 1u) * a[(x + r) % n][i];
                        }

                        dp[j] = max(dp[j], here + dp_prev[k]);
                    }
                }
            }

            swap(dp, dp_prev);
        }

        cout << dp_prev[(1u << n) - 1] << '\n';
    }

    return 0;
}