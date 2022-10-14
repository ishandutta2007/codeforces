#line 1 "/home/ftiasch/Documents/shoka/heavy_light_decomp_base.h"
#include <algorithm>
#include <vector>

struct HeavyLightDecompositionBase {
  using Tree = std::vector<std::vector<int>>;

  HeavyLightDecompositionBase(const Tree &tree, int root)
      : n(tree.size()), parent(n), size(n), depth(n), top(n), bottom(n) {
    parent[root] = -1;
    build(tree, root);
    for (int u = 0; u < n; ++u) {
      top[u] = top[bottom[u]];
    }
  }

  int lca(int a, int b) const {
    while (bottom[a] != bottom[b]) {
      if (get_lowest_depth(a) > get_lowest_depth(b)) {
        a = top[a];
      } else {
        b = top[b];
      }
    }
    return depth[a] < depth[b] ? a : b;
  }

  int n;
  std::vector<int> parent, size, depth;

protected:
  void build(const Tree &tree, int u) {
    const int p = parent[u];
    depth[u] = ~p ? depth[p] + 1 : 0;
    size[u] = 1;
    std::pair<int, int> candidate{0, u};
    for (int v : tree[u]) {
      if (v != p) {
        parent[v] = u;
        build(tree, v);
        size[u] += size[v];
        candidate = std::max(candidate, std::make_pair(size[v], bottom[v]));
      }
    }
    bottom[u] = candidate.second;
    top[bottom[u]] = p;
  }

  int get_lowest_depth(int u) const { return ~top[u] ? depth[top[u]] : -1; }

  std::vector<int> top, bottom;
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int N = 300'000;

int n, m, a[N];
long long down[N], sum_down[N], up[N], weight[N], sum_weight[N];
std::vector<std::pair<int, int>> tree[N];

void calc_down(int p, int u, int upw) {
  for (auto [v, w] : tree[u]) {
    if (v != p) {
      calc_down(u, v, w);
      weight[v] = a[v] + sum_down[v] - down[v] - w;
      sum_down[u] += down[v];
    }
  }
  down[u] = std::max(a[u] + sum_down[u] - 2 * upw, 0LL);
}

void calc_up(int p, int u) {
  for (auto [v, w] : tree[u]) {
    if (v != p) {
      sum_weight[v] = sum_weight[u] + weight[v];
      up[v] = std::max(a[u] + sum_down[u] - down[v] + up[u] - 2 * w, 0LL);
      calc_up(u, v);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::vector<std::vector<int>> simpl_tree(n);
  for (int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    tree[a].emplace_back(b, c);
    tree[b].emplace_back(a, c);
    simpl_tree[a].push_back(b);
    simpl_tree[b].push_back(a);
  }
  calc_down(-1, 0, 0);
  calc_up(-1, 0);
  HeavyLightDecompositionBase hld(simpl_tree, 0);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    int w = hld.lca(u, v);
    printf("%lld\n", sum_weight[u] - sum_weight[w] + sum_weight[v] -
                         sum_weight[w] + sum_down[w] + a[w] + up[w]);
  }
}