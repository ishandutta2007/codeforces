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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

struct Edge {
  int a, b, c;
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<Edge> edges(m);
  std::vector<int> events{0, 400'000'004};
  for (int i = 0, a, b, c; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    edges[i] = {a - 1, b - 1, c << 2};
    events.push_back(c);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      events.push_back((edges[i].c + edges[j].c) >> 1);
    }
  }
  std::sort(events.begin(), events.end());
  events.erase(std::unique(events.begin(), events.end()), events.end());
  std::vector<std::pair<int, long long>> stat(events.size());
  for (int i = 0; i + 1 < static_cast<int>(events.size()); ++i) {
    int x = (events[i] + events[i + 1]) >> 1;
    std::sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b) {
      return std::abs(a.c - x) < std::abs(b.c - x);
    });
    DSU dsu(n);
    int coef = 0;
    long long delta = 0;
    for (int i = 0; i < m; ++i) {
      int a = edges[i].a;
      int b = edges[i].b;
      if (dsu.merge(a, b)) {
        if (x < edges[i].c) {
          coef -= 1;
          delta += edges[i].c;
        } else {
          coef += 1;
          delta -= edges[i].c;
        }
      }
    }
    stat[i] = {coef, delta};
  }
  int p, k, a, b, c;
  scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);
  long long result = 0;
  for (int i = 0, q; i < k; ++i) {
    if (i < p) {
      scanf("%d", &q);
    } else {
      q = (1LL * q * a + b) % c;
    }
    auto &s = stat[static_cast<int>(
                       std::upper_bound(events.begin(), events.end(), q << 2) -
                       events.begin()) -
                   1];
    long long result_i = 1LL * s.first * (q << 2) + s.second;
    // printf("%lld\n", result_i);
    result ^= result_i >> 2;
  }
  printf("%lld\n", result);
}