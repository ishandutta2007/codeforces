#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2001;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    if (n < 0) return (n % MOD + MOD) % MOD;
    else if (n < MOD) return n;
    else if (n < 2 * MOD) return n - MOD;
    else return n % MOD;
}   
int dp[N][N], sum_not_eq[N][N], sum[N][N];
int f[N];
int f1[N];
int getsum(int i, int j) {
    if (i == -1) {
        return j == 0;
    }   
    else {
        return sum[i][j];
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        int ans = 1;
        for (char c : s) {
            ans = mod(ans * (c - 'a' + 1));
        }   
        cout << ans << '\n';
        exit(0);
    }   
    f[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        f[i] = mod(f[i + 1] * (s[i] - 'a' + 1));
    }   
    f1[0] = 1;
    for (int i = 0; i < n; ++i) {
        f1[i + 1] = mod(f1[i] * (s[i] - 'a' + 1));
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i && (j + 1) * (n - i) <= k; ++j) {
            int x = (j + 1) * (n - i);
            if (j == i) {
                ++dp[i][x];
            }
            else {
                int p = i - 1 - j;
                dp[i][x] = mod(dp[i][x] + (s[p] - 'a') * f1[p]);
            }   
        }   
        for (int j = 0; j <= k; ++j) {
            for (int p = 0; p <= i && (p + 1) * (n - i) <= j; ++p) {
                int pos = i - 1 - p;
                int w = j - (p + 1) * (n - i);
                if (w) {
                    dp[i][j] = mod(dp[i][j] + sum_not_eq[pos][w]);
                }
            }   
            dp[i][j] = mod(dp[i][j] * ('z' - s[i]));
        }   
        for (int j = 0; j <= k; ++j) {
            sum[i][j] = mod(getsum(i - 1, j) * (s[i] - 'a' + 1) + dp[i][j]);
            sum_not_eq[i][j] = mod(sum[i][j] - getsum(i - 1, j));
        }   
        ans = mod(ans + dp[i][k] * f[i + 1]);
    }   
    cout << ans << '\n';
}