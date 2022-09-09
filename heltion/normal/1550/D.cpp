#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, l, r;
        cin >> n >> l >> r;
        vector<LL> f(n + 1), g(n + 1);
        for (int i = 0; i <= n; i += 1)
            f[i] = i ? f[i - 1] * i % mod : 1;
        for (int i = 1; i <= n; i += 1)
            g[i] = i > 1 ? (mod - mod / i) * g[mod % i] % mod : 1;
        for (int i = 0; i <= n; i += 1)
            g[i] = i ? g[i - 1] * g[i] % mod : 1;
        auto C = [&](int m, int n) {
            return f[m] * g[n] % mod * g[m - n] % mod;
        };
        LL m = min(r - 1, n - l);
        auto G = [&](int k) {
            LL ans = max(m - n, 0LL) * C(n, k) % mod;
            for (LL i = max(m - n, 0LL) + 1; i <= m; i += 1) {
                LL add = max(l + i - 1, 0LL), sub = max(n - (r - i), 0LL);
                //cout << i << " " << k << " " << add << " " << sub << "\n";
                if (add > k or sub > n - k) continue;
                (ans += C(n - add - sub, k - add)) %= mod;
            }
            return ans;
        };
        if (n % 2 == 0) cout << G(n / 2) << "\n";
        else cout << (G(n / 2) + G((n + 1) / 2)) % mod << "\n";
    }
    return 0;
}