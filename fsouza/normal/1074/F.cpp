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

struct tree_t {
  int n;
  vector<vector<int>> adj;

  vector<int> invpreorder, preorder, endpreorder, depth;
  vector<vector<int>> parent;
  int ln;

  tree_t(int _n): n(_n), adj(n), invpreorder(n), endpreorder(n), depth(n),
                  parent(__lg(n) + 1, vector<int>(n)) {
    ln = __lg(n);
  }

  void dfs(int v, int p, int d) {
    parent[0][v] = p;
    for (int l = 1; l <= ln; ++l)
      parent[l][v] = parent[l - 1][parent[l - 1][v]];

    depth[v] = d;
    invpreorder[v] = preorder.size();
    preorder.push_back(v);
    for (int u : adj[v])
      if (u != p)
        dfs(u, v, d + 1);
    endpreorder[v] = preorder.size() - 1;
  }

  int climb(int v, int dist) const {
    for (int l = 0; l <= ln; ++l)
      if (dist & (1<<l))
        v = parent[l][v];
    return v;
  }

  void build() {
    dfs(0, 0, 0);
  }
};

struct segtree_t {
  int n;
  struct node_t {
    int lazy = 0;
    int result = 0;
  };
  vector<node_t> nodes;

  segtree_t(int _n): n(_n), nodes(4 * n) {}

  void update(int a, int b, int m) { update(a, b, m, 0, 0, n - 1); }

  void update(int a, int b, int mult, int v, int l, int r) {
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      nodes[v].lazy += mult;
      recalc(v, l, r);
    } else {
      int m = l + (r - l) / 2;
      update(a, b, mult, 2*v+1, l, m);
      update(a, b, mult, 2*v+2, m+1, r);
      recalc(v, l, r);
    }
  }

  void recalc(int v, int l, int r) {
    if (nodes[v].lazy > 0) {
      nodes[v].result = r - l + 1;
    } else {
      nodes[v].result = 0;
      if (l != r) {
        nodes[v].result += nodes[2 * v + 1].result;
        nodes[v].result += nodes[2 * v + 2].result;
      }
    }
  }
};

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  tree_t tree(n);
  tree.adj = adj;
  tree.build();

  segtree_t seg(n);

  vector<pair<int, int>> ranges;

  set<pair<int, int>> already;

  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;

    if (a > b) swap(a, b);

    const tree_t &t = tree;
    ranges.clear();
    if (t.invpreorder[a] <= t.invpreorder[b] &&
        t.invpreorder[b] <= t.endpreorder[a]) {
      int a2 = t.climb(b, t.depth[b] - t.depth[a] - 1);

      pair<int, int> k0 = make_pair(t.invpreorder[a2], t.endpreorder[a2]);
      pair<int, int> k1 = make_pair(t.invpreorder[b], t.endpreorder[b]);

      ranges.emplace_back(k0.first, k1.first - 1);
      ranges.emplace_back(k1.second + 1, k0.second);
    } else if (t.invpreorder[b] <= t.invpreorder[a] &&
               t.invpreorder[a] <= t.endpreorder[b]) {
      swap(a, b);

      int a2 = t.climb(b, t.depth[b] - t.depth[a] - 1);

      pair<int, int> k0 = make_pair(t.invpreorder[a2], t.endpreorder[a2]);
      pair<int, int> k1 = make_pair(t.invpreorder[b], t.endpreorder[b]);

      ranges.emplace_back(k0.first, k1.first - 1);
      ranges.emplace_back(k1.second + 1, k0.second);

      swap(a, b);
    } else {
      pair<int, int> k0 = make_pair(t.invpreorder[a], t.endpreorder[a]);
      pair<int, int> k1 = make_pair(t.invpreorder[b], t.endpreorder[b]);
      if (k0.first > k1.first) swap(k0, k1);
      ranges.emplace_back(0, k0.first - 1);
      ranges.emplace_back(k0.second + 1, k1.first - 1);
      ranges.emplace_back(k1.second + 1, n - 1);
    }

    if (a > b) swap(a, b);
    pair<int, int> ab = {a, b};
    int mult;
    if (already.insert(ab).second) {
      mult = 1;
    } else {
      already.erase(ab);
      mult = -1;
    }

    for (pair<int, int> range : ranges) {
      range.first = max(range.first, 0);
      range.second = min(range.second, n - 1);
      if (range.first <= range.second) {
        seg.update(range.first, range.second, mult);
      }
    }

    int forbid = seg.nodes[0].result;
    int result = n - forbid;
    printf("%d\n", result);
  }

  return 0;
}