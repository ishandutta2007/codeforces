#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-311455hHrvSAo73VJF.cpp"

#line 4 "/tmp/tmp-311455hHrvSAo73VJF.cpp"

struct Solver {
  Solver(int n) : has(n), depth(n), tree(n) {
    int m = read();
    int x = read() - 1;
    int y = read() - 1;
    has[y] = true;
    for (int i = 0; i < m; ++i) {
      has[read() - 1] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
      int a = read() - 1;
      int b = read() - 1;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    dfs(-1, x);
    result -= depth[y];
  }

  bool dfs(int p, int u) {
    bool h = has[u];
    depth[u] = ~p ? depth[p] + 1 : 0;
    for (int v : tree[u]) {
      if (v != p) {
        bool sh = dfs(u, v);
        if (sh) {
          result += 2;
        }
        h |= sh;
      }
    }
    return h;
  }

  int result = 0;
  std::vector<bool> has;
  std::vector<int> depth;
  std::vector<std::vector<int>> tree;
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::cout << Solver(n).result << "\n";
  }
}