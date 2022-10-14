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

int main() {
  int n;
  scanf("%d", &n);
  DSU dsu[]{DSU{n}, DSU{n}};
  for (int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    dsu[c].merge(a - 1, b - 1);
  }
  std::vector<int> size[2]{std::vector<int>(n), std::vector<int>(n)};
  for (int i = 0; i < n; ++i) {
    for (int t = 0; t < 2; ++t) {
      size[t][dsu[t].find(i)]++;
    }
  }
  long long result = 0;
  for (int u = 0; u < n; ++u) {
    int s[2];
    for (int t = 0; t < 2; ++t) {
      int fu = dsu[t].find(u);
      s[t] = size[t][fu];
      if (fu == u) {
          result += s[t] * (s[t] - 1LL);
      }
    }
    result += (s[0] - 1LL) * (s[1] - 1LL);
  }
  printf("%lld\n", result);
}