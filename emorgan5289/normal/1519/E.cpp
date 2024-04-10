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

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&0-(v<0)); }
    
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

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
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
    modint pow(const ll k) const { return _pow(v, k); }
    modint inv() const { return _pow(v, M-2); }
};

using mod7 = modint<int(1e9+7)>;
using mod9 = modint<int(1e9+9)>;
const int N = 5e5+5;
map<pair<mod7, mod9>, int> m;
vector<array<int, 2>> adj[N];
vector<int> grp[N];
int vv[N], ve[N];

void dfs(int i) {
    vv[i] = 1;
    for (auto [j, e] : adj[i]) {
        if (ve[e]) continue;
        ve[e] = 1;
        if (vv[j]) {
            grp[j].pb(e);
        } else {
            dfs(j);
            if (grp[j].size()&1)
                grp[j].pb(e);
            else
                grp[i].pb(e);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int t = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        mod7 x7 = (mod7(a)/b+1)/(mod7(c)/d), y7 = (mod7(a)/b)/(mod7(c)/d+1);
        mod9 x9 = (mod9(a)/b+1)/(mod9(c)/d), y9 = (mod9(a)/b)/(mod9(c)/d+1);
        pair<mod7, mod9> x = {x7, x9}, y = {y7, y9};
        if (!m.count(x)) m[x] = t++;
        if (!m.count(y)) m[y] = t++;
        adj[m[x]].pb({m[y], i});
        adj[m[y]].pb({m[x], i});
    }
    for (int i = 0; i < t; i++)
        if (!vv[i]) dfs(i);
    vector<array<int, 2>> ans;
    for (int i = 0; i < t; i++)
        for (int j = 0; j+1 < grp[i].size(); j += 2)
            ans.pb({grp[i][j], grp[i][j+1]});
    cout << ans.size() << "\n";
    for (auto& [i, j] : ans)
        cout << i+1 << " " << j+1 << "\n";
}