#line 2 "/home/ftiasch/Documents/shoka/io.h"

#include <cctype>
#include <cstdint>
#include <cstdio>

struct FastIn {
  FastIn(FILE *in_ = stdin) : in(in_) {}

  char next_char() {
    if (head == length) {
      head = 0;
      length = fread(buffer, 1, LENGTH, in);
    }
    return buffer[head++];
  }

  uint64_t next_uint() {
    char c = next_char();
    while (!std::isdigit(c)) {
      c = next_char();
    }
    uint64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10U + c - '0';
    }
    return x;
  }

  int64_t next_int() {
    char c = next_char();
    while (!std::isdigit(c) && c != '-') {
      c = next_char();
    }
    int64_t sign = 1;
    if (c == '-') {
      sign = -1;
      c = next_char();
    }
    int64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10 + c - '0';
    }
    return sign * x;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  size_t head = 0;
  size_t length = 0;
  FILE *in;
};
#line 2 "G_Common_Divisor_Graph.cpp"

#include <bits/stdc++.h>

struct DSU {
  DSU(int n) : parent(n) { std::iota(parent.begin(), parent.end(), 0); }

  DSU(const DSU &other) = default;

  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      parent[u] = v;
    }
  }

  std::vector<int> parent;
};

int main() {
  FastIn io;
  int n = io.next_uint();
  int q = io.next_uint();
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = io.next_uint();
  }
  int m = *std::max_element(a.begin(), a.end()) + 1;
  std::vector<int> min_div(m + 1, -1), primes;
  for (int d = 2; d <= m; ++d) {
    if (min_div[d] == -1) {
      min_div[d] = d;
      primes.push_back(d);
    }
    for (int p : primes) {
      if (d * p > m) {
        break;
      }
      min_div[p * d] = p;
      if (d % p == 0) {
        break;
      }
    }
  }
  DSU dsu(m + 1);
  for (int i = 0; i < n; ++i) {
    for (int d = a[i]; d > 1; d /= min_div[d]) {
      dsu.merge(a[i], min_div[d]);
    }
  }
  std::vector<std::vector<int>> new_edges(m + 1);
  for (int i = 0; i < n; ++i) {
    std::vector<int> components{dsu.find(a[i]), dsu.find(a[i] + 1)};
    for (int d = a[i] + 1; d > 1; d /= min_div[d]) {
      components.push_back(dsu.find(min_div[d]));
    }
    std::sort(components.begin(), components.end());
    components.erase(std::unique(components.begin(), components.end()),
                     components.end());
    for (int y : components) {
      for (int x : components) {
        new_edges[x].push_back(y);
        if (x == y) {
          break;
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    auto &v = new_edges[i];
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
  }
  while (q--) {
    int x = dsu.find(a[io.next_uint() - 1]);
    int y = dsu.find(a[io.next_uint() - 1]);
    if (x == y) {
      puts("0");
    } else {
      if (x > y) {
        std::swap(x, y);
      }
      auto &v = new_edges[x];
      auto iterator = std::lower_bound(v.begin(), v.end(), y);
      if (iterator != v.end() && *iterator == y) {
        puts("1");
      } else {
        puts("2");
      }
    }
  }
}