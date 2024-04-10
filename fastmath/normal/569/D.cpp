#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 4007;
const int MAXE = MAXN * MAXN;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int C[MAXN][MAXN];
int all[MAXN], dp[MAXN];

void prec() {
    for (int i = 0; i < MAXN; ++i) {
        C[i][0] = 1;
    }   
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = mod(C[i - 1][j] + C[i - 1][j - 1]);
        }   
    }      
    all[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 2; j <= i; ++j) {
            all[i] = mod(all[i] + C[i - 1][j - 1] * all[i - j]);
        }   
        all[i] = mod(all[i] + all[i - 1] * 2);
    }   
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            int ost = i - j;
            //cout << i << ' ' << j << " : " << C[i][j] << ' ' << (all[ost] - dp[ost]) << '\n';
            dp[i] = mod(dp[i] + C[i][j] * (all[ost] - dp[ost]));
        }   
    }   
    cout << dp[n] << '\n';
    return 0;
}