#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-882161LS4vf2jW2Vh9.cpp"

struct HeavyLightDecompositionBase {
  using Tree = std::vector<std::vector<int>>;

  HeavyLightDecompositionBase(const Tree &tree, int root)
      : n(tree.size()), parent(n), dfn(n), size(n), depth(n), top(n),
        bottom(n) {
    parent[root] = -1;
    build(tree, 0, root);
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

  int distance(int a, int b) const {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
  }

  int n;
  std::vector<int> parent, dfn, size, depth;

protected:
  void build(const Tree &tree, int &&clock, int u) {
    const int p = parent[u];
    dfn[u] = clock++;
    depth[u] = ~p ? depth[p] + 1 : 0;
    size[u] = 1;
    std::pair<int, int> candidate{0, u};
    for (int v : tree[u]) {
      if (v != p) {
        parent[v] = u;
        build(tree, std::move(clock), v);
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

int main() {
  IO io;
  int n = io.read();
  std::vector<std::vector<int>> tree(n);
  for (int i = 0; i < n - 1; ++i) {
    int a = io.read() - 1;
    int b = io.read() - 1;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  HeavyLightDecompositionBase hld(tree, 0);
  int q = io.read();
  while (q--) {
    int k = io.read();
    std::vector<int> order(k);
    for (int i = 0; i < k; ++i) {
      order[i] = io.read() - 1;
    }
    std::sort(order.begin(), order.end(),
              [&](int u, int v) { return hld.dfn[u] < hld.dfn[v]; });
    int st = hld.distance(order[0], order[k - 1]);
    for (int i = 1; i < k; ++i) {
      st += hld.distance(order[i - 1], order[i]);
    };
    auto find = [&](int u) {
      std::pair<int, int> best{0, u};
      for (int v : order) {
        best = std::max(best, {hld.distance(u, v), v});
      }
      return best;
    };
    std::cout << (find(find(order[0]).second).first * 2 == st ? "YES" : "NO")
              << "\n";
  }
}