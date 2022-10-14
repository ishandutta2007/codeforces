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
#line 2 "/tmp/tmp-4448HWcLsnd3sNNt.cpp"

#line 4 "/tmp/tmp-4448HWcLsnd3sNNt.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    auto a = read_vector(n);
    int result = 0;
    std::vector<int> prefix_sum(n + 1);
    for (int i = 0; i < n; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }
    int suffix_sum = 0;
    std::map<int, int> map;
    for (int i = n; i--;) {
      suffix_sum += a[i];
      map[suffix_sum] = n - i;
      auto iterator = map.find(prefix_sum[i]);
      if (iterator != map.end()) {
        result = std::max(result, i + iterator->second);
      }
    }
    std::cout << result << "\n";
  }
}