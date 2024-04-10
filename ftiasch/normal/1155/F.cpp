#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 14;

using Pair = std::pair<int, int>;

void update(Pair &x, Pair a) { x = ~x.first ? std::min(x, a) : a; }

int n, m, popcount[1 << N];
bool graph[N][N];
int path[N][1 << N][N];
std::pair<int, int> bcc[1 << N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a][b] = graph[b][a] = true;
  }
  for (int mask = 0; mask < 1 << n; ++mask) {
    popcount[mask] = __builtin_popcount(mask);
  }
  memset(path, -1, sizeof(path));
  for (int s = 0; s < n; ++s) {
    // path[s][1 << s][s] = n;
    for (int u = 0; u < n; ++u) {
      if (graph[s][u]) {
        path[s][1 << u][u] = s;
      }
    }
    for (int mask = 0; mask < 1 << n; ++mask) {
      for (int u = 0; u < n; ++u) {
        if ((mask >> u & 1) && ~path[s][mask][u]) {
          for (int v = 0; v < n; ++v) {
            if (graph[u][v] && (~mask >> v & 1)) {
              path[s][mask | 1 << v][v] = u;
              if (popcount[mask] > 1 || s != v) {
                path[s][mask][v] = u;
              }
            }
          }
        }
      }
    }
  }
  memset(bcc, -1, sizeof(bcc));
  bcc[1] = {0, 0};
  int full = ((1 << n) - 1);
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (~bcc[mask].first) {
      int comp = full ^ mask;
      for (int s = 0; s < n; ++s) {
        if (mask >> s & 1) {
          for (int sub = comp; sub > 0; sub = (sub - 1) & comp) {
            for (int t = s; t < n; ++t) {
              if ((mask >> t & 1) && ~path[s][sub][t]) {
                update(bcc[mask | sub], {bcc[mask].first + 1 + popcount[sub],
                                         (s * n + t) << n | sub});
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n", bcc[full].first);
  int mask = full;
  while (true) {
    int plan = bcc[mask].second;
    if (!plan) {
      break;
    }
    int sub = plan & full;
    int t = (plan >> n) % n;
    int s = (plan >> n) / n;
    int v = path[s][sub][t];
    int pmask = sub;
    printf("%d %d\n", v + 1, t + 1);
    while (v != s) {
      int u = path[s][pmask][v];
      printf("%d %d\n", u + 1, v + 1);
      pmask ^= 1 << v;
      v = u;
    }
    mask ^= sub;
  }
}