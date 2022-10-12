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
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
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
        if (k < 1) return k == 0 ? modint(1) : modint(inv(this->v)).pow(-k);
        return k&1 ? *this*(this->pow(k-1)) : (*this**this).pow(k>>1);
    }
};

using mod = modint<998244353>;

const int N = 2e5+5;
vector<array<int, 2>> adj[N];
int fm[2][N], f[N], c[20][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb({0, y}), adj[y].pb({1, x});
    }
    fill(fm[0], fm[0]+n, inf);
    fill(fm[1], fm[1]+n, inf);
    fm[0][0] = 0;
    deque<array<int, 2>> q({{0, 0}});
    while (!q.empty()) {
        auto [t, i] = q.front(); q.pop_front();
        for (auto& [w, j] : adj[i]) {
            if (w == t && fm[w][j] > fm[t][i])
                fm[w][j] = fm[t][i], q.push_front({t, j});
            if (w != t && fm[w][j] > fm[t][i]+1)
                fm[w][j] = fm[t][i]+1, q.push_back({w, j});
        }
    }
    for (int i = 0; i < n; i++)
        f[i] = min(fm[0][i], fm[1][i]);
    for (int i = 0; i < 20; i++)
        fill(c[i], c[i]+n, inf);
    c[0][0] = 0;
    q.push_back({0, 0});
    while (!q.empty()) {
        auto [t, i] = q.front(); q.pop_front();
        for (auto& [w, j] : adj[i]) {
            int s = t+f[i]-f[j]+(w == (t+f[i])%2 ? 0 : 1);
            if (s < 20 && c[s][j] == inf)
                c[s][j] = c[t][i]+1, q.push_back({s, j});
        }
    }
    if (f[n-1] > 30)
        cout << mod(2).pow(f[n-1])+c[0][n-1]-1 << "\n";
    else {
        ll ans = inf_ll;
        for (int i = 0; i < 20; i++)
            cmin(ans, (1ll<<(f[n-1]+i))+c[i][n-1]-1);
        cout << mod(ans) << "\n";
    }
}