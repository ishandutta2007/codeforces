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

// combined data structure for various ancestor-related queries.

struct ancestor {

    vector<int> vin, vout, d, rvin;
    vector<vector<int>> adj, p;
    int n, t = 0, e;

    void dfs(int i, int v) {
        rvin[t] = i;
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
        rvin.assign(n, -1);
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

struct segtree {

    using node = array<int, 2>;

    node combine(node x, node y) {
        return max(x, y);
    }

    constexpr static node identity = {-1, -1};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u;
    int n;

    segtree(vector<array<int, 2>>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void push(int i) {
        if (u[i] == 0) return;
        tree[i][0] += u[i];
        if (i < n) {
            u[2*i] += u[i];
            u[2*i+1] += u[i];
        }
        u[i] = 0;
    }

    void update(int l, int r, int x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] += x;
        }
        push(i);
        if (l > b[i] || r < a[i] || (l <= a[i] && r >= b[i]))
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
        tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    vector<int> vis(n, 0);
    ancestor anc(adj, 0);
    vector<array<int, 2>> v;
    for (int i = 0; i < n; i++)
        v.pb({anc.d[anc.rvin[i]], i});
    segtree s(v);
    ll w = 0;
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            if (anc.d[j] < anc.d[i])
                p[i] = j;
    ll c = 0, r = 0;
    ll ans = inf_ll;
    for (ll i = 0; i <= n; i++)
        cmin(ans, -i*(n-i));
    for (int j = 0; j < k; j++) {
        auto [d, i] = s.query(0, n-1);
        r++; w--;
        if (d != 0) {
            i = anc.rvin[i];
            while (i != -1) {
                if (vis[i]) break;
                vis[i] = 1;
                w++;
                s.update(anc.vin[i], anc.vout[i], -1);
                i = p[i];
            }
        }
        ll b = n-w-r;
        // 0 <= x <= b
        // (r*(w+x) + (x-b)*(w+x))
        // x^2 + rx + rw - bx + wx - bw
        ll x = min(b, max(0ll, (b-r-w)/2));
        debug(r, w, b, x);
        cmax(ans, (r*(w+x) + (x-b)*(w+x)));
    }
    cout << ans << "\n";
}