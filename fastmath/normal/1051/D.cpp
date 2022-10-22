#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

const int MAXN = 2007;

int dp[MAXN][4][MAXN];

int d[4][4];

void prec() {
    d[0][0] = 0;
    d[0][1] = 1;
    d[0][2] = 1;
    d[0][3] = 1;

    d[1][0] = 0;
    d[1][1] = 0;
    d[1][2] = 2;
    d[1][3] = 0;

    d[2][0] = 0;
    d[2][1] = 2;
    d[2][2] = 0;
    d[2][3] = 0;

    d[3][0] = 1;
    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 0;
}

int get(int n, int nm) {
    return d[n][nm];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    prec();

    int n, k;
    cin >> n >> k;

    dp[0][0][1] = 1;
    dp[0][1][2] = 1;
    dp[0][2][2] = 1;
    dp[0][3][1] = 1;

    for (int i = 0; i < n - 1; ++i) {
        for (int m = 0; m < 4; ++m) {
            for (int t = 0; t < MAXN; ++t) {
                for (int nm = 0; nm < 4; ++nm) {
                    int add = get(m, nm); 
                    if (t + add < MAXN) {
                        dp[i + 1][nm][t + add] = mod(dp[i + 1][nm][t + add] + dp[i][m][t]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += dp[n - 1][i][k];
    }
    cout << mod(ans) << '\n';

    return 0;
}