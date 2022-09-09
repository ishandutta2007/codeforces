#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<LL> f(3 * n + 10), g(3 * n + 10);
    for (int i = 0; i < 3 * n + 10; i += 1) g[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
    vector<LL> ans(3 * n + 1);
    auto C = [&](int m, int n) {
        if (n > m) return 0LL;
        return f[m] * g[m - n] % mod * g[n] % mod;
    };
    LL inv3 = power(3, mod - 2);
    vector<LL> p(3, n);
    for (int i = 1; i <= 3 * n; i += 1) {
        vector<LL> q = {p[1], p[2], 0};
        q[2] = (C(3 * n + 1, i + 1) + 2 * mod - p[2] * 2 + mod - p[1]) % mod * inv3 % mod;
        (q[1] += q[2]) %= mod;
        (q[0] += q[1]) %= mod;
        p.swap(q);
        ans[i] = p[0];
    }
    for (; q; q -= 1) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}