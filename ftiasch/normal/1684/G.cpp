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

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-4448Z1gYUw7x3gi9.cpp"

#line 4 "/tmp/tmp-4448Z1gYUw7x3gi9.cpp"

struct Solver {
  Solver(int m_, std::vector<int> &&smalls_, std::vector<int> &&bigs_)
      : m{m_}, smalls{std::move(smalls_)}, bigs{std::move(bigs_)},
        match(smalls.size(), -1), visited(bigs.size()) {}

  std::vector<std::pair<int, int>> solve() {
    for (int u = 0; u < bigs.size(); ++u) {
      if (!find(u)) {
        return {};
      }
      std::fill(ALL(visited), false);
    }
    std::vector<std::pair<int, int>> plan;
    for (int v = 0; v < smalls.size(); ++v) {
      int u = match[v];
      if (~u) {
        plan.emplace_back(2 * bigs[u] + smalls[v], bigs[u] + smalls[v]);
      } else {
        plan.emplace_back(3 * smalls[v], 2 * smalls[v]);
      }
    }
    return plan;
  }

  bool find(int u) {
    if (visited[u]) {
      return false;
    }
    visited[u] = true;
    for (int v = 0; v < smalls.size(); ++v) {
      if ((2LL * bigs[u] + smalls[v] <= m && bigs[u] % smalls[v] == 0) &&
          (!~match[v] || find(match[v]))) {
        match[v] = u;
        return true;
      }
    }
    return false;
  }

  int m;
  std::vector<int> smalls, bigs, match;
  std::vector<bool> visited;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int m = read();
  std::vector<int> smalls, bigs;
  for (int a : read_vector(n)) {
    (a <= m / 3 ? smalls : bigs).push_back(a);
  }
  auto plan = Solver{m, std::move(smalls), std::move(bigs)}.solve();
  if (plan.empty()) {
    std::cout << "-1\n";
  } else {
    std::cout << plan.size() << "\n";
    for (auto [a, b] : plan) {
      std::cout << a << " " << b << "\n";
    }
  }
}