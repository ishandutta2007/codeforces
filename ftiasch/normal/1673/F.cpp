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
#line 2 "/tmp/tmp-30989UVw9otuZh7X1.cpp"

#line 4 "/tmp/tmp-30989UVw9otuZh7X1.cpp"

const int N = 32;

template <int i0> std::vector<int> gen(int k) {
  std::vector<int> result(1 << k);
  for (int j = 0; j < k; ++j) {
    std::copy(result.begin(), result.begin() + (1 << j),
              result.begin() + (1 << j));
    std::reverse(result.begin(), result.begin() + (1 << j));
    for (int i = 0; i < 1 << j; ++i) {
      result[i] ^= 1 << (i0 + (j << 1));
    }
  }
  return result;
}

int main() {
  auto xcode = gen<0>(5);
  auto ycode = gen<1>(5);
  std::vector<std::pair<int, int>> remap(1 << 10, {-1, -1});
  for (int i = 0; i < 32; ++i) {
    for (int j = 0; j < 32; ++j) {
      int h = xcode[i] ^ ycode[j];
      assert(!~remap[h].first);
      remap[xcode[i] ^ ycode[j]] = {i, j};
    }
  }
  int n = read();
  int q = read();
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      int d = ycode[j - 1] ^ ycode[j];
      std::cout << d << " \n"[j + 1 == n];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int d = xcode[i - 1] ^ xcode[i];
      std::cout << d << " \n"[j + 1 == n];
    }
  }
  std::cout << std::flush;
  int tracker = xcode[0] ^ ycode[0];
  while (q--) {
    tracker ^= read();
    auto [x, y] = remap[tracker];
    std::cout << x + 1 << " " << y + 1 << std::endl;
  }
}