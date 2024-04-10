#include <bits/stdc++.h>

namespace {

static const int N = 300000 + 1;
static const int D = 20;

int gold[N], cost[N], parent[N][D];

} // namespace

int main() {
  int q;
  scanf("%d%d%d", &q, gold, cost);
  memset(parent, -1, sizeof(parent));
  for (int i = 1; i <= q; ++i) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", parent[i], gold + i, cost + i);
      for (int j = 0; ~parent[i][j]; ++j) {
        parent[i][j + 1] = parent[parent[i][j]][j];
      }
    } else {
      int v, w;
      scanf("%d%d", &v, &w);
      int g = 0;
      long long c = 0;
      while (gold[v] > 0 && w > 0) {
        int vv = v;
        for (int j = D; j--;) {
          if (~parent[vv][j] && gold[parent[vv][j]] > 0) {
            vv = parent[vv][j];
          }
        }
        int tmp = std::min(gold[vv], w);
        gold[vv] -= tmp;
        w -= tmp;
        g += tmp;
        c += 1LL * tmp * cost[vv];
      }
      printf("%d %lld\n", g, c);
      fflush(stdout);
    }
  }
}