#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //c[1] c[2] ... c[k-1] c[k]
    //(k - i + 1) ^ ... /c[i]!
    int n, k;
    cin >> n >> k;
    vector<LL> dp(n), f(n), g(n);
    for (int i = 0; i < n; i += 1) g[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
    dp[0] = 1;
    for (int x = 1; x <= k; x += 1)
    for (int i = n - 1; i >= 0; i -= 1)
        for (int j = 0; j < i; j += 1)
            dp[i] = (dp[i] + dp[j] * g[i - j] % mod * power(k - x + 1, (i - j) * j + (i - j) * (i - j - 1) / 2)) % mod;
    cout << dp[n - 1] * f[n - 1] % mod;
    return 0;
}