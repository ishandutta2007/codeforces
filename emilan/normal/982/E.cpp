#include <bits/stdc++.h>

using namespace std;

using ll = long long;

array<ll, 3> egcd(ll a, ll b) {
    ll x0 = 1, x1 = 0, y0 = 0, y1 = 1;

    while (b) {
        ll d = a / b;
        tie(a, b) = make_pair(b, a - d * b);
        tie(x0, x1) = make_pair(x1, x0 - d * x1);
        tie(y0, y1) = make_pair(y1, y0 - d * y1);
    }

    return {a, x0, y0};
}

pair<ll, ll> crt(ll r0, ll r1, ll m0, ll m1) {
    auto [g, x, _] = egcd(m0, m1);
    if ((r1 - r0) % g) return {0, 0};

    ll u1 = m1 / g;
    ll r = r0 + m0 * (x * (r1 - r0) / g % u1);
    ll m = m0 * u1;
    if (r < 0) r += m;

    return {r, m};
}

int main() {
    ll n, m, x, y, vx, vy;
    cin >> n >> m >> x >> y >> vx >> vy;

    if (vx == 0) {
        if (x != 0 && x != n) return cout << -1, 0;

        if (x == 0) cout << 0;
        else cout << n;

        cout << ' ';

        if (vy == -1) cout << 0;
        else cout << m;
    } else if (vy == 0) {
        if (y != 0 && y != m) return cout << -1, 0;

        if (vx == -1) cout << 0;
        else cout << n;

        cout << ' ';

        if (y == 0) cout << 0;
        else cout << m;
    } else {
        x = vx == 1 ? x : 2 * n - x;
        y = vy == 1 ? y : 2 * m - y;

        auto [r, mod] = crt((2 * n - x) % n, (2 * m - y) % m, n, m);

        if (mod == 0) cout << -1;
        else {
            x = (x + r) % (2 * n);
            y = (y + r) % (2 * m);

            cout << x << ' ' << y;
        }
    }
}