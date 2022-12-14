#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 1ll << 62));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || s[i - 1] == '0' && s[i] == '0') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + a);
            }
            dp[i][1] = min(dp[i - 1][0] + a, dp[i - 1][1]) + b;
        }

        cout << dp[n][0] + ll(a + b) * n + b << '\n';
    }
}