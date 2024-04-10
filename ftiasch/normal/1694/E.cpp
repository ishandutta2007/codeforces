#line 1 "Documents/shoka/util.h"
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
#line 2 "/tmp/tmp-2623004wtd2kZtjh16.cpp"

int main() {
  IO io;
  int n = io.read();
  int m = io.read();
  std::vector<int> out(n), dp(n, INT_MAX);
  std::vector<std::vector<int>> bgraph(n);
  for (int i = 0; i < m; ++i) {
    int u = io.read() - 1;
    int v = io.read() - 1;
    out[u]++;
    bgraph[v].push_back(u);
  }
  MinPQ<std::pair<int, int>> pq;
  pq.emplace(dp[n - 1] = 0, n - 1);
  while (!pq.empty()) {
    auto [dp_u, u] = pq.top();
    pq.pop();
    if (dp_u == dp[u]) {
      for (auto v : bgraph[u]) {
        out[v]--;
        if (dp[v] > out[v] + 1 + dp[u]) {
          pq.emplace(dp[v] = out[v] + 1 + dp[u], v);
        }
      }
    }
  }
  std::cout << dp[0] << "\n";
}