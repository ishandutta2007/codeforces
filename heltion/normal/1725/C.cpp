#include <bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vector<LL> d(n + 1);
    set<LL> s;
    int k = 0;
    for (int i = 1; i <= n; i += 1) {
        cin >> d[i];
        d[i] += d[i - 1];
        s.insert(d[i]);
    }
    if (d[n] % 2 == 0)
        for (int i = 1; i <= n; i += 1)
            k += s.count(d[i] - d[n] / 2);
    vector<LL> f(max(n, m) + 1), g(max(n, m) + 1);
    for (int i = 0; i <= max(n, m); i += 1)
        g[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
    LL ans = 0;
    for (int i = 0; i <= k and i <= m; i += 1) {
        LL pans = f[k] * g[i] % mod * g[k - i] % mod;
        pans = pans * f[m] % mod * g[i] % mod * g[m - i] % mod;
        pans = pans * f[i] % mod;
        pans = pans * power((LL)(m - i) * (m - i - 1) % mod, k - i) % mod;
        pans = pans * power(m - i, n - 2 * k) % mod;
        ans = (ans + pans) % mod;
        //cout << i << " " << pans << "\n";
    }
    cout << ans;
}