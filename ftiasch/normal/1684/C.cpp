#line 1 "util.h"
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
#line 2 "/tmp/tmp-696031IobepeaRlWM0.cpp"

#line 4 "/tmp/tmp-696031IobepeaRlWM0.cpp"

using Plan = std::pair<int, int>;

Plan solve(int n, int m, Vector2D<int> a) {
  Plan candidate{0, 0};
  for (const auto &row : a) {
    auto sorted_row = row;
    std::ranges::sort(sorted_row);
    std::vector<int> diffs;
    for (int i = 0; i < m; ++i) {
      if (row[i] != sorted_row[i]) {
        diffs.push_back(i);
      }
    }
    if (diffs.size() > 2) {
      return {-1, -1};
    }
    if (diffs.size() == 2) {
      Plan p{diffs[0], diffs[1]};
      if (candidate.first != candidate.second && candidate != p) {
        return {-1, -1};
      }
      candidate = p;
    }
  }
  auto [x, y] = candidate;
  for (auto &row : a) {
    std::swap(row[x], row[y]);
    for (int j = 1; j < m; ++j) {
      if (row[j - 1] > row[j]) {
        return {-1, -1};
      }
    }
  }
  return candidate;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    Vector2D<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = read_vector(m);
    }
    auto [i, j] = solve(n, m, std::move(a));
    if (~i) {
      std::cout << i + 1 << " " << j + 1 << "\n";
    } else {
      std::cout << "-1\n";
    }
  }
}