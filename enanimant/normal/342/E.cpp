// May 7, 2020
// https://codeforces.com/problemset/problem/342/E

/*

*/


#include <bits/stdc++.h>

using namespace std;

/*
Description:
a class that represents a graph and its centroid tree.
*/


class Centroid {
public:
  struct Edge {
    int from;
    int to;
    int cost;
  };
  
  int n;
  vector<vector<int>> g;
  vector<Edge> edges;
  
  vector<int> pv;
  vector<int> order;
  vector<int> sz;
  vector<int> depth;
  
  // data for the centroid tree
  int h;
  vector<int> cpv;
  vector<int> cdepth;
  vector<vector<int>> dist; // dist[v][i]: distance to v's ancestor who has depth i
  
  vector<int> aux; // aggregate value to calculate
  vector<vector<int>> f; // f[v][i]: the aggregate of v to the parent in centroid tree with depth i
  
  Centroid(int _n) : n(_n) {
    g.resize(n);
    pv.resize(n);
    order.reserve(n);
    sz.resize(n);
    depth.resize(n);
    
    h = 32 - __builtin_clz(n);
    cpv.resize(n);
    cdepth.resize(n, -1);
    dist.resize(n, vector<int>(h));
    
    aux.resize(n);
    f.resize(n, vector<int>(h));
  }
  
  int add(int from, int to, int cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n && from != to);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    if (id == n - 2) {
      build_centroid();
    }
    return id;
  }
  
private:
  void dfs(int v, int p) {
    pv[v] = p;
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      const auto &e = edges[id];
      int u = e.from ^ e.to ^ v;
      if (u == p || cdepth[u] != -1) {
        continue;
      }
      depth[u] = depth[v] + 1;
      aux[u] = aux[v] + 1; // HERE: change to calculate what is needed
      dfs(u, v);
      sz[v] += sz[u];
    }
  }
  
  void do_dfs_from(int v) {
    depth[v] = 0;
    aux[v] = 0; // HERE: customize
    order.clear();
    dfs(v, -1);
  }
  
  int find_centroid(int v) {
    do_dfs_from(v);
    int h = sz[v] / 2;
    for (int u : order) {
      bool ok = (sz[v] - sz[u] <= h);
      for (int id : g[u]) {
        const auto &e = edges[id];
        int to = e.from ^ e.to ^ u;
        if (to == pv[u] || cdepth[to] != -1) {
          continue;
        }
        ok &= (sz[to] <= h);
      }
      if (ok) {
        return u;
      }
    }
    assert(0);
  }
  
  void calculate(int v) {
    do_dfs_from(v);
    int d = cdepth[v];
    for (int i : order) {
      dist[i][d] = depth[i];
      f[i][d] = aux[i];
    }
  }
  
  void dfs_cent(int v, int p) {
    // v: the centroid of its current component
    // p: parent in centroid tree
    cpv[v] = p;
    calculate(v);
    for (int id : g[v]) {
      const auto &e = edges[id];
      int u = e.from ^ e.to ^ v;
      if (cdepth[u] != -1) {
        continue;
      }
      int c = find_centroid(u);
      cdepth[c] = cdepth[v] + 1;
      dfs_cent(c, v);
    }
  }
  
  int build_centroid() { // returns the root of the subtree
    int c = find_centroid(0);
    cdepth[c] = 0;
    dfs_cent(c, -1);
  }
};



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m;
  cin >> n >> m;
  Centroid ct(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    ct.add(u, v);
  }
  vector<int> best(n, n);
  function<void(int)> paint = [&](int v) {
    for (int u = v; u != -1; u = ct.cpv[u]) {
      best[u] = min(best[u], ct.dist[v][ct.cdepth[u]]);
    }
  };
  paint(0);
  while (m--) {
    int op, v;
    cin >> op >> v;
    v--;
    if (op == 1) {
      paint(v);
    } else {
      int ans = n;
      for (int u = v; u != -1; u = ct.cpv[u]) {
        ans = min(ans, ct.dist[v][ct.cdepth[u]] + best[u]);
      }
      cout << ans << '\n';
    }
  }


  return 0;
}