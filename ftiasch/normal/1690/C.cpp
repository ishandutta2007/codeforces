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
#line 2 "/tmp/tmp-11630TlynThC3NIuZ.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read_vector(n);
    auto t = io.read_vector(n);
    std::vector<int> result(n);
    int prefix_max = 0;
    for (int i = 0; i < n; ++i) {
      result[i] = t[i] - std::max(prefix_max, s[i]);
      prefix_max = t[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cout << result[i] << " \n"[i + 1 == n];
    }
  }
}