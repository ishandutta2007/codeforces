#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, c[N], p[N], indeg[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", c + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
    p[i]--;
    indeg[p[i]]++;
  }
  std::queue<int> queue;
  for (int u = 0; u < n; ++u) {
    if (!indeg[u]) {
      queue.push(u);
    }
  }
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    c[u] = 0;
    indeg[p[u]]--;
    if (!indeg[p[u]]) {
      queue.push(p[u]);
    }
  }
  int result = 0;
  for (int u = 0; u < n; ++u) {
    if (c[u]) {
      int sub = c[u];
      int v = u;
      do {
        sub = std::min(sub, c[v]);
        c[v] = 0;
        v = p[v];
      } while (v != u);
      result += sub;
    }
  }
  printf("%d\n", result);
}