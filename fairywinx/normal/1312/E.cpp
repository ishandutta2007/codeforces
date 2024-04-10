#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    for (int i = 0; i < n; ++i) {
        dp[i][i + 1] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len;
            for (int k = i + 1; k < j; ++k) {
                if (dp[i][k] != -1 && dp[i][k] == dp[k][j]) {
                    dp[i][j] = dp[i][k] + 1;
                }
            }
        }
    }

    vector<int> ans(n + 1, n + 228);
    ans[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[j][i + 1] != -1) {
                ans[i + 1] = min(ans[i + 1], ans[j] + 1);
            }
        }
    }
    cout << ans.back() << '\n';
}