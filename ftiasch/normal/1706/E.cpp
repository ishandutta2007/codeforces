#line 2 "sparse_table.h"

#include <cstring>
#include <functional>
#include <vector>

template <typename T, typename Compare = std::less<T>> struct SparseTable {
  explicit SparseTable(const std::vector<T> &value)
      : n(value.size()), l(log2n(n)), log(n), table(l, std::vector<T>(n)) {
    log[0] = 0;
    for (int i = 1; i < n; ++i) {
      log[i] = log[i - 1] + (1 << (log[i - 1] + 1) < i + 1);
    }
    table[0] = value;
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T operator()(int l, int r) const {
    const int lv = log[r - l];
    return min(table[lv][l], table[lv][r - (1 << lv) + 1]);
  }

private:
  static constexpr int log2n(int n) {
    return n > 1 ? 32 - __builtin_clz(n - 1) : 1;
  }

  static T min(const T &a, const T &b) {
    static Compare compare;
    return compare(a, b) ? a : b;
  }

  int n, l;
  std::vector<int> log;
  std::vector<std::vector<T>> table;
};
#line 2 "/tmp/tmp-900709UZJ9iVKoco2e.cpp"

#line 1 "util.h"
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
#line 4 "/tmp/tmp-900709UZJ9iVKoco2e.cpp"

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

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    int q = io.read();
    DSU dsu(n);
    std::vector<std::pair<int, int>> next(n);
    for (int i = 1; i <= m; ++i) {
      int a = io.read() - 1;
      int b = io.read() - 1;
      int ra = dsu.find(a);
      int rb = dsu.find(b);
      if (ra != rb) {
        auto [u, v] = dsu.merge(ra, rb);
        next[u] = {v, i};
      }
    }
    std::vector<int> position(n), weight(n - 1);
    {
      int u = dsu.ends[dsu.find(0)].first;
      position[u] = 0;
      for (int i = 0; i < n - 1; ++i) {
        auto [v, w] = next[u];
        position[v] = i + 1;
        weight[i] = w;
        u = v;
      }
    }
    SparseTable<int> pmin_rmq(position);
    SparseTable<int, std::greater<int>> pmax_rmq(position), wrmq(weight);
    while (q--) {
      int l = io.read() - 1;
      int r = io.read() - 1;
      int pmin = pmin_rmq(l, r);
      int pmax = pmax_rmq(l, r);
      int result = 0;
      if (pmin < pmax) {
        result = wrmq(pmin, pmax - 1);
      }
      std::cout << result << " \n"[q == 0];
    }
  }
}