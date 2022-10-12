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

const int N = 405;
vector<int> adj[N];
int sp[N][N], c_sp[N][N], step[N][N];
vector<array<int, 2>> grp[N];
bool v[N];
int n, m;

mod solve(int x, int y) {
    if (c_sp[x][y] == 2) return 0;
    fill(v, v+n, 0);
    for (int i = x; i != y; i = step[i][y])
        v[i] = 1;
    v[y] = 1;
    mod ans = 1;
    for (int i = 0; i < n; i++)
        if (!v[i]) {
            mod deg = 0;
            for (int j : adj[i])
                if (sp[i][y] == 1+sp[j][y] && sp[i][x] == 1+sp[j][x])
                    deg++;
            ans *= deg;
        }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++) {
        fill(sp[i], sp[i]+n, inf);
        sp[i][i] = 0;
        queue<int> q({i});
        while (!q.empty()) {
            int j = q.front(); q.pop();
            if (sp[i][j] > 0) grp[sp[i][j]].pb({i, j});
            for (int k : adj[j])
                if (sp[i][k] == inf)
                    sp[i][k] = sp[i][j]+1, q.push(k);
        }
        c_sp[i][i] = 1;
    }
    for (int i = 1; i < n; i++)
        for (auto& [x, y] : grp[i])
            for (int k : adj[x])
                if (sp[k][y]+1 == sp[x][y]) {
                    step[x][y] = k;
                    c_sp[x][y] = min(2, c_sp[x][y]+c_sp[k][y]);
                }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << solve(i, j) << " \n"[j == n-1];
}