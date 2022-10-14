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

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-330131fHj0EUxV7Ja5.cpp"

#line 4 "/tmp/tmp-330131fHj0EUxV7Ja5.cpp"

struct Solver {
  Solver(int n) : indeg(n), outdeg(n), dp(n, -1), graph(n) {
    int m = read();
    while (m--) {
      int x = read() - 1;
      int y = read() - 1;
      outdeg[x]++;
      indeg[y]++;
      graph[x].push_back(y);
    }
    for (int u = 0; u < n; ++u) {
      dfs(u);
    }
  }

  void dfs(int u) {
    if (!~dp[u]) {
      dp[u] = 1;
      for (int v : graph[u]) {
        dfs(v);
        if (outdeg[u] != 1 && indeg[v] != 1) {
          dp[u] = std::max(dp[u], dp[v] + 1);
        }
      }
    }
  }

  int result() const { return *std::ranges::max_element(dp); }

  std::vector<int> indeg, outdeg, dp;
  std::vector<std::vector<int>> graph;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  std::cout << Solver(n).result() << "\n";
}