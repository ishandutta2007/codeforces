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
#line 2 "/tmp/tmp-311455bisnmutQcVZ2.cpp"

#line 4 "/tmp/tmp-311455bisnmutQcVZ2.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    auto s = read<std::string>();
    int n = s.size();
    std::vector<bool> all_zeros(n + 1);
    all_zeros[n] = true;
    for (int i = n; i--;) {
      all_zeros[i] = (s[i] != '1') && all_zeros[i + 1];
    }
    bool all_ones = true;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += all_ones && all_zeros[i + 1];
      all_ones &= s[i] != '0';
    }
    std::cout << result << "\n";
  }
}