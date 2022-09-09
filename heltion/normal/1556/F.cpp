#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 14;
constexpr LL mod = 1000000007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
LL a[maxn];
LL dp[1 << maxn];
LL p[maxn][1 << maxn];
LL d[maxn][maxn];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i += 1) cin >> a[i];
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1) {
            d[i][j] = a[i] * power(a[i] + a[j], mod - 2) % mod;
            //cout << i << " " << j << " " << d[i][j] << "\n";
        }
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < (1 << n); j += 1) {
            p[i][j] = 1;
            for (int k = 0; k < n; k += 1)
                if ((j >> k) & 1) 
                    p[i][j] = p[i][j] * d[i][k] % mod;
        }
    for (int i = 0; i < (1 << n); i += 1) {
        for (int j = (i - 1) & i; j; j = (j - 1) & i) {
            LL x = dp[j];
            for (int k = 0; k < n; k += 1)
                if ((j >> k) & 1)
                    x = x * p[k][i - j] % mod;
            dp[i] = (dp[i] + x) % mod;
        }
        dp[i] = (mod + 1 - dp[i]) % mod;
    }
    LL ans = 0;
    for (int i = 0; i < (1 << n); i += 1) {
        LL x = dp[i];
        for (int k = 0; k < n; k += 1)
            if ((i >> k) & 1)
                x = x * p[k][(1 << n) - 1 - i] % mod;
        ans = (ans + x * __builtin_popcount(i)) % mod;
    }
    cout << ans;
    return 0;
}