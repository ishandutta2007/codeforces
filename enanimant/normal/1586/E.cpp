/*
 * author:  ADMathNoob
 * created: 10/17/21 07:05:23
 * problem: https://codeforces.com/contest/1586/problem/E
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
class DfsUndigraph : public Undigraph<T> {
 public:
  using Undigraph<T>::edges;
  using Undigraph<T>::g;
  using Undigraph<T>::n;
  using Undigraph<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pre;
  vector<int> post;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<int> low;
  vector<T> dist;
  vector<int> was;
  int attempt;

  DfsUndigraph(int _n) : Undigraph<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pre = vector<int>(n, -1);
    post = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    low = vector<int>(n, -1);
    dist = vector<T>(n);
    was = vector<int>(n, -1);
    attempt = 0;
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
    low.clear();
    dist.clear();
    was.clear();
  }

 private:
  void do_dfs(int v) {
    was[v] = attempt;
    pre[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    low[v] = pre[v];
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      const auto& e = edges[id];
      int to = e.from ^ e.to ^ v;
      if (was[to] == attempt) {
        low[v] = min(low[v], pre[to]);
        continue;
      }
      pv[to] = v;
      pe[to] = id;
      root[to] = root[v];
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      do_dfs(to);
      sz[v] += sz[to];
      low[v] = min(low[v], low[to]);
    }
    post[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    pv[v] = -1;
    pe[v] = -1;
    root[v] = v;
    depth[v] = 0;
    dist[v] = T{};
    attempt++;
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
      if (root[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  DfsUndigraph<int> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g.add(x, y);
  }
  int tt;
  cin >> tt;
  vector<int> a(tt), b(tt);
  vector<int> deg(n, 0);
  for (int i = 0; i < tt; i++) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
    ++deg[a[i]];
    ++deg[b[i]];
  }
  vector<int> odd;
  for (int i = 0; i < n; i++) {
    if (deg[i] % 2 == 1) {
      odd.push_back(i);
    }
  }
  if (odd.empty()) {
    g.dfs(0);
    cout << "YES" << '\n';
    for (int qq = 0; qq < tt; qq++) {
      int x = a[qq];
      int y = b[qq];
      vector<int> pa, pb;
      while (g.depth[x] > g.depth[y]) {
        pa.push_back(x);
        x = g.pv[x];
      }
      while (g.depth[y] > g.depth[x]) {
        pb.push_back(y);
        y = g.pv[y];
      }
      while (x != y) {
        pa.push_back(x);
        x = g.pv[x];
        pb.push_back(y);
        y = g.pv[y];
      }
      pa.push_back(x);
      for (int i = (int) pb.size() - 1; i >= 0; i--) {
        pa.push_back(pb[i]);
      }
      cout << pa.size() << '\n';
      for (int i = 0; i < (int) pa.size(); i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << pa[i] + 1;
      }
      cout << '\n';
    }
  } else {
    cout << "NO" << '\n';
    cout << odd.size() / 2 << '\n';
  }
  return 0;
}