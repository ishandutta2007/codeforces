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
#line 2 "/tmp/tmp-418190PeaXuNZVR7N.cpp"

#line 4 "/tmp/tmp-418190PeaXuNZVR7N.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = read() - 1;
    }
    std::vector<int> sum(n);
    Long result = 0;
    for (int b = 0; b < n; ++b) {
      std::ranges::fill(sum, 0);
      for (int a = 0; a < b; ++a) {
        sum[p[a]]++;
      }
      for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
      }
      int ac = 0;
      for (int d = b + 1; d < n; ++d) {
        if (p[b] > p[d]) {
          result += ac;
        }
        ac += sum[p[d]];
      }
    }
    std::cout << result << "\n";
  }
}