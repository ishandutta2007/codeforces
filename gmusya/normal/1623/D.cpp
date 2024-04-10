#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll BinPow(ll a, ll p) {
    if (!p) {
        return 1;
    }
    if (p & 1) {
        return BinPow(a, p - 1) * a % MOD;
    } else {
        ll x = BinPow(a, p / 2);
        return x * x % MOD;
    }
}

ll Inv(ll x) {
    return BinPow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _;
    cin >> _;
    while (_--) {
        ll n, m;
        ll x, y;
        ll r, c;
        ll p;
        cin >> n >> m >> x >> y >> r >> c >> p;
        p = (100 - p) * Inv(100) % MOD;
        ll a = 0, b = 1;
        ll dx = -1, dy = -1;
        for (ll i = 0; i < 4 * (n - 1) * (m - 1); ++i) {
            if ((x == n && dx == 1) || (x == 1 && dx == -1)) {
                dx *= -1;
            }
            if ((y == m && dy == 1) || (y == 1 && dy == -1)) {
                dy *= -1;
            }
            x += dx;
            y += dy;
            a += 1;
            if (x == r || y == c) {
                a *= p;
                b *= p;
            }
            a %= MOD;
            b %= MOD;
        }
        cout << (a * Inv(1 - b + MOD) % MOD + MOD) % MOD << "\n";
    }
    return 0;
}