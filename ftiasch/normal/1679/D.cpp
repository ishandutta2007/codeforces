#line 1 "/tmp/tmp-51969i6hcMH7sclnH.cpp"
// #include "debug.h"
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
#line 3 "/tmp/tmp-51969i6hcMH7sclnH.cpp"

#line 5 "/tmp/tmp-51969i6hcMH7sclnH.cpp"

struct Solve {
  Solve(int n_) : n(n_), dp(n), graph(n) {
    int m = read();
    k = read<Long>();
    a = read_vector(n);
    for (int i = 0; i < m; ++i) {
      int u = read() - 1;
      int v = read() - 1;
      graph[u].push_back(v);
    }
    auto values = a;
    std::ranges::sort(values);
    values.erase(std::unique(values.begin(), values.end()), values.end());
    int l = 0;
    int r = values.size();
    while (l < r) {
      int m = (l + r) >> 1;
      if (work(values[m]) >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    result = r < values.size() ? values[r] : -1;
  }

  Long dfs(int limit, int u) {
    if (!~dp[u]) {
      dp[u] = 0;
      Long working_dp = 1;
      for (int v : graph[u]) {
        if (a[v] <= limit) {
          if (dp[v] == 0) {
            working_dp = k;
            break;
          }
          working_dp = std::max(working_dp, 1 + dfs(limit, v));
        }
      }
      dp[u] = working_dp;
    }
    return dp[u];
  }

  Long work(int limit) {
    std::ranges::fill(dp, -1);
    Long result = 0;
    for (int u = 0; u < n; ++u) {
      if (a[u] <= limit) {
        result = std::max(result, dfs(limit, u));
      }
    }
    // std::cerr << KV(limit) << KV(dp) << std::endl;
    return result;
  }

  int n, result;
  Long k;
  std::vector<int> a;
  std::vector<Long> dp;
  std::vector<std::vector<int>> graph;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  std::cout << Solve(n).result << "\n";
}