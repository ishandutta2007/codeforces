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
#line 2 "/tmp/tmp-330131VHztoPVNq1Ht.cpp"

#line 4 "/tmp/tmp-330131VHztoPVNq1Ht.cpp"

struct Solver {
  Solver(int p)
      : k(p), n(1 << p), head(n, -1), to(n << 1), next(n << 1), vlabel(n),
        elabel(n - 1) {
    for (int i = 0; i < (n - 1) << 1; ++i) {
      to[i] = read() - 1;
    }
    for (int i = 0; i < (n - 1) << 1; ++i) {
      next[i] = head[to[i ^ 1]];
      head[to[i ^ 1]] = i;
    }
    vlabel[0] = 1 << k;
    dfs(0, -1, 0, 1);
  }

  void dfs(int &&count, int p, int u, int parity) {
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
      int v = to[iterator];
      if (v != p) {
        count++;
        if (parity) {
          elabel[iterator >> 1] = 1 << k | count;
          vlabel[v] = count;
        } else {
          elabel[iterator >> 1] = count;
          vlabel[v] = 1 << k | count;
        }
        dfs(std::move(count), u, v, parity ^ 1);
      }
    }
  }

  void output() const {
    std::cout << 1 << "\n";
    for (int i = 0; i < n; ++i) {
      std::cout << vlabel[i] << " \n"[i + 1 == n];
    }
    for (int i = 0; i < n - 1; ++i) {
      std::cout << elabel[i] << " \n"[i + 2 == n];
    }
  }

  int k, n;
  std::vector<int> head, to, next, vlabel, elabel;
};

int main() {
  std::ios::sync_with_stdio(false);
  for (int T = read(); T--;) {
    int p = read();
    Solver{p}.output();
  }
}