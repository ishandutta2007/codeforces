#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;
const int M = 100'000;

int degree[N + N], match[N + N][N];

int main() {
  int a, b, m;
  scanf("%d%d%d", &a, &b, &m);
  int n = a + b;
  std::vector<std::pair<int, int>> edges(m);
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    u--;
    v = v - 1 + a;
    edges[i] = {u, v};
    degree[u]++;
    degree[v]++;
  }
  int result = *std::max_element(degree, degree + n);
  memset(match, -1, sizeof(match));
  for (auto [u, v] : edges) {
    int x = 0, y = 0;
    while (~match[u][x]) {
      x++;
    }
    while (~match[v][y]) {
      y++;
    }
    match[u][x] = v;
    match[v][y] = u;
    if (x != y) {
      while (~v) {
        std::swap(match[v][x], match[v][y]);
        v = match[v][y];
        std::swap(x, y);
      }
    }
  }
  printf("%d\n", result);
  for (auto [u, v] : edges) {
    int c = 0;
    while (match[u][c] != v) {
      c++;
    }
    printf("%d ", c + 1);
  }
}