#line 1 "/home/ftiasch/Documents/shoka/nd_vector.h"
#include <vector>

template <typename T, int N> struct NDVector {
  using Nested = NDVector<T, N - 1>;
  using Vector = std::vector<typename Nested::Vector>;

  template <typename... Args> static Vector create(int n, Args &&...args) {
    return Vector(n, Nested::create(std::forward<Args>(args)...));
  }
};

template <typename T> struct NDVector<T, 1> {
  using Vector = std::vector<T>;

  template <typename... Args> static Vector create(Args &&...args) {
    return Vector(std::forward<Args>(args)...);
  }
};
#line 2 "/tmp/tmp-91229Mi7GAUf5xTYV.cpp"

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
#line 4 "/tmp/tmp-91229Mi7GAUf5xTYV.cpp"

int main() {
  IO io;
  int n = io.read();
  auto a = NDVector<int, 2>::create(2, n);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] += io.read();
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] -= io.read();
    }
  }
  if (std::accumulate(ALL(a[0]), 0) + std::accumulate(ALL(a[1]), 0) == 0) {
    int sum[]{0, 0};
    Long result = 0;
    for (int i = 0; i < n; ++i) {
      sum[0] += a[0][i];
      sum[1] += a[1][i];
      if ((sum[0] > 0) ^ (sum[1] > 0)) {
        int t = sum[1] > 0;
        Long d = std::min(sum[t], -sum[t ^ 1]);
        result += d;
        sum[t] -= d;
        sum[t ^ 1] += d;
      }
      result += std::abs(sum[0]) + std::abs(sum[1]);
    }
    std::cout << result << "\n";
  } else {
    std::cout << -1 << "\n";
  }
}