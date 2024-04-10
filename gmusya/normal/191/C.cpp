#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct segment_tree {
    struct ver {
        ver() = default;
        ll mod = 0;
        ll sum = 0;
    };
    int sz = 0;
    vector <ver> t;
    void push (int v, int tl, int tr) {
        int tm = (tl + tr) / 2;
        t[v * 2].mod += t[v].mod;
        t[v * 2 + 1].mod += t[v].mod;
        t[v].mod = 0;
    }
    void set_value(int v, int tl, int tr) {
        int tm = (tl + tr) / 2;
        t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum +
                   t[v * 2].mod * (tm - tl + 1) + t[v * 2 + 1].mod * (tr - tm);
    }
    void build (int v, int tl, int tr, vector <int> &a) {
        if (tl == tr) {
            t[v].sum = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);
        set_value(v, tl, tr);
    }
    ll get (int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v].sum + t[v].mod * (tr - tl + 1);
        push(v, tl, tr);
        set_value(v, tl, tr);
        int tm = (tl + tr) / 2;
        ll s1 = get(v * 2, tl, tm, l, min(tm, r));
        ll s2 = get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
        return s1 + s2;
    }
    void update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r) return;
        if (l == tl && r == tr) {
            t[v].mod += val;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(tm, r), val);
        update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
        set_value(v, tl, tr);
    }
    ll get(int l, int r) {
        return get(1, 0, sz - 1, l, r);
    }
    void update(int l, int r, int val) {
        update(1, 0, sz - 1, l, r, val);
    }
    void build (vector <int> &a) {
        sz = a.size();
        t.resize(sz << 2);
        build(1, 0, sz - 1, a);
    }
};

struct graph {
    vector <pair <int, int>> e;
    int n, timer = 0;
    vector <bool> used;
    vector <int> sz, depth, parent;
    vector <int> tin, pos, root;
    vector <vector <int>> g;
    vector <int> lg;
    vector <vector <int>> up;
    segment_tree t;
    explicit graph(int _n) {
        n = _n;
        used.resize(n);
        sz.resize(n), depth.resize(n), parent.resize(n);
        root.resize(n), tin.resize(n), pos.resize(n);
        g.resize(n);
        lg.resize(n);
        for (int i = 2; i < n; i++)
            lg[i] = lg[i / 2] + 1;
        up.resize(n, vector <int>(lg[n - 1] + 1));
    }
    void dfs1(int v) {
        used[v] = true;
        sz[v] = 1;
        for (int u : g[v])
            if (!used[u]) {
                parent[u] = v;
                depth[u] = depth[v] + 1;
                dfs1(u);
                sz[v] += sz[u];
            }
    }
    void dfs2(int v) {
        tin[v] = timer++;
        pos[tin[v]] = v;
        used[v] = false;
        int ma = -1;
        for (int u : g[v])
            if (used[u])
                if (ma == -1 || sz[u] > sz[ma]) ma = u;
        if (ma == -1) return;
        root[ma] = root[v];
        dfs2(ma);
        for (int u : g[v])
            if (used[u] && u != ma) {
                root[u] = u;
                dfs2(u);
            }
    }
    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int k = (depth[v] - depth[u]);
        for (int i = 0; i <= lg[n - 1]; i++)
            if (k & (1 << i))
                v = up[v][i];
        if (u == v) return u;
        pair <int, int> lca = { depth[0], 0 };
        for (int i = lg[n - 1]; i >= 0; i--) {
            int _u = up[u][i];
            int _v = up[v][i];
            if (_u == _v) lca = max(lca, { depth[_u], _u });
            else {
                u = _u;
                v = _v;
            }
        }
        return lca.second;
    }
    void build_lca() {
        for (int i = 0; i < n; i++)
            up[i][0] = parent[i];
        for (int j = 1; j <= lg[n - 1]; j++)
            for (int i = 0; i < n; i++)
                up[i][j] = up[up[i][j - 1]][j - 1];
    }
    void build_edges(int m) {
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            e.push_back({u, v});
            g[u].push_back(v), g[v].push_back(u);
        }
    }
    void prepare(vector <int> &a) {
        build_edges(n - 1);
        dfs1(0);
        dfs2(0);
        build_lca();
        vector <int> b(n);
        for (int i = 0; i < n; i++)
           b[tin[i]] = a[i];
        t.build(b);
    }
    ll sum_query (int w, int v) {
        if (depth[root[v]] <= depth[w]) return t.get(tin[w], tin[v]);
        ll x = t.get(tin[root[v]], tin[v]);
        ll y = sum_query(w, parent[root[v]]);
        return x + y;
    }
    ll get (int u, int v) {
        int w = lca(u, v);
        ll s1 = sum_query(w, u);
        ll s2 = sum_query(w, v);
        ll s3 = sum_query(w, w);
        return s1 + s2 - s3;
    }
    void update_query(int w, int v, int val) {
        if (depth[root[v]] <= depth[w]) {
            t.update(tin[w], tin[v], val);
            return;
        }
        t.update(tin[root[v]], tin[v], val);
        update_query(w, parent[root[v]], val);
    }
    void update (int u, int v, int val) {
        int w = lca(u, v);
        update_query(w, u, val);
        update_query(w, v, val);
        update_query(w, w, -2 * val);
    }
    void write_all () {
        for (auto &now : e) {
            int u = now.first, v = now.second;
            if (parent[u] == v)
                cout << get(u, u) << ' ';
            else
                cout << get(v, v) << ' ';
        }
    }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  graph g(n);
  g.prepare(a);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g.update(u, v, 1);
  }
  g.write_all();
}