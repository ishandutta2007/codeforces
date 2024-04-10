#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 200000;
LL f[maxn + 1], g[maxn + 1];
LL C(int m, int n){
    return f[m] * g[n] % mod * g[m - n] % mod;
}
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; i += 1) f[i] = i ? f[i - 1] * i % mod : 1;
    for(int i = 1; i <= n; i += 1) g[i] = i == 1 ? 1 : (mod - mod / i) * g[mod % i] % mod;
    for(int i = 0; i <= n; i += 1) g[i] = i ? g[i - 1] * g[i] % mod : 1;
    if(k == 0) cout << f[n];
    else if(k >= n) cout << 0;
    else{
        LL m = n - k;
        LL ans = 0;
        for(int i = 0; i < m; i += 1)
            if(i & 1) ans -= C(m, i) * power(m - i, n) % mod;
            else ans += C(m, i) * power(m - i, n) % mod;
        ans = (ans % mod + mod) % mod;
        cout << ans * C(n, m) * 2 % mod;
    }
    return 0;
}