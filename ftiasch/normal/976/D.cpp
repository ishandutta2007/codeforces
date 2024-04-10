#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> d(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
  }
  std::vector<std::pair<int, int>> edges;
  for (int i = 0; i <= n - 1 - i; ++i) {
    for (int u = d[i]; u < d[i + 1]; ++u) {
      for (int v = u + 1; v <= d[n - i]; ++v) {
        edges.emplace_back(u, v);
      }
    }
  }
  printf("%d\n", static_cast<int>(edges.size()));
  //   std::vector<int> deg(d[n] + 1);
  for (auto [a, b] : edges) {
    // deg[a]++;
    // deg[b]++;
    printf("%d %d\n", a + 1, b + 1);
  }
  //   std::cout << deg << std::endl;
}