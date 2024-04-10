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

template<int N, typename T = int>
struct segtree {

    constexpr static T max_T = numeric_limits<T>::max();
    constexpr static T min_T = numeric_limits<T>::min();
    constexpr static int H = int(ceil(log2(N))), _N = 1<<H;

    struct node { T s, l, r; } t[2*_N];
    node merge(node x, node y) {
        return {x.s+y.s, std::min(x.l, y.l), std::max(x.r, y.r)};
    }

    T u[2*_N]; bool f[2*_N]; int a[2*_N], b[2*_N];
    segtree() {
        fill(t, t+2*_N, node({0, 0, 0}));
        fill(f, f+2*_N, 0), fill(u, u+2*_N, 0);
        iota(a+_N, a+2*_N, 0), iota(b+_N, b+2*_N, 0);
        for (int i = _N-1; i > 0; i--)
            a[i] = a[2*i], b[i] = b[2*i+1];
    }

    void apply(int i, T x, bool ins) {
        if (ins) u[i] = x, f[i] = 1;
        else u[i] += x;
    }

    void push(int i) {
        if (!f[i] && !u[i]) return;
        if (f[i]) t[i] = {0, 0, 0};
        t[i].s += u[i]*(b[i]-a[i]+1), t[i].l += u[i], t[i].r += u[i];
        if (i < _N) apply(2*i, u[i], f[i]), apply(2*i+1, u[i], f[i]);
        u[i] = f[i] = 0;
    }

    void _upd(int l, int r, T x, bool ins, int i = 1) {
        if (l <= a[i] && r >= b[i]) apply(i, x, ins);
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i]) return;
        _upd(l, r, x, ins, 2*i), _upd(l, r, x, ins, 2*i+1);
        t[i] = merge(t[2*i], t[2*i+1]);
    }

    node _qry(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i]) return t[i];
        if (l > b[i] || r < a[i]) return {0, max_T, min_T};
        return merge(_qry(l, r, 2*i), _qry(l, r, 2*i+1));
    }

    T get(int i) {
        for (int x = H; x >= 0; x--) push((_N+i)>>x);
        return t[_N+i].s;
    }

    void set(int l, int r, T x) { _upd(l, r, x, 1); }
    void add(int l, int r, T x) { _upd(l, r, x, 0); }
    void set(int i, T x) { set(i, i, x); }
    void add(int i, T x) { add(i, i, x); }
    T sum(int l, int r) { return _qry(l, r).s; }
    T min(int l, int r) { return _qry(l, r).l; }
    T max(int l, int r) { return _qry(l, r).r; }
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
        for (int j = 0; (1<<j) <= k; j++)
            if (k&(1<<j)) i = p[i][j];
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

const int N = 1e5+5;
ll n, l;
ll c[N], vin[N], vout[N], t = 0;
segtree<N, ll> s;
vector<array<ll, 2>> adj[N];
ll dp[N];

void dfs1(int i, int k, ll d) {
    vin[i] = t++;
    s.set(vin[i], d);
    for (auto& [w, j] : adj[i])
        if (j != k) dfs1(j, i, d+w);
    vout[i] = t-1;
}

void dfs2(int i, int k) {
    c[i] = s.max(0, n-1);
    for (auto& [w, j] : adj[i]) {
        if (j == k) continue;
        s.add(0, n-1, w);
        s.add(vin[j], vout[j], -2*w);
        dfs2(j, i);
        s.add(0, n-1, -w);
        s.add(vin[j], vout[j], 2*w);
    }
}

void dfs3(int i, int k) {
    c[i] += c[k];
    for (auto& [w, j] : adj[i])
        if (j != k) dfs3(j, i);
    // sort(all(adj[i]), [&](auto x, auto y){
    //     return c[x[1]] < c[y[1]];
    // });
}

void dfs4(int i, int k) {
    for (auto& [w, j] : adj[i])
        if (j != k) dfs4(j, i), dp[i] += dp[j];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<vector<int>> uw_adj(n);
    for (int i = 0; i < n-1; i++) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        adj[x].pb({w, y}), adj[y].pb({w, x});
        uw_adj[x].pb(y), uw_adj[y].pb(x);
    }
    dfs1(0, 0, 0);
    dfs2(0, 0);
    debug(vector(c, c+n));
    int r = min_element(c, c+n)-c;
    // dfs3(r, r);
    debug(vector(c, c+n));
    ancestor anc(uw_adj, r);
    ll q; cin >> q;
    while (q--) {
        cin >> l;
        fill(dp, dp+n, 0);
        for (int i = 0; i < n; i++) {
            int x = i;
            for (int j = anc.p[i].size()-1; j >= 0; j--) {
                // debug(c[x]-c[anc.p[x][j]], anc.p[x][j]);
                if (c[i]-c[anc.p[x][j]] <= l)
                    x = anc.p[x][j];
            }
            // debug(i, x, anc.p[x][0]);
            dp[i]++;
            if (x != r) dp[anc.p[x][0]]--;
        }
        // debug(vector(dp, dp+n));
        dfs4(r, r);
        // debug(vector(dp, dp+n));
        cout << (*max_element(dp, dp+n)) << "\n";
    }
}