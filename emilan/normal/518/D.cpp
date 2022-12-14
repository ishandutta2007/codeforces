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
    int n, t;
    double p;
    cin >> n >> p >> t;

    vt<vt<double>> dp(t + 1, vt<double>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j + 1] += dp[i][j] * p;
            dp[i + 1][j] += dp[i][j] * (1 - p);
        }

        dp[i + 1][n] += dp[i][n];
    }

    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[t][i] * i;
    }

    cout << setprecision(7) << fixed << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}