#include <bits/stdc++.h>

const int N = 300001;

int n, m, result, count[N], switches[N][2], parent[N << 1], size[N << 1];
char states[N];

int id(int c, int l) { return l + 1 << 1 | c; }

int findRoot(int u) {
  if (parent[u] != u) {
    parent[u] = findRoot(parent[u]);
  }
  return parent[u];
}

int cost(int u) { return u < 2 ? size[0] : std::min(size[u], size[u ^ 1]); }

void link(int u, int v) {
  u = findRoot(u), v = findRoot(v);
  if (u != v) {
    if (u < v) {
      std::swap(u, v);
    }
    result -= cost(u) + cost(v);
    parent[u] = v;
    parent[u ^ 1] = v ^ 1;
    size[v] += size[u];
    size[v ^ 1] += size[u ^ 1];
    result += cost(v);
  }
}

int main() {
  while (scanf("%d%d%s", &n, &m, states) == 3) {
    memset(count, 0, sizeof(*count) * n);
    for (int i = 0, c, x; i < m; ++i) {
      scanf("%d", &c);
      while (c--) {
        scanf("%d", &x);
        x--;
        switches[x][count[x]++] = i;
      }
    }
    int v = m + 1 << 1;
    std::iota(parent, parent + v, 0);
    for (int i = 0; i < v; ++i) {
      size[i] = i & 1;
    }
    result = 0;
    for (int i = 0; i < n; ++i) {
      int a = switches[i][0], b = switches[i][1], f = states[i] == '0';
      if (count[i] == 1) {
        link(id(0, a), f);
      } else if (count[i] == 2) {
        link(id(0, a), id(f, b));
      }
      printf("%d\n", result);
    }
  }
}