#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
const int N = 107;
int dp[N][N];
int res[N][N];
int tmp[N][N];
void mult(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= MOD;
            }   
        }   
    }   
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) a[i][j] = tmp[i][j];
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin); cout.precision(20);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; ++i) {
        res[i][i] = 1;
    }   
    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            dp[i][i + 1] = 1;
        }
    }   
    dp[0][0] = 1;
    dp[m - 1][0] = 1;
    for (int p = 0; (1ll << p) <= n; ++p) {
        if ((n >> p) & 1) {
            mult(res, dp);
        }   
        mult(dp, dp);
    }   
    cout << res[0][0] << '\n';
}