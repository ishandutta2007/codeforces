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

using mod = modint<int(1e9+7)>;

const int N = 1<<18;
vector<tuple<ll, mod, mod>> v[2*N];
int lv[2*N], rv[2*N];

mod get(int i, ll x) {
    tuple<ll, mod, mod> y = {x, 0, 0};
    int j = lower_bound(all(v[i]), y)-v[i].begin();
    debug(v[i]);
    debug(i, x, j);
    return get<1>(v[i].back()) - 2*(j == 0 ? 0 : get<1>(v[i][j-1]))
      - x*(get<2>(v[i].back()) - 2*(j == 0 ? 0 : get<2>(v[i][j-1])));
}

mod query(int l, int r, ll x, int i) {
    if (l <= lv[i] && r >= rv[i]) {
        mod z = get(i, x);
        debug(i, lv[i], rv[i], x, z);
        return z;
    }
    if (r < lv[i] || l > rv[i])
        return 0;
    return query(l, r, x, 2*i) + query(l, r, x, 2*i+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
        b[i] += b[i-1];
    for (int i = 0; i < N; i++)
        lv[i+N] = rv[i+N] = i;
    for (int i = 0; i < n-1; i++)
        v[N+i].pb({b[i], mod(b[i])*(a[i+1]-a[i]), a[i+1]-a[i]});
    for (int i = N-1; i > 0; i--) {
        lv[i] = lv[2*i], rv[i] = rv[2*i+1];
        merge(all(v[2*i]), all(v[2*i+1]), back_inserter(v[i]));
    }
    for (int i = 0; i < 2*N; i++)
        for (int j = 1; j < v[i].size(); j++) {
            get<1>(v[i][j]) += get<1>(v[i][j-1]);
            get<2>(v[i][j]) += get<2>(v[i][j-1]);
        }
    debug(a);
    debug(b);
    while (q--) {
        ll l, r; cin >> l >> r; l--, r--;
        cout << query(l, r-1, l == 0 ? 0 : b[l-1], 1) << "\n";
    }
}