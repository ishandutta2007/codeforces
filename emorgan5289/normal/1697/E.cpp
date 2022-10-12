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

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

template<ll M>
struct modint {

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }

    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
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
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<array<ll, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];

    auto d = [&](int i, int j) {
        return abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
    };

    dsu u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            bool ok = 1;
            for (int k = 0; k < n; k++)
                if (k != i && k != j)
                    if (d(i, k) <= d(i, j) || d(j, k) <= d(i, j))
                        if (d(i, k) != d(i, j) || d(j, k) != d(i, j))
                            ok = 0;
            if (ok) {
                debug(i, j);
                u.unite(i, j);
            }
        }
    }

    vector<ll> c;
    for (int i = 0; i < n; i++)
        if (u.rep(i) == i) {
            bool ok = 1;
            for (int j = 0; j < n; j++)
                if (j != i && u.rep(j) == i) {
                    for (int k = 0; k < n; k++) {
                        if (u.rep(k) != i && d(i, j) >= d(i, k))
                            ok = 0;
                        if (u.rep(k) != i && d(i, j) >= d(j, k))
                            ok = 0;
                    }
                    break;
                }
            if (ok) c.pb(u.size(i));
            else {
                for (int j = 0; j < u.size(i); j++)
                    c.pb(1);
            }
        }
    debug(c);

    vector<mod> dp0(n+1), dp1(n+1);
    dp0[0] = 1;
    for (ll x : c) {
        fill(all(dp1), 0);
        for (int i = n-1; i >= 0; i--) {
            if (x > 1 && i+x <= n)
                dp1[i+x] += dp0[i];
            dp1[i+1] += dp0[i];
        }
        swap(dp0, dp1);
    }
    debug(dp0);

    mod ans = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        r *= n+1-i;
        debug(i, r, dp0[i]);
        ans += r*dp0[i];
    }
    cout << ans << "\n";
}