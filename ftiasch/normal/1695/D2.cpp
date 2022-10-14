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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "sol.cpp"

struct Solver {
  Solver(int n) : n(n), tree(n) {}

  int solve() {
    if (n == 1) {
      return 0;
    }
    int r = 0;
    while (r < n && tree[r].size() < 3) {
      r++;
    }
    if (r == n) {
      return 1;
    }
    return dfs(-1, r);
  }

  int dfs(int p, int u) {
    int count1 = 0, dp = 0;
    for (int v : tree[u]) {
      if (v != p) {
        auto dp_v = dfs(u, v);
        if (dp_v) {
          dp += dp_v;
        } else {
          count1++;
        }
      }
    }
    return dp + std::max(count1 - 1, 0);
  }

  int n;
  std::vector<std::vector<int>> tree;
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    Solver solver(n);
    for (int i = 0; i < n - 1; ++i) {
      int a = io.read() - 1;
      int b = io.read() - 1;
      solver.tree[a].push_back(b);
      solver.tree[b].push_back(a);
    }
    std::cout << solver.solve() << "\n";
  }
}