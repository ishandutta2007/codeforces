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
#line 2 "/tmp/tmp-565589jXihGx7BONKr.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
#line 4 "/tmp/tmp-565589jXihGx7BONKr.cpp"

const int M = 30;

bool connected(int n, const std::vector<int> &a) {
  DSU dsu(n + M);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < M; ++j) {
      if (a[i] >> j & 1) {
        dsu.merge(i, n + j);
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    if (dsu.find(0) != dsu.find(i)) {
      return false;
    }
  }
  return true;
}

int solve(int n, std::vector<int> &a) {
  int zeros = 0;
  for (int i = 0; i < n; ++i) {
    if (!a[i]) {
      zeros++;
      a[i]++;
    }
  }
  if (connected(n, a)) {
    return zeros;
  }
  for (int i = 0; i < n; ++i) {
    a[i]--;
    if (connected(n, a)) {
      return zeros + 1;
    }
    a[i] += 2;
    if (connected(n, a)) {
      return zeros + 1;
    }
    a[i]--;
  }
  int h = 0;
  for (int i = 0; i < n; ++i) {
    h = std::max(h, a[i] & -a[i]);
  }
  std::vector<int> highs;
  for (int i = 0; i < n; ++i) {
    if ((a[i] & -a[i]) == h) {
      highs.push_back(i);
    }
  }
  assert(highs.size() >= 2);
  a[highs[0]]--;
  a[highs[1]]++;
  return zeros + 2;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector(n);
    int result = solve(n, a);
    std::cout << result << "\n";
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << " \n"[i + 1 == n];
    }
  }
}