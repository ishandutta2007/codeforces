#line 1 "/home/ftiasch/Documents/shoka/dsu.h"
#include <vector>

class DSU {
public:
  DSU(int n) : parent(n, -1) {}

  int find(int u) {
    if (!~parent[u]) {
      return u;
    }
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  bool merge(int a, int b) {
    if (find(a) == find(b)) {
      return false;
    }
    parent[find(a)] = find(b);
    return true;
  }

private:
  std::vector<int> parent;
};
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#line 3 "/home/ftiasch/Documents/shoka/util.h"
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
#line 3 "/tmp/tmp-116306SEIXsuf0ib4.cpp"

// #include "debug.h"

#include <bits/stdc++.h>

int main() {
  IO io;
  //    1 2 3 4 5 6 7 8 9  10 11 12 13 14 15 16
  // f  4 4 4 9 9 9 9 9 16 16 16 16 16 16 16 16
  // g  1 1 1 4 4 4 4 4 9  9  9  9  9  9  9  16
  //    Y Y N Y Y Y N N Y  Y  Y  Y  N  N  N  Y

  //    2Y1N 3Y2N 4Y3N 5Y4N
  //    Y: [x^2, x^2 + x]
  //    x = lfloor sqrt{a[i]} rfllor
  int n = io.read();
  auto a = io.read_vector(n);
  int m = a.back();
  a.insert(a.begin(), -m); // off by 1
  DSU dsu(n + 1);
  std::vector<std::pair<Long, Long>> bads;
  for (int x = 2; x < m; ++x) {
    Long r = 1LL * x * x;
    int length = x - 1;
    Long l = r - length;
    for (int j = n; j >= 1;) {
      int i = dsu.find(j);
      while (a[i] - a[i - 1] <= length) {
        dsu.merge(i, i - 1);
        i = dsu.find(i);
      }
      bads.emplace_back(l - a[j], r - a[i]);
      j = i - 1;
    }
  }
  std::ranges::sort(bads);
  Long result = 0;
  for (auto [l, r] : bads) {
    if (l <= result) {
      result = std::max(result, r);
    }
  }
  std::cout << result << "\n";
}