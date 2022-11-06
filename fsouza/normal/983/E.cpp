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

struct point_t {
  int x, y;
};

struct bit_t {
  int n;
  vector<int> tree;
  bit_t(int _n): n(_n), tree(n + 1) {}
  void update(int i, int delta) {
    for (++i; i <= n; i += i&-i)
      tree[i] += delta;
  }
  int query(int i) {
    int result = 0;
    for (++i; i > 0; i -= i&-i)
      result += tree[i];
    return result;
  }
};

struct query2_t {
  int x0, x1;
  int y0, y1;
  int *result;
};

struct solver2_t {
  int nx;
  vector<point_t> points;
  vector<query2_t> queries;
  solver2_t(int _nx, const vector<point_t> &_points,
            const vector<query2_t> &_queries)
    : nx(_nx), points(_points), queries(_queries) {
  }
  void solve() {
    enum evtype_t {
      START_QUERY = 0,
      PROCESS_POINT = 1,
      END_QUERY = 2,
    };
    struct event_t {
      evtype_t type;
      int y, id;
      bool operator<(const event_t &o) const {
        if (y != o.y) return y < o.y;
        return type < o.type;
      }
    };
    vector<event_t> events;
    for (int i = 0; i < (int)queries.size(); ++i) {
      const query2_t &q = queries[i];
      events.push_back({START_QUERY, q.y0, i});
      events.push_back({END_QUERY, q.y1, i});
      *q.result = 0;
    }
    for (int i = 0; i < (int)points.size(); ++i) {
      events.push_back({PROCESS_POINT, points[i].y, i});
    }
    sort(events.begin(), events.end());

    bit_t bit(nx);
    for (const event_t &ev : events) {
      if (ev.type == PROCESS_POINT) {
        bit.update(points[ev.id].x, +1);
      } else {
        const query2_t &q = queries[ev.id];
        int range_value = bit.query(q.x1) - bit.query(q.x0 - 1);
        if (ev.type == START_QUERY) *q.result -= range_value;
        else *q.result += range_value;
      }
    }
  }
};

struct query_t {
  int a, b, l = -1;
  int result = -1;
  bool is_done;
  int q2res;
  query_t(int _a, int _b): a(_a), b(_b) {}
};

struct solver_t {
  int n, lgn;
  vector<vector<int>> adj, ancestor, reach;
  vector<int> parent, depth, next_reach, preorder, invpreorder, endsubtree;
  solver_t(int _n): n(_n), lgn(__lg(n)), adj(n)
                  , ancestor(lgn + 1, vector<int>(n, -1))
                  , reach(lgn + 1, vector<int>(n, -1))
                  , parent(n), depth(n), next_reach(n, -1)
                  , invpreorder(n), endsubtree(n) {}
  int highest_node(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return depth[a] < depth[b] ? a : b;
  }
  void dfs(int v, int p, int d) {
    invpreorder[v] = preorder.size();
    preorder.push_back(v);
    parent[v] = p;
    depth[v] = d;
    ancestor[0][v] = p;
    for (int l = 1; l <= lgn; ++l) {
      int al1 = ancestor[l - 1][v];
      if (al1 == -1) ancestor[l][v] = -1;
      else ancestor[l][v] = ancestor[l - 1][al1];
    }
    for (int u : adj[v])
      if (u != p)
        dfs(u, v, d + 1);
    endsubtree[v] = preorder.size() - 1;
  }
  int climb(int v, int dist) {
    for (int l = 0; l <= lgn; ++l)
      if (dist & (1<<l))
        v = ancestor[l][v];
    return v;
  }
  int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = climb(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int l = lgn; l >= 0; --l)
      if (ancestor[l][a] != ancestor[l][b])
        a = ancestor[l][a], b = ancestor[l][b];
    return parent[a];
  }
  void dfs2(int v, int p) {
    for (int u : adj[v])
      if (u != p) {
        dfs2(u, v);
        next_reach[v] = highest_node(next_reach[v], next_reach[u]);
        if (next_reach[v] != -1 && depth[next_reach[v]] >= depth[v])
          next_reach[v] = -1;
      }
  }
  void dfs3(int v, int p) {
    reach[0][v] = next_reach[v];
    for (int l = 1; l <= lgn; ++l) {
      int rl1v = reach[l - 1][v];
      if (rl1v == -1) reach[l][v] = -1;
      else reach[l][v] = reach[l - 1][rl1v];
    }
    for (int u : adj[v])
      if (u != p)
        dfs3(u, v);
  }
  void solve(vector<query_t> &queries, const vector<pair<int, int>> &buses) {
    vector<point_t> solver2points;
    dfs(0, -1, 0);
    for (const pair<int, int> &bus : buses) {
      int a, b, l;
      tie(a, b) = bus;
      l = lca(a, b);
      if (a != l) next_reach[a] = highest_node(next_reach[a], l);
      if (b != l) next_reach[b] = highest_node(next_reach[b], l);
      solver2points.push_back({invpreorder[a], invpreorder[b]});
      solver2points.push_back({invpreorder[b], invpreorder[a]});
    }
    dfs2(0, -1);
    dfs3(0, -1);
    vector<query2_t> solver2queries;
    for (query_t &q : queries) {
      q.l = lca(q.a, q.b);
      q.result = 0;
      for (int &v : {ref(q.a), ref(q.b)}) {
        for (int l = lgn; l >= 0; --l)
          if (reach[l][v] != -1 && depth[reach[l][v]] > depth[q.l]) {
            v = reach[l][v];
            q.result += 1<<l;
          }
      }
      if (q.a == q.b) {
        q.is_done = true;
      } else if (depth[next_reach[q.a] != -1 ? next_reach[q.a] : q.a] >
                 depth[q.l] ||
                 depth[next_reach[q.b] != -1 ? next_reach[q.b] : q.b] >
                 depth[q.l]) {
        q.is_done = true;
        q.result = -1;
      } else if (q.a == q.l || q.b == q.l) {
        q.is_done = true;
        q.result += 1;
      } else {
        q.is_done = false;
        solver2queries.push_back({invpreorder[q.a], endsubtree[q.a],
              invpreorder[q.b], endsubtree[q.b], &q.q2res});
      }
    }
    solver2_t solver2(n, solver2points, solver2queries);
    solver2.solve();
    for (query_t &q : queries)
      if (!q.is_done) {
        if (q.q2res > 0) q.result += 1;
        else q.result += 2;
      }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  solver_t solver(n);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p), --p;
    solver.adj[i].push_back(p);
    solver.adj[p].push_back(i);
  }
  int nb;
  scanf("%d", &nb);
  vector<pair<int, int>> buses;
  for (int i = 0; i < nb; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    buses.emplace_back(a, b);
  }
  int nq;
  scanf("%d", &nq);
  vector<query_t> queries;
  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    queries.emplace_back(a, b);
  }
  solver.solve(queries, buses);
  for (int q = 0; q < nq; ++q) {
    printf("%d\n", queries[q].result);
  }
  return 0;
}