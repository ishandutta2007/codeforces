#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int mod;
void add(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
void sub(int& x, int y) {
    x -= y;
    if (x < 0) x += mod;
}
constexpr int maxn = 50 + 1;
constexpr int maxm = 1225 + 1;
int dp[maxn][maxm], sum[maxn][maxm], c[maxn][maxn], f[maxn];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n >> mod;
    int m = n * (n - 1) / 2;
    for (int i = 1; i <= n; i += 1){
        for (int j = 0; j <= m; j += 1) {
            if (i != 1) {
                dp[i][j] = sum[i - 1][j];
                if (j >= i) sub(dp[i][j], sum[i - 1][j - i]);
            }
            else dp[i][j] = j == 0;
            sum[i][j] = dp[i][j];
            if (j) {
                add(sum[i][j], sum[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= n; i += 1){
        f[i] = i ? (LL)f[i - 1] * i % mod : 1;
        for (int j = 0; j <= i; j += 1)
            c[i][j] = j ? (c[i - 1][j] + c[i - 1][j - 1]) % mod : 1;
    }
    int ans = 0;
    for (int i = 4; i <= n; i += 1){
        int pans = 0;
        for (int j = 1; j <= i; j += 1)
            for (int k = j + 1; k <= i; k += 1)
                for (int x = k - j + 1; x <= m; x += 1)
                    add(pans, (LL)sum[i - 1][x - 1 + j - k] * dp[i - 1][x] % mod);
        add(ans, (LL)pans * f[n - i] % mod * c[n][n - i] % mod);
    }
    cout << ans;
    return 0;
}