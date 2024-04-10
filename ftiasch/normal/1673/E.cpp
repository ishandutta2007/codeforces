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
#line 2 "/tmp/tmp-30989Bscm10Hnvjm5.cpp"

#line 4 "/tmp/tmp-30989Bscm10Hnvjm5.cpp"

const int N = 1 << 20;

int parity(int n, int k) { return k & (n - k) ? 0 : 1; }

int sum_parity(int n, int k) {
  if (k > n) {
    return 0;
  }
  // 0 <= k <= n
  if (n == 0) {
    return 1;
  }
  if (k == 0) {
    return 0;
  }
  return parity(n - 1, k - 1);
  //   // n > 0 && k > 0
  //   int result = 0;
  //   for (int i = k; i <= n; ++i) {
  //     result ^= parity(n, i);
  //     // = parity(n - 1, i - 1) ^ parity(n - 1, i)
  //   }
  //   return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int m = read();
  auto b = read_vector(n);
  // (2^x) ^ (2^y) ^ (2^z) = 2^{x * 2^y * 2^z}
  std::vector<int> result(N);
  for (int i = 0; i < n; ++i) {
    int e = b[i];
    for (int j = i; j < n; ++j) {
      if (i < j) {
        if (b[j] >= 20 || ((N - 1) / e < (1 << b[j]))) {
          break;
        }
        e <<= b[j];
      }
      // [i, j + 1]
      int cuts = std::max(m - !!i - (j + 1 < n), 0);
      int gaps = std::max(i - 1, 0) + std::max(n - (j + 1) - 1, 0);
      result[e] ^= sum_parity(gaps, cuts);
    }
  }
  int len = N;
  while (len > 1 && !result[len - 1]) {
    len--;
  }
  for (int i = len; i--;) {
    std::cout << result[i];
  }
}