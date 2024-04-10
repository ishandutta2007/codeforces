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

template <typename T> std::vector<int> discretize(const std::vector<T> &a) {
  auto values = a;
  std::sort(ALL(values));
  values.erase(std::unique(ALL(values)), values.end());
  std::vector<int> result(a.size());
  for (int i = 0; i < a.size(); ++i) {
    result[i] = std::lower_bound(ALL(values), a[i]) - values.begin();
  }
  return result;
}
#line 2 "/tmp/tmp-627077rAjO74Bu5iZY.cpp"

#line 4 "/tmp/tmp-627077rAjO74Bu5iZY.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    auto a = read_vector(n);
    auto b = read_vector(n);
    std::vector<std::tuple<int, int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = {a[i], b[i], i};
    }
    std::ranges::sort(v);
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      ok &= std::get<1>(v[i - 1]) <= std::get<1>(v[i]);
    }
    if (ok) {
      std::vector<int> rank(n);
      for (int i = 0; i < n; ++i) {
        rank[std::get<2>(v[i])] = i;
      }
      std::vector<std::pair<int, int>> plan;
      for (int s = 0; s < n; ++s) {
        if (~rank[s]) {
          std::vector<int> cycle;
          int u = s;
          do {
            cycle.push_back(u);
            int v = rank[u];
            rank[u] = -1;
            u = v;
          } while (u != s);
          for (int i = cycle.size(); i-- > 1;) {
            plan.emplace_back(cycle[i - 1], cycle[i]);
          }
        }
      }
      std::cout << plan.size() << "\n";
      for (auto [x, y] : plan) {
        std::cout << x + 1 << " " << y + 1 << "\n";
      }
    } else {
      std::cout << -1 << "\n";
    }
  }
}