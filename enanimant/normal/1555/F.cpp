/*
 * author:  ADMathNoob
 * created: 07/30/21 14:34:07
 * problem: https://codeforces.com/contest/1555/problem/F
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

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

template <typename T>
class HldForest : public LcaForest<T> {
 public:
  using LcaForest<T>::edges;
  using LcaForest<T>::g;
  using LcaForest<T>::n;
  using LcaForest<T>::ignore;
  using LcaForest<T>::pv;
  using LcaForest<T>::sz;
  using LcaForest<T>::pre;
  using LcaForest<T>::order;
  using LcaForest<T>::depth;
  using LcaForest<T>::dfs;
  using LcaForest<T>::dfs_all;
  using LcaForest<T>::lca;
  using LcaForest<T>::build_lca;

  vector<int> head;
  vector<int> visited;

  HldForest(int _n) : LcaForest<T>(_n) {
    visited.resize(n);
  }

  void build_hld(const vector<int>& vs) {
    for (int tries = 0; tries < 2; tries++) {
      if (vs.empty()) {
        dfs_all();
      } else {
        order.clear();
        for (int v : vs) {
          assert(depth[v] == -1);
          dfs(v, false);
        }
        assert((int) order.size() == n);
      }
      if (tries == 1) {
        break;
      }
      for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
          continue;
        }
        int best = -1, bid = 0;
        for (int j = 0; j < (int) g[i].size(); j++) {
          int id = g[i][j];
          if (ignore != nullptr && ignore(id)) {
            continue;
          }
          int v = edges[id].from ^ edges[id].to ^ i;
          if (pv[v] != i) {
            continue;
          }
          if (sz[v] > best) {
            best = sz[v];
            bid = j;
          }
        }
        swap(g[i][0], g[i][bid]);
      }
    }
    build_lca();
    head.resize(n);
    for (int i = 0; i < n; i++) {
      head[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
      int x = order[i];
      int y = order[i + 1];
      if (pv[y] == x) {
        head[y] = head[x];
      }
    }
  }

  void build_hld(int v) {
    build_hld(vector<int>(1, v));
  }

  void build_hld_all() {
    build_hld(vector<int>());
  }

  vector<pair<int, int>> get_path(int x, int y) {
    vector<pair<int, int>> path[2];
    int z = lca(x, y);
    for (int id = 0; id < 2; id++) {
      int v = (id == 0 ? x : y);
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          path[id].emplace_back(pre[z] + 1, pre[v]);
          break;
        }
        path[id].emplace_back(pre[head[v]], pre[v]);
        v = pv[head[v]];
      }
    }
    vector<pair<int, int>> ret;
    for (int i = 0; i < (int) path[0].size(); i++) {
      ret.emplace_back(path[0][i].second, path[0][i].first);
    }
    ret.emplace_back(-1, pre[z]);
    for (int i = (int) path[1].size() - 1; i >= 0; i--) {
      ret.push_back(path[1][i]);
    }
    return ret;
    // returns segments of the path:
    //   first from x to lca, reversed segments
    //   then (-1, pre[lca])
    //   then from lca to y, direct segments
    // but in most cases, apply_on_path should be enough
  }

  bool apply_on_path(int x, int y, bool with_lca, function<void(int, int, bool)> f) {
    // f(x, y, up): up -- whether this part of the path goes up
    assert(!head.empty());
    int z = lca(x, y);
    if (z == -1) {
      return false;
    }
    {
      int v = x;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          f(pre[z] + 1, pre[v], true);
          break;
        }
        f(pre[head[v]], pre[v], true);
        v = pv[head[v]];
      }
    }
    if (with_lca) {
      f(pre[z], pre[z], false);
    }
    {
      int v = y;
      int cnt_visited = 0;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          f(pre[z] + 1, pre[v], false);
          break;
        }
        visited[cnt_visited++] = v;
        v = pv[head[v]];
      }
      for (int at = cnt_visited - 1; at >= 0; at--) {
        v = visited[at];
        f(pre[head[v]], pre[v], false);
      }
    }
    return true;
  }
};

class Dsu {
 public:
  int n;
  vector<int> p;
  vector<int> sz;
  vector<int> v;  // version
  vector<pair<int, int>> ops;
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
    while (true) {
      if (v[x] != ver) {
        p[x] = -1;
        sz[x] = 1;
        v[x] = ver;
      }
      if (p[x] == -1) {
        break;
      }
      x = p[x];
    }
    return x;
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
    ops.emplace_back(x, y);
    --comps;
    return true;
  }

  inline void undo() {
    // only undoes unite(x, y) operations that returned true
    assert(!ops.empty());
    int x, y;
    tie(x, y) = ops.back();
    ops.pop_back();
    sz[y] -= sz[x];
    p[x] = -1;
    ++comps;
  }
  
  void reset() {
    ops.clear();
    comps = n;
    ++ver;
  }
};

class SegTree {
 public:
  struct Node {
    // declare variables with default value
    int add = 0;
    int sum = 0;

    void apply(int l, int r, int v) {
      add += v;
      sum += (r - l + 1) * v;
    }
  };

  Node unite(const Node& a, const Node& b) const {
    Node res;
    res.sum = a.sum + b.sum;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<Node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename T>
  void build(int x, int l, int r, const vector<T>& v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  Node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    Node res;
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else if (ll > y) {
      res = get(z, y + 1, r, ll, rr);
    } else {
      res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
    }
    pull(x, z);
    return res;
  }

  template <typename... T>
  void modify(int x, int l, int r, int ll, int rr, const T&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const Node&)>& f) {
    if (l == r) {
      return l;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const Node&)>& f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const Node&)>& f) {
    if (l == r) {
      return l;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const Node&)>& f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  SegTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename T>
  SegTree(const vector<T>& v) {
    n = (int) v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  Node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr < n);
    return get(0, 0, n - 1, ll, rr);
  }

  Node get(int p) {
    assert(0 <= p && p < n);
    return get(0, 0, n - 1, p, p);
  }

  // due to variadic templates, we cannot also have modify(int p, const T&... v)
  template <typename... T>
  void modify(int ll, int rr, const T&... v) {
    assert(0 <= ll && ll <= rr && rr < n);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const Node&)>& f) {
    assert(0 <= ll && ll <= rr && rr < n);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const Node&)>& f) {
    assert(0 <= ll && ll <= rr && rr < n);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  Dsu d(n);
  vector<int> ret(q, -1);
  vector<tuple<int, int, int>> e(q);
  HldForest<int> g(n);
  for (int i = 0; i < q; i++) {
    auto& [u, v, w] = e[i];
    cin >> u >> v >> w;
    --u; --v;
    if (d.unite(u, v)) {
      ret[i] = 1;
      g.add(u, v, w);
    }
  }
  g.build_hld_all();
  SegTree st(n);
  for (int i = 0; i < q; i++) {
    const auto& [u, v, w] = e[i];
    if (ret[i] != -1) {
      continue;
    }
    if ((g.dist[u] + g.dist[v] + w) % 2 == 1) {
      int sum = 0;
      g.apply_on_path(u, v, false, [&](int L, int R, bool up) {
        sum += st.get(L, R).sum;
      });
      if (sum == 0) {
        ret[i] = 1;
        g.apply_on_path(u, v, false, [&](int L, int R, bool up) {
          st.modify(L, R, +1);
        });
      }
    } else {
      ret[i] = 0;
    }
  }
  for (int r : ret) {
    cout << (r == 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}