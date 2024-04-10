#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

pii mod_inv(int x, int m) {
    int y = m, xs = 1, ys = 0;
    while (y > 0) {
        int q = x / y, tmp;
        tmp = x - q * y, x = y, y = tmp;
        tmp = xs - q * ys, xs = ys, ys = tmp;
    }
    return {x, xs < 0 ? xs + m : xs};
}

pii crt(int r0, int m0, int r1, int m1) {
    if (m0 < m1) swap(r0, r1), swap(m0, m1);
    auto [g, s] = mod_inv(m0, m1);
    if ((r1 - r0) % g != 0) return {0, 0};
    int u1 = m1 / g;
    int r = r0 + m0 * ((r1 - r0) / g % u1 * s % u1);
    int m = m0 * u1;
    return {r < 0 ? r + m : r, m};
}

pii f(int n, int lb, int ub, int p, int e) {
    vector<int> p_pwr(e + 1);
    p_pwr[0] = 1;
    for (int i = 1; i <= e; i++) {
        p_pwr[i] = p_pwr[i - 1] * p;
    }
    int m = p_pwr[e];

    vector<int> pwr(n + 1);
    vector<ll> fact(n + 1);
    vector<ll> finv(n + 1);
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= n; i++) {
        pwr[i] = pwr[i - 1];
        int x = i;
        for (; x % p == 0; x /= p) pwr[i]++;
        fact[i] = fact[i - 1] * x % m;
        finv[i] = mod_inv(int(fact[i]), m).second;
    }

    auto C = [&](int x, int y) -> ll {
        if (0 <= y && y <= x) {
            if (int pwr_ = pwr[x] - pwr[x - y] - pwr[y]; pwr_ < e) {
                return fact[x] * finv[x - y] % m * finv[y] % m
                    * p_pwr[pwr_] % m;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    };

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        int lb_ = lb + ((n - i + lb) & 1);
        int ub_ = ub - ((n - i + ub) & 1);
        ll x1 = (C(n - i, (n - i + lb_) / 2)
            + m - C(n - i, (n - i + ub_) / 2 + 1)) % m;
        ll x2 = (C(n, i) * x1) % m;
        ans = (ans + x2) % m;
    }
    return {int(ans), m};
}

void solve() {
    int n, m0, lb, ub;
    cin >> n >> m0 >> lb >> ub;

    int r = 0, m = 1;
    int x = m0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int e = 0;
            for (; x % i == 0; x /= i) e++;
            auto [r_, m_] = f(n, lb, ub, i, e);
            tie(r, m) = crt(r, m, r_, m_);
        }
    }
    if (x > 1) {
        auto [r_, m_] = f(n, lb, ub, x, 1);
        tie(r, m) = crt(r, m, r_, m_);
    }

    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}