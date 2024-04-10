#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (a %= mod; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int maxn = 2000000;
    vector<LL> f(maxn + 1), g(maxn + 1);
    for (int i = 0; i <= maxn; i += 1) g[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
    int t;
    LL inv2 = (mod + 1) / 2;
    auto C = [&](int n, int m) {
        if (n < 0 or m < 0) return 0LL;
        return f[n + m] * g[n] % mod * g[m] % mod;
    };
    for (cin >> t; t; t -= 1){
        LL n, m, k;
        cin >> n >> m >> k;
        m = n - m;
        if (m == 0) cout << n * k % mod << "\n";
        else {
            LL ans = 0;
            for (int i = 1; i <= n; i += 1) {
                LL pans = C(n - m - i, m - 1)  % mod * i % mod * power(inv2, n - i) % mod;
                ans = (ans + pans) % mod;
            }
            cout << ans * k % mod << "\n";
        }
    }
}