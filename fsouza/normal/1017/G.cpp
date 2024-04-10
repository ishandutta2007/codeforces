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

struct segtree_t {
  struct node_t {
    lint sum = 0LL, minv = LLONG_MAX;
    node_t() {}
    node_t(lint _sum, lint _minv): sum(_sum), minv(_minv) {}
    node_t(const node_t &a, const node_t &b) {
      sum = a.sum + b.sum;
      if (a.minv == LLONG_MAX) minv = b.minv;
      else minv = min(b.minv, b.sum + a.minv);
    }
  };
  int n;
  vector<node_t> tree;
  segtree_t() {}
  segtree_t(int _n): n(_n), tree(4 * n) {
    build(0, 0, n - 1);
  }
  void build(int v, int l, int r) {
    if (l == r) tree[v] = {1LL, 1LL};
    else {
      int m = l + (r - l) / 2;
      build(2*v+1, l, m);
      build(2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  void reset(int pos) { reset(pos, 0, 0, n - 1); }
  void reset(int pos, int v, int l, int r) {
    if (l == r) {
      tree[v] = {1LL, 1LL};
    } else {
      int m = l + (r - l) / 2;
      if (pos <= m) reset(pos, 2*v+1, l, m);
      else reset(pos, 2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  void update(int pos, lint delta) { update(pos, delta, 0, 0, n - 1); }
  void update(int pos, lint delta, int v, int l, int r) {
    if (l == r) {
      tree[v].sum += delta;
      tree[v].minv += delta;
    } else {
      int m = l + (r - l) / 2;
      if (pos <= m) update(pos, delta, 2*v+1, l, m);
      else update(pos, delta, 2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  node_t query(int a, int b) { return query(a, b, 0, 0, n - 1); }
  node_t query(int a, int b, int v, int l, int r) {
    if (a > r || b < l) return {};
    else if (a <= l && r <= b) return tree[v];
    else {
      int m = l + (r - l) / 2;
      return node_t(query(a, b, 2*v+1, l, m), query(a, b, 2*v+2, m+1, r));
    }
  }
};

struct heavylight_t {
  int n;
  //
  vector<vector<int>> adj = vector<vector<int>>(n);
  vector<int> parent = vector<int>(n);
  vector<int> depth = vector<int>(n);
  vector<int> sts = vector<int>(n);
  vector<int> path_of = vector<int>(n);
  vector<int> preorder;
  vector<int> invpreorder = vector<int>(n), endsubtree = vector<int>(n);
  struct path_t {
    int n;
    segtree_t seg;
    void init() {
      seg = segtree_t(n);
    }
  };
  vector<path_t> paths = vector<path_t>(n);

  void init(int v, int p, int d) {
    invpreorder[v] = preorder.size();
    preorder.push_back(v);
    parent[v] = p;
    depth[v] = d;
    sts[v] = 1;
    for (int u : adj[v])
      if (u != p) {
        init(u, v, d + 1);
        sts[v] += sts[u];
      }
    endsubtree[v] = preorder.size() - 1;
  }

  void assign_paths(int v, int p, int path_of_v) {
    path_of[v] = path_of_v;
    paths[path_of[v]].n += 1;
    for (int u : adj[v])
      if (u != p)
        assign_paths(u, v, 2 * sts[u] >= sts[v] ? path_of_v : u);
  }

  void prepare() {
    init(0, -1, 0);
    assign_paths(0, -1, 0);
    for (int v = 0; v < n; ++v)
      if (path_of[v] == v)
        paths[v].init();
  }

  int pos_of(int v) { return depth[v] - depth[path_of[v]]; }

  segtree_t::node_t query(int v) {
    segtree_t::node_t result;
    while (v != -1) {
      result = segtree_t::node_t(paths[path_of[v]].seg.query(0, pos_of(v)),
                                 result);
      v = parent[path_of[v]];
    }
    return result;
  }
};

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  heavylight_t hl{n};
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p), --p;
    hl.adj[i].push_back(p);
    hl.adj[p].push_back(i);
  }
  hl.prepare();

  auto preorder_cmp = [&hl](int a, int b) {
    return hl.invpreorder[a] < hl.invpreorder[b];
  };
  set<int, decltype(preorder_cmp)> changed(preorder_cmp);

  for (int q = 0; q < nq; ++q) {
    int kind, v;
    scanf("%d %d", &kind, &v), --v;
    if (kind == 1) {
      changed.insert(v);
      hl.paths[hl.path_of[v]].seg.update(hl.pos_of(v), -1LL);
    } else if (kind == 2) {
      auto it = changed.lower_bound(v);
      while (it != changed.end() && hl.invpreorder[*it] <= hl.endsubtree[v]) {
        int u = *it++;
        hl.paths[hl.path_of[u]].seg.reset(hl.pos_of(u));
        changed.erase(u);
      }
      segtree_t::node_t res = hl.query(v);
      if (res.minv <= 0LL) {
        lint delta = 1 - res.minv;
        changed.insert(v);
        hl.paths[hl.path_of[v]].seg.update(hl.pos_of(v), delta);
      }
    } else {
      if (hl.query(v).minv <= 0LL) printf("black\n");
      else printf("white\n");
    }
  }

  return 0;
}