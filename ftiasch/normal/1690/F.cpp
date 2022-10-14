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
#line 2 "/tmp/tmp-116303XiNv763hn7n.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read<std::string>();
    auto p = io.read_vector(n);
    for (int i = 0; i < n; ++i) {
      p[i]--;
    }
    std::vector<bool> visited(n);
    Long lcm = 1;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        std::string t;
        int j = i;
        do {
          visited[j] = true;
          t += s[j];
          j = p[j];
        } while (j != i);
        int cycle = (t + t).find(t, 1);
        lcm = lcm / std::__gcd<Long>(lcm, cycle) * cycle;
      }
    }
    std::cout << lcm << "\n";
  }
}