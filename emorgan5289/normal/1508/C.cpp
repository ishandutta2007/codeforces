#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9+10;
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

struct dsu {

    vector<ll> p, sz;

    dsu(ll n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    ll rep(ll x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(ll a, ll b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(ll a, ll b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    ll size(ll x) {
        return sz[rep(x)];
    }
};

const ll N = 2e5+5;
vector<array<ll, 2>> adj[N];
set<ll> uadj[N];
set<ll> uv;
vector<ll> grp[N];
vector<array<ll, 3>> e, re;
vector<array<ll, 2>> e0;
// multiset<array<ll, 3>> re;
dsu u(N), uu(N);

void bfs(ll x) {
    uv.erase(uv.find(x));
    queue<ll> q({x});
    while (!q.empty()) {
        x = q.front(); q.pop();
        vector<ll> vis;
        for (auto& i : uv)
            if (!uadj[x].count(i))
                vis.pb(i);
        for (ll i : vis)
            q.push(i), u.unite(x, i), uv.erase(uv.find(i));
    }
}

ll check(int x, int y, int n, ll xr) {
    dsu u2(n);
    debug(re);
    for (auto& [i, j] : e0) {
        if (i == x && j == y) continue;
        if (i == y && j == x) continue;
        debug(i, j);
        u2.unite(i, j);
    }
    ll ans = 0;
    for (auto& [w, i, j] : re) {
        if (w >= xr) {
            if (!u2.query(x, y))
                u2.unite(x, y), ans += xr;
        }
        if (!u2.query(i, j))
            u2.unite(i, j), ans += w;
    }
    debug(x, y, xr, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    ll xr = 0;
    for (ll i = 0; i < m; i++) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        adj[x].pb({w, y}), adj[y].pb({w, x});
        uadj[x].insert(y);
        uadj[y].insert(x);
        xr ^= w;
    }
    for (ll i = 0; i < n; i++)
        uv.insert(i);
    for (ll i = 0; i < n; i++)
        if (uv.count(i)) bfs(i);
    for (ll i = 0; i < n; i++)
        grp[u.rep(i)].pb(i);
    for (ll i = 0; i < n; i++)
        debug(grp[i]);
    for (ll i = 0; i < n; i++)
        for (auto& [w, j] : adj[i])
            e.pb({w, i, j});
    sort(all(e));
    bool cyc = 0;
    ll ans = 0;
    if (n*(n-1)/2-m >= n) cyc = 1;
    else {
        debug("small");
        vector<vector<ll>> madj(n, vector<ll>(n, 1));
        for (ll i = 0; i < n; i++)
            for (auto& [w, j] : adj[i])
                madj[i][j] = 0;
        dsu u2(n);
        for (ll i = 0; i < n; i++)
            for (ll j = i+1; j < n; j++)
                if (madj[i][j]) {
                    if (u2.query(i, j))
                        cyc = 1;
                    u2.unite(i, j);
                }
        if (!cyc) {
            ans = inf_ll;
            dsu u3(n);
            for (auto& [w, i, j] : e) {
                if (!u3.query(i, j)) re.pb({w, i, j});
                u3.unite(i, j);
            }
            for (ll i = 0; i < n; i++)
                for (ll j = i+1; j < n; j++)
                    if (madj[i][j]) e0.pb({i, j});
            for (ll i = 0; i < n; i++)
                for (ll j = i+1; j < n; j++)
                    if (madj[i][j]) {
                        cmin(ans, check(i, j, n, xr));
                    }
            cout << ans << "\n";
        }
    }
    if (cyc) {
        for (auto& [w, i, j] : e)
            if (!u.query(i, j)) {
                u.unite(i, j);
                ans += w;
            }
        cout << ans << "\n";
    }
}