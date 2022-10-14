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

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-169394a4juXBdKNLph.cpp"

#line 4 "/tmp/tmp-169394a4juXBdKNLph.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    auto a = read_vector<int>(n);
    std::vector<int> ones, twos;
    for (int i = 0; i < n; ++i) {
      (read() == 1 ? ones : twos).push_back(a[i]);
    }
    std::ranges::sort(ones, std::greater<int>());
    std::ranges::sort(twos, std::greater<int>());
    int result = INT_MAX;
    std::vector<Long> sum_twos(twos.size() + 1);
    for (int j = 0; j < twos.size(); ++j) {
      sum_twos[j + 1] = sum_twos[j] + twos[j];
    }
    Long sum_ones = 0;
    for (int i = 0, j = twos.size(); i <= ones.size(); ++i) {
      while (j && sum_ones + sum_twos[j - 1] >= m) {
        j--;
      }
      if (sum_ones + sum_twos[j] >= m) {
        result = std::min(result, i + 2 * j);
      }
      if (i < ones.size()) {
        sum_ones += ones[i];
      }
    }
    std::cout << (result < INT_MAX ? result : -1) << "\n";
  }
}