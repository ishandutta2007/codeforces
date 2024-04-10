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
#line 2 "/tmp/tmp-696031BW5BtPXpoFOu.cpp"

#line 4 "/tmp/tmp-696031BW5BtPXpoFOu.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    auto a = read_vector(n);
    Long sum = std::accumulate(ALL(a), 0LL);
    std::vector<Long> candidates(n);
    for (int i = 0; i < n; ++i) {
      candidates[i] = -a[i] + (n - 1 - i);
    }
    std::ranges::sort(candidates);
    Long result = sum;
    for (int i = 1; i <= m; ++i) {
      sum += candidates[i - 1];
      result = std::min(result, sum - i * (i - 1LL) / 2);
    }
    std::cout << result << "\n";
  }
}