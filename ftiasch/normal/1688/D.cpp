#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::cin.sync_with_stdio(false); }

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
};
#line 2 "/tmp/tmp-478690xSWtOcfpRMr3.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int k = io.read();
    auto a = io.read_vector(n);
    std::vector<Long> sum(n + 1);
    for (int i = n; i--;) {
      sum[i] = a[i] + sum[i + 1];
    }
    int l = std::min(n, k);
    Long result = 0;
    Long extra = ((k - l) + (k - 1LL)) * l / 2;
    for (int i = 0; i + l <= n; ++i) {
      result = std::max(result, sum[i] - sum[i + l] + extra);
    }
    std::cout << result << "\n";
  }
}