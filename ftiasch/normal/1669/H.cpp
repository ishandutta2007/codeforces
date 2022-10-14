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
#line 2 "/tmp/tmp-4448hoS3kxHLQmwY.cpp"

#line 4 "/tmp/tmp-4448hoS3kxHLQmwY.cpp"

const int K = 31;

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    std::vector<int> count(K, n);
    for (int a : read_vector(n)) {
      for (int i = 0; i < K; ++i) {
        count[i] -= a >> i & 1;
      }
    }
    int result = 0;
    for (int i = K; i--;) {
      if (count[i] <= m) {
        result |= 1 << i;
        m -= count[i];
      }
    }
    std::cout << result << "\n";
  }
}