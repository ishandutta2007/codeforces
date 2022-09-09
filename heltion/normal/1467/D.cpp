#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000 + 2;
LL dp[maxn][maxn];
LL w[maxn], a[maxn];
constexpr LL mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, q, debug = 0;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 0; i <= k; i += 1)
        for(int j = 1; j <= n; j += 1){
            if(not i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
            if(debug) cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    LL ans = 0;
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= k + 1; j += 1)
            w[i] = (w[i] + dp[j - 1][i] * dp[k + 1 - j][i]) % mod;
        if(debug) cout << i << " " << w[i] << "\n";
        ans = (ans + w[i] * a[i]) % mod;
    }
    for(; q; q -= 1){
        int i, x;
        cin >> i >> x;
        ans = (ans + mod - w[i] * a[i] % mod) % mod;
        a[i] = x;
        ans = (ans + w[i] * a[i]) % mod;
        cout << ans << "\n";
    }
    return 0;
}