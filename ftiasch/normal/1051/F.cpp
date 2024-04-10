#line 1 "/home/ftiasch/Documents/shoka/dsu.h"
#include <vector>

class DSU {
public:
  DSU(int n) : parent(n, -1) {}

  int find(int u) {
    if (!~parent[u]) {
      return u;
    }
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  bool merge(int a, int b) {
    if (find(a) == find(b)) {
      return false;
    }
    parent[find(a)] = find(b);
    return true;
  }

private:
  std::vector<int> parent;
};
#line 1 "/home/ftiasch/Documents/shoka/heavy_light_decomp_base.h"
#include <algorithm>
#line 3 "/home/ftiasch/Documents/shoka/heavy_light_decomp_base.h"

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
#line 3 "sol.cpp"

#include <bits/stdc++.h>

using Long = long long;

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

const int N = 100'000;
const int K = 21;

int n, m, k, special_src[K];
Long special_dist[K][N], depth[N];
std::vector<std::pair<int, int>> tree[N], graph[N];

void sssp(Long *dist, int src) {
  std::fill(dist, dist + n, 1e14);
  dist[src] = 0;
  PQ<std::pair<Long, int>> pq;
  pq.emplace(0, src);
  while (!pq.empty()) {
    auto [dist_u, u] = pq.top();
    pq.pop();
    if (dist_u == dist[u]) {
      for (auto [v, w] : graph[u]) {
        if (dist[v] > dist[u] + w) {
          pq.emplace(dist[v] = dist[u] + w, v);
        }
      }
    }
  }
}

void prepare(int p, int u) {
  for (auto [v, w] : tree[u]) {
    if (v != p) {
      depth[v] = depth[u] + w;
      prepare(u, v);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  DSU dsu(n);
  std::vector<std::vector<int>> simp_tree(n);
  for (int i = 0, a, b, c; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
    if (dsu.merge(a, b)) {
      tree[a].emplace_back(b, c);
      tree[b].emplace_back(a, c);
      simp_tree[a].push_back(b);
      simp_tree[b].push_back(a);
    } else {
      special_src[k++] = a;
    }
  }
  for (int i = 0; i < k; ++i) {
    sssp(special_dist[i], special_src[i]);
  }
  prepare(-1, 0);
  HeavyLightDecompositionBase hld(simp_tree, 0);
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    int c = hld.lca(a, b);
    Long result = depth[a] + depth[b] - 2 * depth[c];
    for (int i = 0; i < k; ++i) {
      result = std::min(result, special_dist[i][a] + special_dist[i][b]);
    }
    printf("%lld\n", result);
  }
}