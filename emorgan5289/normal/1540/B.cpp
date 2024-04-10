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

// combined data structure for various ancestor-related queries.

struct ancestor {

    vector<int> vin, vout, d;
    vector<vector<int>> adj, p;
    int n, t = 0, e;

    void dfs(int i, int v) {
        vin[i] = t++;
        p[i][0] = v, d[i] = d[v]+1;
        for (int j = 1; j <= e; j++)
            p[i][j] = p[p[i][j-1]][j-1];
        for (auto& j : adj[i])
            if (j != v) dfs(j, i);
        vout[i] = t-1;
    }

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (adj.empty()) return;
        vin.resize(n), vout.resize(n), d.assign(n, 0);
        e = ceil(log2(n));
        p.assign(n, vector<int>(e+1));
        dfs(root, root);
    }

    // returns true if i is an ancestor of j in O(1) time.
    bool is_ancestor(int i, int j) const {
        return vin[i] <= vin[j] && vout[i] >= vout[j];
    }

    // returns the k'th ancestor of i O(logk) time.
    int ktha(int i, int k) const {
        while (k) {
            int j = k&-k;
            i = p[i][__builtin_ctz(j)];
            k -= j;
        }
        return i;
    }

    // returns the LCA of i and j in O(logn) time.
    int lca(int i, int j) const {
        if (is_ancestor(i, j)) return i;
        if (is_ancestor(j, i)) return j;
        for (int k = e; k >= 0; k--)
            if (!is_ancestor(p[i][k], j))
                i = p[i][k];
        return p[i][0];
    }

    // returns the vertex one step along the path from i to j in O(logn) time.
    int step(int i, int j) const {
        return is_ancestor(i, j) ? ktha(j, d[j]-d[i]-1) : p[i][0];
    }

    // returns the number of edges between i and j in O(logn) time.
    int dist(int i, int j) {
        return d[i]+d[j]-2*d[lca(i, j)];
    }
};

// note, the file lca_old.cpp allows lca queries in O(1) time instead of O(logn) time,
// but has a much higher constant factor and can cause MLE for around 5*10^5 vertices.

using mod = modint<int(1e9+7)>;
// using mod = long double;

vector<vector<int>> adj;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    vector<vector<mod>> dp(n, vector<mod>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = 0;
            else {
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])/2;
            }
            // debug(i, j, dp[i][j]);
        }
    ancestor anc(adj);
    mod ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            // == i or j
            mod pans = ans;
            ans += 1;
            // subtree j
            if (anc.is_ancestor(j, i)) {
                int x = anc.step(j, i);
                ans += n-(anc.vout[x]-anc.vin[x]+1)-1;
            }
            else {
                ans += anc.vout[j]-anc.vin[j];
            }
            // bool ji = anc.is_ancestor(j, i);
            // bool ij = anc.is_ancestor(i, j);
            // int sji = anc.step(j, i);
            // int sij = anc.step(i, j);
            // for (int k = 0; k < n; k++) {
            //     if (k == i || k == j) continue;
            //     if (ji) {
            //         if (!anc.is_ancestor(sji, k) || anc.is_ancestor(i, k)) continue;
            //     } else if (ij) {
            //         if (anc.is_ancestor(j, k) || !anc.is_ancestor(sij, k)) continue;
            //     } else {
            //         if (anc.is_ancestor(j, k) || anc.is_ancestor(i, k)) continue;
            //     }
            //     debug(i, j, k, dp[anc.dist(j, k)][anc.dist(i, k)]);
            //     ans += dp[anc.dist(j, k)][anc.dist(i, k)];
            // }
            debug(i+1, j+1, ans-pans);
        }

    for (int i = 0; i < n; i++) {
        vector<array<int, 2>> v;
        vector<int> sz(n, 0);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            v.pb({j, anc.step(i, j)});
            sz[anc.step(i, j)]++;
        }
        for (auto& [x, xi] : v)
            for (auto& [y, yi] : v) {
                if (xi == yi) continue;
                if (x < y) continue;
                ans += dp[anc.dist(x, i)][anc.dist(y, i)]*(n-sz[xi]-sz[yi]);
            }
    }
    ans /= mod(n);
    cout << ans << "\n";
}