#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

const int MAXN = 2007;

int dp[MAXN][MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    dp[1][0] = m;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = m;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = mod(dp[i - 1][j - 1] * (m - 1) + dp[i - 1][j]);
        }
    }

    cout << dp[n][k] << '\n';
    return 0;
}