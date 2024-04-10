/*
 * author:  ADMathNoob
 * created: 09/06/22 10:35:14
 * problem: https://codeforces.com/contest/1726/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class Graph {
 public:
  struct Edge {
    int from;
    int to;
    T cost;
  };

  int n;
  vector<vector<int>> g;
  vector<Edge> edges;

  function<bool(int)> ignore;

  Graph(int n_) : n(n_), g(n), ignore(nullptr) {}

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
  using Graph<T>::n;
  using Graph<T>::g;
  using Graph<T>::edges;

  Undigraph(int n_) : Graph<T>(n_) {}

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
  using Undigraph<T>::n;
  using Undigraph<T>::g;
  using Undigraph<T>::edges;
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

  DfsUndigraph(int n_) : Undigraph<T>(n_) {}

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    DfsUndigraph<int> g(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g.add(x, y);
    }
    g.dfs(0);
    vector<bool> used(m, false);
    for (int i = 0; i < n; i++) {
      int id = g.pe[i];
      if (id != -1) {
        used[id] = true;
      }
    }
    set<int> s;
    set<int> red;
    for (int id = 0; id < m; id++) {
      if (!used[id]) {
        const auto& e = g.edges[id];
        s.insert(e.from);
        s.insert(e.to);
        red.insert(id);
      }
    }
    if (m == n + 2 && (int) s.size() == 3) {
      int max_span = -1;
      int mx = -1;
      for (int id : red) {
        const auto& e = g.edges[id];
        int span = abs(g.depth[e.from] - g.depth[e.to]);
        if (span > mx) {
          mx = span;
          max_span = id;
        }
      }
      
      int lowest = -1;
      int d = -1;
      for (int u : s) {
        if (g.depth[u] > d) {
          lowest = u;
          d = g.depth[u];
        }
      }

      used[max_span] = true;
      used[g.pe[lowest]] = false;
    }
    for (int id = 0; id < m; id++) {
      cout << used[id];
    }
    cout << '\n';
  }
  return 0;
}