#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    int ans = 0;
    vt<vt<int>> dp(n + 1, vt<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i][j] + 2, dp[i + 1][j + 1]);
                ans = max(dp[i + 1][j + 1], ans);
            }

            dp[i + 1][j] = max(dp[i][j] - 1, dp[i + 1][j]);
            dp[i][j + 1] = max(dp[i][j] - 1, dp[i][j + 1]);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}