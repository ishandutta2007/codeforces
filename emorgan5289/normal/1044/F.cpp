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

struct hld_single {

    vector<vector<int>> adj;
    vector<int> vin, vout, head, p, d, sz;
    vector<bool> hvy;
    int n, t = 0;

    void _assign(int i, int v) {
        if ((p[i] = v) != -1) d[i] = d[v]+1;
        for (int j : adj[i])
            if (j != v) _assign(j, i), sz[i] += sz[j];
        int b = -1;
        for (int j : adj[i])
            if (j != v && (b == -1 || sz[j] > sz[b])) b = j;
        if (b != -1) hvy[b] = 1;
    }

    void _dfs(int i) {
        vin[i] = t++;
        head[i] = hvy[i] ? head[p[i]] : i;
        for (int j : adj[i])
            if (j != p[i] && hvy[j]) _dfs(j);
        for (int j : adj[i])
            if (j != p[i] && !hvy[j]) _dfs(j);
        vout[i] = t-1;
    }

    hld_single(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (_adj.size() == 0) return;
        vin.resize(n), vout.resize(n), head.resize(n);
        p.assign(n, -1), d.assign(n, 0), sz.assign(n, 1), hvy.assign(n, 0);
        _assign(root, -1), _dfs(root);
    }

    // returns a single interval (inclusive of both ends) which
    // represents the subtree of vertex i.
    array<int, 2> subtree(int i) const {
        return {vin[i], vout[i]};
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to the root (inclusive of both).
    vector<array<int, 2>> path(int i) const {
        vector<array<int, 2>> out;
        for (; i != -1; i = p[head[i]])
            out.push_back({vin[head[i]], vin[i]});
        reverse(out.begin(), out.end());
        return out;
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to vertex j (inclusive of both).
    vector<array<int, 2>> path(int i, int j) const {
        vector<array<int, 2>> tmp, out;
        for (; head[i] != head[j]; j = p[head[j]]) {
            if (d[head[i]] > d[head[j]]) swap(i, j);
            tmp.push_back({vin[head[j]], vin[j]});
        }
        if (d[i] > d[j]) swap(i, j);
        tmp.push_back({vin[i], vin[j]});
        sort(tmp.begin(), tmp.end());
        for (auto [l, r] : tmp) {
            if (!out.empty() && out.back()[1] == l-1)
                l = out.back()[0], out.pop_back();
            out.push_back({l, r});
        }
        return out;
    }
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

const int N = 2e5+5, S = 500;
int off[N], a[N];
short f[S][2*N];

void upd(int l, int r, int k) {
    while (l%S != 0 && l <= r) {
        f[l/S][N+a[l]]--;
        a[l] += k;
        f[l/S][N+a[l]]++;
        l++;
    }
    while (l+S-1 <= r) {
        off[l/S] += k;
        l += S;
    }
    while (l <= r) {
        f[l/S][N+a[l]]--;
        a[l] += k;
        f[l/S][N+a[l]]++;
        l++;
    }
}

int qry(int k) {
    int ans = 0;
    for (int i = 0; i < S; i++)
        ans += f[i][N+k-off[i]];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        f[i/S][N]++;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    ancestor anc(adj, 0);
    set<array<int, 2>> s;
    while (q--) {
        int x, y; cin >> x >> y; x--, y--;
        if (x > y) swap(x, y);
        int k = 1;
        if (s.count({x, y})) {
            s.erase(s.find({x, y}));
            k = -1;
        } else {
            s.insert({x, y});
        }
        // debug(x, y, k);
        if (anc.is_ancestor(y, x)) {
            y = anc.step(y, x);
            upd(anc.vin[x], anc.vout[x], k);
            upd(anc.vin[0], anc.vout[0], k);
            upd(anc.vin[y], anc.vout[y], -k);
        } else if (anc.is_ancestor(x, y)) {
            x = anc.step(x, y);
            upd(anc.vin[y], anc.vout[y], k);
            upd(anc.vin[0], anc.vout[0], k);
            upd(anc.vin[x], anc.vout[x], -k);
        } else {
            upd(anc.vin[x], anc.vout[x], k);
            upd(anc.vin[y], anc.vout[y], k);
        }
        // debug(s.size());
        cout << qry(s.size()) << "\n";
    }
}