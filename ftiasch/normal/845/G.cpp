#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

struct LinearBasis {
  static const int B = 30;

  LinearBasis() { memset(basis, -1, sizeof(basis)); }

  void add(int v) {
    v = ask(v);
    if (v) {
      int pivot = 31 - __builtin_clz(v);
      for (int i = 0; i < B; ++i) {
        if (~basis[i] && (basis[i] >> pivot & 1)) {
          basis[i] ^= v;
        }
      }
      basis[pivot] = v;
    }
  }

  int ask(int v) const {
    for (int i = B; i--;) {
      if ((v >> i & 1) && ~basis[i]) {
        v ^= basis[i];
      }
    }
    return v;
  }

  int basis[B];
} basis;

int n, m, head[N], to[N << 1], weight[N], next[N << 1], depth[N];
bool used[N];

void dfs(int u) {
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      int v = to[iterator];
      int w = weight[iterator >> 1];
      if (~depth[v]) {
        basis.add(depth[u] ^ depth[v] ^ w);
      } else {
        depth[v] = depth[u] ^ w;
        dfs(v);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
    if (i & 1) {
      scanf("%d", weight + (i >> 1));
    }
  }
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  memset(depth, -1, sizeof(depth));
  depth[0] = 0;
  dfs(0);
  printf("%d\n", basis.ask(depth[n - 1]));
}