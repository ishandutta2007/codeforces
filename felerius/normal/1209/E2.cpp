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
// Problem: E2: Rotate Columns (hard version) (https://codeforces.com/contest/1209/problem/E2)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[j][i];

        vector<pair<int, int>> col_max(m);
        for (int i = 0; i < m; ++i)
            col_max[i] = {*max_element(begin(a[i]), end(a[i])), i};
        sort(begin(col_max), end(col_max), greater<>{});
        vector<vector<int>> b(n, vector<int>(n));
        for (int i = 0; i < min(n, m); ++i)
            b[i] = move(a[col_max[i].second]);

        vector<vector<int>> choice(n, vector<int>(1u << n));
        for (int i = 0; i < n; ++i) {
            for (uint32_t m = 0; m < (1u << n); ++m) {
                for (int r = 0; r < n; ++r) {
                    int val = 0;
                    for (int j = 0; j < n; ++j)
                        val += ((m >> j) & 1) * b[i][(j + r) % n];
                    choice[i][m] = max(choice[i][m], val);
                }
            }
        }

        vector<int> dp(1u << n), dp_prev(1u << n);
        for (int i = 0; i < n; ++i) {
            for (uint32_t m = 0; m < (1u << n); ++m) {
                dp[m] = choice[i][m];
                for (auto sm = m; sm != 0; sm = (sm - 1) & m)
                    dp[m] = max(dp[m], choice[i][m & ~sm] + dp_prev[sm]);
            }
            swap(dp, dp_prev);
        }

        cout << dp_prev[(1u << n) - 1] << '\n';
    }

    return 0;
}