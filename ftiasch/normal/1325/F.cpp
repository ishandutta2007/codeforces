#include <bits/stdc++.h>

const int N = 100000;
const int M = 200000;

int n, m, bound, head[N], to[M << 1], next[M << 1], parent[N], depth[N];
bool used[M], removed[N];

void dfs(int u) {
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      int v = to[iterator ^ 1];
      if (~depth[v]) {
        if (depth[u] - depth[v] >= bound - 1) {
          printf("2\n%d\n%d", depth[u] - depth[v] + 1, v + 1);
          while (u != v) {
            printf(" %d", u + 1);
            u = parent[u];
          }
          puts("");
          exit(0);
        }
      } else {
        parent[v] = u, depth[v] = depth[u] + 1;
        dfs(v);
      }
    }
  }
  if (!removed[u]) {
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
      int v = to[iterator ^ 1];
      if (depth[v] < depth[u]) {
        removed[v] = true;
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    next[i] = head[--to[i]];
    head[to[i]] = i;
  }
  bound = 0;
  while (bound * bound < n) {
    bound++;
  }
  memset(depth, -1, sizeof(depth));
  parent[0] = -1, depth[0] = 0;
  dfs(0);
  puts("1");
  for (int i = 0; i < n; ++i) {
    if (!removed[i]) {
      printf("%d ", i + 1);
      if (!--bound) {
        break;
      }
    }
  }
  puts("");
}