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
#line 2 "/tmp/tmp-330131Pyi3aNtdepf2.cpp"

#line 4 "/tmp/tmp-330131Pyi3aNtdepf2.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int m = read();
  int q = read();
  auto buffer = read_vector<std::string>(n);
  std::vector<int> a(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i + j * n] = buffer[i][j] == '*';
    }
  }
  int ones = std::accumulate(ALL(a), 0);
  int sum = std::count(a.begin(), a.begin() + ones, 0);
  while (q--) {
    int x = read() - 1;
    int y = read() - 1;
    int i = x + y * n;
    if (i < ones) {
      if (a[i]) {
        sum++;
      } else {
        sum--;
      }
    }
    a[i] ^= 1;
    if (a[i]) {
      // 0->1
      if (!a[ones]) {
        sum++;
      }
      ones++;
    } else {
      ones--;
      if (!a[ones]) {
        sum--;
      }
    }
    std::cout << sum << "\n";
  }
}