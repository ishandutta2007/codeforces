#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 1000000 + 1;
LL dp[maxn], sum[maxn];
LL ff[maxn], sf[maxn];
LL g(LL n){
    return (n + 1) * n / 2 % mod;
}
LL f(LL n){
    n = n * (n + 1) % mod * (n + 2) % mod;
    while(n % 6) n += mod;
    return n / 6 % mod;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    dp[0] = sum[0] = dp[1] = 1;
    sum[1] = 2;
    for(int i = 2; i <= n; i += 1){
        dp[i] = (g(sum[i - 1]) - g(sum[i - 2]) + mod) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        //cout << i << " " << dp[i] << "\n";
    }
    LL ans = 0;
    ans += (f(sum[n] + mod - 1) - f(sum[n - 1] + mod - 1) + mod) * 2;
    for(int i = 0; i < n; i += 1)
        ans += (g(sum[n - i] + mod - 1) - g(sum[n - i - 1] + mod - 1) + mod) * 2;
    for(int i = 1; i <= n; i += 1){
        ff[i] = (g(sum[i] + mod - 1) - g(sum[i - 1] + mod - 1) + mod) % mod;
        sf[i] = (ff[i] + sf[i - 1]) % mod;
    }
    for(int i = 1; i <= n; i += 1) ans += ff[i] * sf[n - i - 1] % mod;
    ans += 1;
    cout << ans % mod << "\n";
    return 0;
}