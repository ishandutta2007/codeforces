#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct unionfind_t {
  int n;
  vector<int> parent, rank;
  unionfind_t(int _n): n(_n), parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
  }
  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    if (rank[a] == rank[b]) ++rank[b];
  }
};

struct solver_t {
  struct edge_t {
    int o, value, id;
  };
  int n, lgn;
  vector<vector<edge_t>> adj;
  vector<pair<int, int>> results;
  vector<int> depth;
  vector<vector<int>> ancestor;
  vector<vector<int>> max_above;
  vector<int> id_edge_above;
  vector<bool> resolved;
  vector<int> next_unresolved;
  solver_t(int _n)
      : n(_n)
      , lgn(__lg(n))
      , adj(n)
      , depth(n)
      , ancestor(lgn + 1, vector<int>(n))
      , max_above(lgn + 1, vector<int>(n))
      , id_edge_above(n, -1)
      , resolved(n, false)
      , next_unresolved(n) {
    resolved[0] = true;
    iota(next_unresolved.begin(), next_unresolved.end(), 0);
    next_unresolved[0] = -1;
  }
  void init() {
    dfs(0, 0, 0, 0);
  }
  void dfs(int v, int p, int d, int ed_value) {
    depth[v] = d;
    ancestor[0][v] = p;
    max_above[0][v] = ed_value;
    for (int l = 1; l <= lgn; ++l) {
      ancestor[l][v] = ancestor[l - 1][ancestor[l - 1][v]];
      max_above[l][v] = max(max_above[l - 1][v],
                            max_above[l - 1][ancestor[l - 1][v]]);
    }
    for (const edge_t &ed : adj[v]) {
      if (ed.o != p) {
        id_edge_above[ed.o] = ed.id;
        dfs(ed.o, v, d + 1, ed.value);
      }
    }
  }
  int get_next_unresolved(int v) {
    if (v == -1 || !resolved[v]) return v;
    else return next_unresolved[v] = get_next_unresolved(next_unresolved[v]);
  }
  int climb(int v, int dist) {
    for (int l = 0; l <= lgn; ++l)
      if (dist & (1<<l))
        v = ancestor[l][v];
    return v;
  }
  int max_value_on_climb(int v, int dist) {
    int result = INT_MIN;
    for (int l = 0; l <= lgn; ++l)
      if (dist & (1<<l)) {
        result = max(result, max_above[l][v]);
        v = ancestor[l][v];
      }
    return result;
  }
  int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = climb(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int l = lgn; l >= 0; --l)
      if (ancestor[l][a] != ancestor[l][b])
        a = ancestor[l][a], b = ancestor[l][b];
    return ancestor[0][a];
  }
  int query(int a, int b, int value) {
    int l = lca(a, b);
    int max_value = max(max_value_on_climb(a, depth[a] - depth[l]),
                        max_value_on_climb(b, depth[b] - depth[l]));
    for (int v : {a, b}) {
      for (int u = get_next_unresolved(v); u != -1 && depth[u] > depth[l];
           u = get_next_unresolved(u)) {
        results.emplace_back(id_edge_above[u], value - 1);
        resolved[u] = true;
        next_unresolved[u] = ancestor[0][u];
      }
    }
    return max_value - 1;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  struct edge_t {
    int a, b, value, id;
  };
  vector<edge_t> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, value;
    scanf("%d %d %d", &a, &b, &value), --a, --b;
    edges.push_back((edge_t){a, b, value, i});
  }
  sort(edges.begin(), edges.end(), [](const edge_t &a, const edge_t &b) {
      return a.value < b.value;
    });
  solver_t solver(n);
  unionfind_t uf(n);
  vector<edge_t> edges_to_query;
  for (const edge_t &ed : edges) {
    if (uf.find(ed.a) != uf.find(ed.b)) {
      solver.adj[ed.a].push_back((solver_t::edge_t){ed.b, ed.value, ed.id});
      solver.adj[ed.b].push_back((solver_t::edge_t){ed.a, ed.value, ed.id});
      uf.join(ed.a, ed.b);
    } else {
      edges_to_query.push_back(ed);
    }
  }
  solver.init();
  vector<int> result(edges.size(), -1);
  for (const edge_t &ed : edges_to_query)
    result[ed.id] = solver.query(ed.a, ed.b, ed.value);
  for (const pair<int, int> &result_pair : solver.results)
    result[result_pair.first] = result_pair.second;
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");
  return 0;
}