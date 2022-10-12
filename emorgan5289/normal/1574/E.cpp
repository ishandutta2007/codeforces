#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

template<ll M>
struct modint {

    static ll _reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = _reduce(n*n))
            if (k&1) r = _reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = _reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = _reduce(v*_pow(n.v, M-2)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<998244353>;
const int N = 2e6+5;
ll a[2][N], b[2][N], z[2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    map<array<ll, 2>, ll> s;
    ll ca = 0, cb = 0, sa = 0, sb = 0;
    for (int i = 0; i < k; i++) {
        ll x, y, t; cin >> x >> y >> t; x--, y--;
        if (s.count({x, y})) {
            if (a[0][x] && a[1][x]) ca--;
            if (b[0][y] && b[1][y]) cb--;
            if (a[0][x] || a[1][x]) sa--;
            if (b[0][y] || b[1][y]) sb--;
            a[(s[{x, y}]+y)%2][x]--;
            b[(s[{x, y}]+x)%2][y]--;
            if (a[0][x] && a[1][x]) ca++;
            if (b[0][y] && b[1][y]) cb++;
            if (a[0][x] || a[1][x]) sa++;
            if (b[0][y] || b[1][y]) sb++;
            z[(x+y+s[{x, y}])%2]--;
            s.erase(s.find({x, y}));
        }
        if (t == 0 || t == 1) {
            if (a[0][x] && a[1][x]) ca--;
            if (b[0][y] && b[1][y]) cb--;
            if (a[0][x] || a[1][x]) sa--;
            if (b[0][y] || b[1][y]) sb--;
            a[(t+y)%2][x]++;
            b[(t+x)%2][y]++;
            if (a[0][x] && a[1][x]) ca++;
            if (b[0][y] && b[1][y]) cb++;
            if (a[0][x] || a[1][x]) sa++;
            if (b[0][y] || b[1][y]) sb++;
            z[(x+y+t)%2]++;
            s[{x, y}] = t;
        }
        if (ca && cb) {
            cout << "0\n";
        } else if (ca) {
            cout << mod(2).pow(m-sb) << "\n";
        } else if (cb) {
            cout << mod(2).pow(n-sa) << "\n";
        } else {
            mod ans = 0;
            ans += mod(2).pow(m-sb);
            ans += mod(2).pow(n-sa);
            if (s.empty()) {
                ans -= 2;
            } else if (z[0] && z[1]) {

            } else {
                ans -= 1;
            }
            cout << ans << "\n";
        }
    }
}