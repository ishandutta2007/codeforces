#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int M = 1 << 14;

char buffer[(M >> 2) + 1];
bool grid[M];
int parent[M + M];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    return false;
  }
  parent[u] = v;
  return true;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int result = 0;
  memset(parent, -1, sizeof(parent));
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    for (int j = 0; j < (m >> 2); ++j) {
      int value =
          std::isdigit(buffer[j]) ? buffer[j] - '0' : 10 + (buffer[j] - 'A');
      for (int k = 0; k < 4; ++k) {
        grid[j << 2 | k] = value >> (3 - k) & 1;
      }
    }
    for (int j = 0; j < m; ++j) {
      if (grid[j]) {
        result++;
        parent[m + j] = m + j;
        if (~parent[j]) {
          result -= merge(j, m + j);
        }
        if (j && grid[j - 1]) {
          result -= merge(m + j - 1, m + j);
        }
      } else {
        parent[m + j] = -1;
      }
    }
    for (int j = 0; j < m; ++j) {
      parent[j] = ~parent[m + j] ? parent[m + j] - m : -1;
    }
  }
  printf("%d\n", result);
}