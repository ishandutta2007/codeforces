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
#line 2 "/tmp/tmp-311455EEMZ3exPrM2R.cpp"

#line 4 "/tmp/tmp-311455EEMZ3exPrM2R.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    auto s = read<std::string>();
    int p = 0;
    while (p < n && s[p] - 'a' <= m) {
      p++;
    }
    if (p == n) {
      std::cout << std::string(n, 'a') << "\n";
    } else {
      std::vector<int> remap(26);
      std::iota(ALL(remap), 0);
      int pm = 0;
      for (int i = 0; i < p; ++i) {
        pm = std::max(pm, s[i] - 'a');
      }
      for (int i = 0; i <= pm; ++i) {
        remap[i] = 0;
      }
      m -= pm;
      int h = s[p] - 'a';
      for (int i = h; i >= h - m; --i) {
        remap[i] = h - m;
      }
      for (int i = 0; i < n; ++i) {
        s[i] = 'a' + remap[s[i] - 'a'];
      }
      std::cout << s << "\n";
    }
  }
}