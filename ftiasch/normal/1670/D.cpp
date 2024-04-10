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
#line 2 "/tmp/tmp-330131MPWqwEiUvNft.cpp"

#line 4 "/tmp/tmp-330131MPWqwEiUvNft.cpp"

Long solve(int n) {
  int x = n / 3 + (n % 3 > 0);
  int y = n / 3 + (n % 3 > 1);
  int z = n / 3;
  return 2 * (1LL * x * y + 1LL * y * z + 1LL * z * x);
}

int main() {
  std::ios::sync_with_stdio(false);
  for (int T = read(); T--;) {
    int n = read();
    int low = 0;
    int high = 1e5;
    while (low < high) {
      int middle = (low + high) >> 1;
      if (solve(middle) >= n) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    std::cout << high << "\n";
  }
}