#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<ll M>
struct modint {

    static ll reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll inv(ll n) {
        ll r = 1;
        for (ll k = M-2; k > 0; k >>= 1, n = reduce(n*n))
            if (k&1) r = reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(reduce(n)) { v += (M&0-(v<0)); }
    
    friend string to_string(const modint& n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint& n) { return o << n.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        if (k < 1) return k == 0 ? 1 : modint(inv(this->v)).pow(-k);
        return k&1 ? *this*(this->pow(k-1)) : (*this**this).pow(k>>1);
    }
};

const int N = 2e5+5, D = 63;
vector<pair<ll, int>> adj[N];
vector<ll> a;
ll v[N], c[N], b[D], f[D], sz;

void ins(ll k) {
    if (k == 0) return;
    for (ll i = 0; i < D; i++) {
        if ((k&1ll<<i) == 0) continue;
        if (!b[i])  {
            sz++, b[i] = k;
            return;
        }
        k ^= b[i];
    }
}

void dfs(int i) {
    v[i] = 1, a.pb(c[i]);
    for (auto& [w, j] : adj[i]) {
        if (v[j]) ins(c[i]^w^c[j]);
        if (!v[j]) c[j] = c[i]^w, dfs(j);
    }
}

using mod = modint<int(1e9+7)>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    while (m--) {
        ll x, y, z; cin >> x >> y >> z; x--, y--;
        adj[x].pb({z, y}), adj[y].pb({z, x});
    }
    mod ans = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i]) continue;
        sz = 0, fill(b, b+D, 0);
        a.clear();
        dfs(i);
        fill(f, f+D, 0);
        for (ll j = 0; j < D; j++)
            for (ll k = 0; k < D; k++)
                if (b[k]&1ll<<j) f[j]++;
        for (ll j = 0; j < D; j++) {
            mod x = 0;
            for (auto& k : a)
                if (k&1ll<<j) x += 1;
            mod path1 = x*mod(a.size()-x);
            mod path0 = mod(a.size())*mod(a.size()-1)/2-path1;
            mod cyc1 = f[j] ? mod(1ll<<(sz-1)) : mod(0);
            mod cyc0 = mod(1ll<<sz)-cyc1;
            // if ((mod(1ll<<j)*(path0*cyc1+path1*cyc0)).v > 0) {
            //     debug(j, 1ll<<j, mod(1ll<<j), path0, path1, cyc0, cyc1);
            //     debug(mod(1ll<<j)*(path0*cyc1+path1*cyc0));
            // }
            ans += mod(1ll<<j)*(path0*cyc1+path1*cyc0);
        }
    }
    cout << ans << "\n";
}