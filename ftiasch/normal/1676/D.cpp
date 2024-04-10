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
#line 2 "/tmp/tmp-141040vgun02D0fvaE.cpp"

#line 4 "/tmp/tmp-141040vgun02D0fvaE.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    auto a = vector_2d<int>(n, m);
    std::vector<int> dsum(n + m - 1), adsum(n + m - 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = read();
        dsum[i + j] += a[i][j];
        adsum[i - j + m - 1] += a[i][j];
      }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        result = std::max(result, dsum[i + j] + adsum[i - j + m - 1] - a[i][j]);
      }
    }
    std::cout << result << "\n";
  }
}