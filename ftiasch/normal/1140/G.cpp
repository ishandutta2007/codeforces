#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;
using Cost2 = std::array<Long, 2>;

const int N = 300'000;
const int D = 19;

int n, depth[N], jump[D][N], order[N];
Long scost[N], down[N];
std::vector<std::pair<int, Cost2>> tree[N];

void prepare(int &&clock, int p, int u) {
  depth[u] = ~p ? depth[p] + 1 : 0;
  jump[0][u] = p;
  order[clock++] = u;
  down[u] = scost[u];
  for (auto &&[v, w] : tree[u]) {
    if (v != p) {
      prepare(std::move(clock), u, v);
      down[u] = std::min(down[u], down[v] + w[0] + w[1]);
    }
  }
}

using Stat = std::array<std::array<Long, 2>, 2>;

Stat merge(const Stat &p, const Stat &q) {
  Stat r;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      r[i][j] = std::min(p[i][0] + q[0][j], p[i][1] + q[1][j]);
    }
  }
  return r;
}

Stat reverse(const Stat &p) {
  Stat r;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      r[i][j] = p[j][i];
    }
  }
  return r;
}

int get_lca(int u, int v) {
  if (depth[u] > depth[v]) {
    std::swap(u, v);
  }
  for (int i = D; i--;) {
    if ((depth[v] - depth[u]) >> i & 1) {
      v = jump[i][v];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = D; i--;) {
    if (jump[i][u] != jump[i][v]) {
      u = jump[i][u];
      v = jump[i][v];
    }
  }
  return jump[0][u];
}

Stat stat[D][N];

Stat get_stat(int u, int d) {
  Stat result;
  result[0][0] = result[1][1] = 0;
  result[0][1] = result[1][0] = scost[u];
  for (int i = D; i--;) {
    if (d >> i & 1) {
      result = merge(result, stat[i][u]);
      u = jump[i][u];
    }
  }
  return result;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", scost + i);
  }
  for (int i = 0, a, b; i < n - 1; ++i) {
    Cost2 c;
    scanf("%d%d%lld%lld", &a, &b, &c[0], &c[1]);
    a--;
    b--;
    tree[a].emplace_back(b, c);
    tree[b].emplace_back(a, c);
  }
  memset(jump, -1, sizeof(jump));
  prepare(0, -1, 0);
  scost[0] = down[0];
  for (int i = 0; i < n; ++i) {
    int u = order[i];
    int p = jump[0][u];
    for (auto &&[v, w] : tree[u]) {
      if (v != p) {
        scost[v] = std::min(down[v], scost[u] + w[0] + w[1]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int u = order[i];
    int p = jump[0][u];
    for (auto &&[v, w] : tree[u]) {
      if (v != p) {
        // from v to u
        stat[0][v][0][0] = std::min(w[0], scost[u] + w[1] + scost[v]);
        stat[0][v][1][1] = std::min(w[1], scost[u] + w[0] + scost[v]);
        stat[0][v][0][1] = std::min(w[0] + scost[u], scost[v] + w[1]);
        stat[0][v][1][0] = std::min(w[1] + scost[u], scost[v] + w[0]);
      }
    }
  }
  for (int d = 1; d < D; ++d) {
    for (int u = 0; u < n; ++u) {
      if (depth[u] >= (1 << d)) {
        int v = jump[d - 1][u];
        jump[d][u] = jump[d - 1][v];
        stat[d][u] = merge(stat[d - 1][u], stat[d - 1][v]);
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    int z = get_lca(x >> 1, y >> 1);
    Stat stat_x = get_stat(x >> 1, depth[x >> 1] - depth[z]);
    Stat stat_y = reverse(get_stat(y >> 1, depth[y >> 1] - depth[z]));
    Stat sum = merge(stat_x, stat_y);
    printf("%lld\n", sum[x & 1][y & 1]);
  }
}