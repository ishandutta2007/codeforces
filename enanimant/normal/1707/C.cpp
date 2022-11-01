/*
 * author:  ADMathNoob
 * created: 07/16/22 07:35:12
 * problem: https://codeforces.com/contest/1707/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

class Dsu {
 public:
  int n;
  vector<int> p;
  vector<int> sz;  // get that inverse Ackermann time complexity
  vector<int> v;   // version
  int comps;
  int ver;

  Dsu(int _n) : n(_n) {
    p.resize(n, -1);
    sz.resize(n, 1);
    v.resize(n, 0);
    comps = n;
    ver = 0;
  }

  inline int get(int x) {
    if (v[x] != ver) {
      p[x] = -1;
      sz[x] = 1;
      v[x] = ver;
    }
    return (p[x] == -1 ? x : (p[x] = get(p[x])));
  }

  inline bool same(int x, int y) {
    return (get(x) == get(y));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
    --comps;
    return true;
  }

  inline void reset() {
    comps = n;
    ++ver;
  }
};

template <typename T>
class Graph {
 public:
  struct Edge {
    int from;
    int to;
    T cost;
  };

  vector<Edge> edges;
  vector<vector<int>> g;
  int n;

  function<bool(int)> ignore;

  Graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)>& f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class Undigraph : public Graph<T> {
 public:
  using Graph<T>::edges;
  using Graph<T>::g;
  using Graph<T>::n;

  Undigraph(int _n) : Graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
vector<int> FindMst(const Undigraph<T>& g, T& ans) {
  vector<int> order(g.edges.size());
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&g](int a, int b) {
    return g.edges[a].cost < g.edges[b].cost;
  });
  Dsu d(g.n);
  vector<int> ans_list;
  ans = 0;
  for (int id : order) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    const auto& e = g.edges[id];
    if (d.unite(e.from, e.to)) {
      ans_list.push_back(id);
      ans += e.cost;
    }
  }
  return ans_list;
  // returns edge ids of minimum "spanning" forest
}

template <typename T>
class Forest : public Graph<T> {
 public:
  using Graph<T>::edges;
  using Graph<T>::g;
  using Graph<T>::n;

  Forest(int _n) : Graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
class DfsForest : public Forest<T> {
 public:
  using Forest<T>::edges;
  using Forest<T>::g;
  using Forest<T>::n;
  using Forest<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pre;
  vector<int> post;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

  DfsForest(int _n) : Forest<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pre = vector<int>(n, -1);
    post = vector<int>(n, -1);
    sz = vector<int>(n, -1);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pre.clear();
    post.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }

 private:
  void do_dfs(int v) {
    pre[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      const auto& e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    post[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};

template <typename T>
class LcaForest : public DfsForest<T> {
  // TODO: for LCA only, use HLD to save memory?
 public:
  using DfsForest<T>::edges;
  using DfsForest<T>::g;
  using DfsForest<T>::n;
  using DfsForest<T>::pv;
  using DfsForest<T>::pre;
  using DfsForest<T>::post;
  using DfsForest<T>::root;
  using DfsForest<T>::depth;

  int h;
  vector<vector<int>> pr;

  LcaForest(int _n) : DfsForest<T>(_n) {
  }

  void build_lca() {
    assert(!pv.empty());
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 1;
    while ((1 << h) <= max_depth) {
      // don't use __lg in case n = 0 or 1?
      h++;
    }
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      }
    }
  }

  bool anc(int x, int y) {
    return (pre[x] <= pre[y] && post[y] <= post[x]);
  }

  int lca(int x, int y) {
    assert(!pr.empty());
    if (root[x] != root[y]) {
      return -1;
    }
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    // don't worry, depth[x] can't be 0 since anc(x, y) is false
    for (int j = __lg(depth[x]); j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Undigraph<long long> g(n);
  vector<int> x(m), y(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
    g.add(x[i], y[i], i);
  }
  long long ans;
  vector<int> ids = FindMst(g, ans);
  debug(ids);
  vector<bool> in_mst(m, false);
  LcaForest<long long> f(n);
  for (int id : ids) {
    in_mst[id] = true;
    f.add(x[id], y[id]);
  }
  const int root = 0;
  f.dfs(root);
  f.build_lca();
  vector<int> a(n + 1);
  auto Add = [&](int v, int delta) {
    a[f.pre[v]] += delta;
    a[f.post[v] + 1] -= delta;
  };
  for (int id = 0; id < m; id++) {
    if (!in_mst[id]) {
      int z = f.lca(x[id], y[id]);
      if (z == x[id] || z == y[id]) {
        int lower = x[id] ^ y[id] ^ z;
        int v = lower;
        for (int j = f.h - 1; j >= 0; j--) {
          if (f.pr[v][j] != -1 && !f.anc(f.pr[v][j], z)) {
            v = f.pr[v][j];
          }
        }
        int upper = v;
        Add(upper, +1);
        Add(lower, -1);
      } else {
        Add(root, +1);
        Add(x[id], -1);
        Add(y[id], -1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i + 1] += a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << (a[f.pre[i]] == 0);
  }
  cout << '\n';
  return 0;
}