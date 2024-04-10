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

using mod = modint<998244353>;

mod cross_subsets(ll n, ll m) {
    return mod(2).pow(n+m) - mod(2).pow(n) - mod(2).pow(m) + 1;
}

// a with a or b with b is automatically fine, a with b needs to be <= x, need at least 1 from each group
mod solve_bipartite(vector<ll>& a, vector<ll>& b, ll x, int k) {
    debug(a, b, x, k);
    if (a.size() == 0 || b.size() == 0)
        return 0;
    if (k == -1)
        return (mod(2).pow(a.size())-1) * (mod(2).pow(b.size())-1);
    vector<ll> c[4];
    for (ll y : a)
        c[((y>>k)&1)].pb(y&~(1ll<<k));
    for (ll y : b)
        c[2|((y>>k)&1)].pb(y&~(1ll<<k));
    if (x&(1ll<<k)) {
        mod p = solve_bipartite(c[0], c[3], x&~(1ll<<k), k-1);
        mod q = solve_bipartite(c[1], c[2], x&~(1ll<<k), k-1);
        return p*q
             + (mod(2).pow(c[0].size())-1) * (mod(2).pow(c[2].size())-1)
             + (mod(2).pow(c[1].size())-1) * (mod(2).pow(c[3].size())-1)
             + p + q
             + p * ((mod(2).pow(c[1].size())-1) + (mod(2).pow(c[2].size())-1))
             + q * ((mod(2).pow(c[0].size())-1) + (mod(2).pow(c[3].size())-1))
        ;
    } else {
        mod p = solve_bipartite(c[0], c[2], x, k-1);
        mod q = solve_bipartite(c[1], c[3], x, k-1);
        return p+q;
    }
}

mod solve_general(vector<ll>& a, ll x, int k) {
    debug(a, x, k);
    if (a.size() == 0) return 0;
    if (k == -1) return mod(2).pow(a.size())-1;
    vector<ll> c[2];
    for (ll y : a)
        c[(y>>k)&1].pb(y&~(1ll<<k));
    if (x&(1ll<<k)) {
        return solve_bipartite(c[0], c[1], x&~(1ll<<k), k-1) + mod(2).pow(c[0].size())-1 + mod(2).pow(c[1].size())-1;
    } else {
        return solve_general(c[0], x, k-1) + solve_general(c[1], x, k-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve_general(a, x, 30) << "\n";
}