#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#include <vector>
#include <queue>

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

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-11630gs2T6Cv40IBk.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector(n);
    auto b = io.read_vector(n);
    int low = 0, high = 1'000'000'000;
    for (int i = 0; i < n; ++i) {
      if (a[i] < b[i]) {
        high = -1;
      } else {
        int d = a[i] - b[i];
        if (b[i] == 0) {
          low = std::max(low, d);
        } else {
          low = std::max(low, d);
          high = std::min(high, d);
        }
      }
    }
    std::cout << (low <= high ? "YES" : "NO") << "\n";
  }
}