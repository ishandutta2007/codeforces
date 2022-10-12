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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// combined data structure for various ancestor-related queries.

struct ancestor {

    vector<ll> vin, vout, d;
    vector<vector<ll>> adj, p;
    ll n, t = 0, e;

    void dfs(ll i, ll v) {
        vin[i] = t++;
        p[i][0] = v, d[i] = d[v]+1;
        for (ll j = 1; j <= e; j++)
            p[i][j] = p[p[i][j-1]][j-1];
        for (auto& j : adj[i])
            if (j != v) dfs(j, i);
        vout[i] = t-1;
    }

    ancestor() {}

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<ll>> _adj, ll root) : adj(_adj), n(_adj.size()) {
        vin.resize(n), vout.resize(n), d.assign(n, 0);
        e = ceil(log2(n));
        p.assign(n, vector<ll>(e+1));
        dfs(root, root);
    }

    // returns true if i is an ancestor of j in O(1) time.
    bool is_ancestor(ll i, ll j) const {
        return vin[i] <= vin[j] && vout[i] >= vout[j];
    }

    // returns the k'th ancestor of i O(logk) time.
    ll ktha(ll i, ll k) const {
        for (ll j = 0; (1<<j) <= k; j++)
            if (k&(1<<j)) i = p[i][j];
        return i;
    }

    // returns the LCA of i and j in O(logn) time.
    ll lca(ll i, ll j) const {
        if (is_ancestor(i, j)) return i;
        if (is_ancestor(j, i)) return j;
        for (ll k = e; k >= 0; k--)
            if (!is_ancestor(p[i][k], j))
                i = p[i][k];
        return p[i][0];
    }

    // returns the vertex one step along the path from i to j in O(logn) time.
    ll step(ll i, ll j) const {
        return is_ancestor(i, j) ? ktha(j, d[j]-d[i]-1) : p[i][0];
    }

    // returns the number of edges between i and j in O(logn) time.
    ll dist(ll i, ll j) {
        return d[i]+d[j]-2*d[lca(i, j)];
    }
};

struct dsu {

    vector<ll> p, sz;

    dsu(ll n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    ll rep(ll x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    void unite(ll a, ll b) {
        a = rep(a), b = rep(b);
        if (a != b) p[b] = a, sz[a] += sz[b];
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

// note, the file lca_old.cpp allows lca queries in O(1) time instead of O(logn) time,
// but has a much higher constant factor and can cause MLE for around 5*10^5 vertices.

const ll N = 2e5+5;
ll d[N], c[50][50], c2[N][50];
vector<vector<array<ll, 2>>> wadj;
ancestor anc;

void dfs(ll i, ll k) {
    for (auto& [w, j] : wadj[i])
        if (j != k) d[j] = d[i]+w, dfs(j, i);
}

ll dist(ll i, ll j) {
    return d[i]+d[j]-2*d[anc.lca(i, j)];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    dsu uf(n);
    vector<vector<ll>> adj(n);
    wadj.resize(n);
    vector<array<ll, 3>> e;
    while (m--) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        if (uf.query(x, y)) e.pb({x, y, w});
        else {
            uf.unite(x, y);
            adj[x].pb(y), adj[y].pb(x);
            wadj[x].pb({w, y}), wadj[y].pb({w, x});
        }
    }
    anc = ancestor(adj, 0);
    dfs(0, 0);
    set<ll> s;
    for (auto& [x, y, w] : e)
        s.insert(x), s.insert(y);
    vector<ll> r;
    for (auto& x : s) r.pb(x);
    for (ll i = 0; i < r.size(); i++) {
        for (ll j = 0; j < r.size(); j++)
            c[i][j] = dist(r[i], r[j]);
        for (ll j = 0; j < n; j++)
            c2[j][i] = dist(j, r[i]);
    }
    for (auto& [x, y, w] : e) {
        ll i = find(all(r), x)-r.begin();
        ll j = find(all(r), y)-r.begin();
        cmin(c[i][j], w), cmin(c[j][i], w);
    }
    for (ll k = 0; k < r.size(); k++)
        for (ll i = 0; i < r.size(); i++)
            for (ll j = 0; j < r.size(); j++)
                cmin(c[i][j], c[i][k]+c[k][j]);
    for (ll i = 0; i < r.size(); i++)
        for (ll j = i+1; j < r.size(); j++)
            assert(c[i][j] == c[j][i]);
    ll q; cin >> q;
    while (q--) {
        ll x, y; cin >> x >> y; x--, y--;
        ll ans = dist(x, y);
        for (ll i = 0; i < r.size(); i++)
            for (ll j = 0; j < r.size(); j++)
                cmin(ans, c2[x][i]+c[i][j]+c2[y][j]);
        cout << ans << "\n";
    }
}