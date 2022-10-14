#line 2 "/home/ftiasch/Documents/shoka/sparse_table.h"

#include <algorithm>
#include <cstring>

template <typename T, int N> struct SparseTable {
  SparseTable() {
    log[0] = 0;
    for (int i = 1; i < N; ++i) {
      log[i] = log[i - 1] + (1 << (log[i - 1] + 1) < i + 1);
    }
  }

  void initialize(int n, const T *value) {
    l = log2n(n), memcpy(table[0], value, sizeof(T) * n);
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        table[i][j] =
            std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T operator()(int l, int r) const {
    const int lv = log[r - l];
    return std::min(table[lv][l], table[lv][r - (1 << lv) + 1]);
  }

private:
  static constexpr int log2n(int n) {
    return n > 1 ? 32 - __builtin_clz(n - 1) : 1;
  }

  static const int L = log2n(N);

  int l, log[N];
  T table[L][N];
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

struct DSU {
  DSU(int n) : parent(n), ends(n) {
    std::iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < n; ++i) {
      ends[i] = {i, i};
    }
  }

  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  std::pair<int, int> merge(int ra, int rb) {
    auto [p, q] = ends[ra];
    auto [r, s] = ends[rb];
    parent[rb] = ra;
    ends[ra] = {p, s};
    return {q, r};
  }

  std::vector<int> parent;
  std::vector<std::pair<int, int>> ends;
};

SparseTable<int, 200'000> rmq;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(m), b(m), c(m);
  std::vector<std::pair<int, int>> order(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    a[i]--;
    b[i]--;
    order[i] = {c[i], i};
  }
  std::sort(order.begin(), order.end());
  DSU dsu(n);
  std::vector<bool> in_tree(m);
  std::vector<std::pair<int, int>> next(n);
  long long mst = 0;
  for (auto [w, i] : order) {
    int ra = dsu.find(a[i]);
    int rb = dsu.find(b[i]);
    in_tree[i] = ra != rb;
    if (in_tree[i]) {
      mst += w;
      auto [u, v] = dsu.merge(ra, rb);
      next[u] = {v, w};
    }
  }
  std::vector<int> position(n), weight(n - 1);
  {
    int u = dsu.ends[dsu.find(0)].first;
    position[u] = 0;
    for (int i = 0; i < n - 1; ++i) {
      auto [v, w] = next[u];
      position[v] = i + 1;
      weight[i] = -w;
      u = v;
    }
  }
  rmq.initialize(n - 1, weight.data());
  for (int i = 0; i < m; ++i) {
    if (in_tree[i]) {
      printf("%lld\n", mst);
    } else {
      int x = position[a[i]];
      int y = position[b[i]];
      if (x > y) {
        std::swap(x, y);
      }
      printf("%lld\n", mst + rmq(x, y - 1) + c[i]);
    }
  }
}