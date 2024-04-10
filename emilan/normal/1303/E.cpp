#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

bool solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    for (int q = 0; q <= m; q++) {
        vector<vector<int>> dp(n + 1, vector<int>(q + 1, -INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int l = 0; l <= q; l++) {
                if (dp[i][l] < 0) continue;

                int r = dp[i][l] + q;
                if (l < q && t[l] == s[i]) {
                    dp[i + 1][l + 1] = max(dp[i + 1][l + 1], dp[i][l]);
                }

                if (r < m && t[r] == s[i]) {
                    dp[i + 1][l] = max(dp[i + 1][l], dp[i][l] + 1);
                }

                dp[i + 1][l] = max(dp[i + 1][l], dp[i][l]);
            }
        }

        if (dp[n][q] == m - q) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? (char *[]){"yes", "yeS", "yEs", "yES", "Yes", "YeS", "YEs", "YES"}[tc & 7] : (char *[]){"no", "nO", "No", "NO"}[tc & 3]) << '\n';
    }
}