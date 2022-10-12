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

// N vertices, flow is measured with type T
template<int N, typename T>
struct dinic {

    const bool SCALING = true;
    const T inf_T = numeric_limits<T>::max();

    struct flow_edge { int v, u; T f, w; };
    vector<flow_edge> adj[N];
    int l[N], p[N], s, t; T k;

    // add an edge from i to j with capacity w
    void edge(int i, int j, T w, bool directed = true) {
        adj[i].push_back({j, int(adj[j].size()), 0, w});
        adj[j].push_back({i, int(adj[i].size())-1, 0, directed ? 0 : w});
    }

    bool bfs() {
        queue<int> q({s});
        fill(l, l+N, -1), l[s] = 0;
        while (!q.empty() && l[t] == -1) {
            int v = q.front(); q.pop();
            for (auto& e : adj[v])
                if (l[e.v] == -1 && e.f < e.w && (!SCALING || e.w - e.f >= k))
                    q.push(e.v), l[e.v] = l[v] + 1;
        }
        return l[t] != -1;
    }

    T dfs(int v, T f) {
        if (v == t || !f)
            return f;
        for (; p[v] < adj[v].size(); p[v]++) {
            auto& e = adj[v][p[v]];
            if (l[e.v] != l[v] + 1)
                continue;
            if (T x = dfs(e.v, min(f, e.w - e.f))) {
                e.f += x, adj[e.v][e.u].f -= x;
                return x;
            }
        }
        return 0;
    }

    // compute the maximum flow from s to t, one-time use
    // Dinic's algorithm, runs in O(V^2E) or O(VElogU)
    T solve(int _s, int _t) {
        s = _s, t = _t; T out = 0;
        for (k = SCALING ? 1<<30 : 1; k > 0; k /= 2)
            while (bfs()) {
                fill(p, p+N, 0);
                while (T x = dfs(s, inf_T)) out += x;
            }
        return out;
    }

    // after calling solve(), return a component vector C s.t. C[i] \in {0, 1}
    // and i is reachable from s iff C[i] = 1. any edge from a 1 to a 0 is in the min cut
    vector<bool> cut() {
        vector<bool> out(N, 0); out[s] = 1;
        queue<int> q({s});
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto& e : adj[v])
                if (e.f < e.w && !out[e.v])
                    out[e.v] = 1, q.push(e.v);
        }
        return out;
    }
};

dinic<2005, int> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<vector<ll>> a(2*n, vector<ll>(n));
        for (int i = 0; i < 2*n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j], a[i][j]--;
        debug(a);
        vector<vector<int>> adj(2*n);
        for (int i = 0; i < 2*n; i++)
            for (int j = i+1; j < 2*n; j++) {
                bool ok = 1;
                for (int k = 0; k < n; k++)
                    if (a[i][k] == a[j][k]) {
                        ok = 0; break;
                    }
                if (!ok) adj[i].pb(j), adj[j].pb(i);
            }

        // in subset
        vector<int> v(2*n, -1);

        while (1) {
            bool found = 0;
            for (int i = 0; i < n; i++) {
                vector<int> freq(n);
                for (int j = 0; j < 2*n; j++)
                    if (v[j] == -1) freq[a[j][i]]++;
                int x = -1;
                for (int j = 0; j < n; j++)
                    if (freq[j] == 1) x = j;
                if (x != -1) {
                    for (int j = 0; j < 2*n; j++)
                        if (a[j][i] == x && v[j] == -1) {
                            x = j; break;
                        }
                    found = 1;
                    v[x] = 1;
                    for (int y : adj[x])
                        v[y] = 0;
                    break;
                }
            }
            if (!found) {
                bool has_1 = 0;
                for (int i = 0; i < 2*n; i++)
                    if (v[i] == -1) has_1 = 1;
                if (!has_1) break;
                for (int i = 0; i < 2*n; i++)
                    if (v[i] == -1) {
                        v[i] = 1;
                        for (int j : adj[i]) v[j] = 0;
                        break;
                    }
            }
            debug(v);
        }

        debug(adj);
        debug(v);

        // original ordering
        vector<int> p(2*n);

        // construct p
        vector<int> ptmp;
        int S = 1004, T = 1003;
        for (int i = 0; i < 2005; i++)
            f.adj[i].clear();
        for (int i = 0; i < 2*n; i++) {
            if (v[i]) {
                ptmp.pb(i);
                f.edge(S, i, 1);
                for (int j : adj[i])
                    f.edge(i, j, 1);
            } else {
                f.edge(i, T, 1);
            }
        }
        auto flow = f.solve(S, T);
        assert(flow == n);
        for (int i = 0; i < n; i++) {
            p[i] = ptmp[i];
            for (auto& e : f.adj[p[i]])
                if (e.f > 0) p[n+i] = e.v;
        }
        debug(p);

        dsu u(n);
        vector<int> bad(n);
        for (int i = 0; i < n; i++) {
            vector<int> g(n), ag(n);
            for (int j = 0; j < n; j++)
                ag[a[p[j]][i]] = j;
            for (int j = 0; j < n; j++)
                g[j] = ag[a[p[j+n]][i]];
            for (int j = 0; j < n; j++) {
                vector<int> vis(n, 0);
                vector<int> cyc;
                int x = j;
                for (; !vis[x]; x = g[x])
                    cyc.pb(x), vis[x] = 1;
                if (x == j) {
                    for (int y : cyc) u.unite(y, j);
                } else {
                    bad[j] = 1;
                }
            }
        }
        debug(bad);
        for (int i = 0; i < n; i++)
            bad[u.rep(i)] |= bad[i];
        ll x = 0;
        for (int i = 0; i < n; i++)
            if (u.rep(i) == i && !bad[i]) x++;
        cout << mod(2).pow(x) << "\n";
        for (int i = 0; i < 2*n; i++)
            if (v[i]) cout << i+1 << " ";
        cout << "\n";
    }
}