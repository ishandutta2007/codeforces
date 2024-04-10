#include <bits/stdc++.h>

const int N = 500'001;

int parent[N], value[N], repr[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

int main() {
  int q;
  scanf("%d", &q);
  int len = 0;
  memset(repr, -1, sizeof(repr));
  while (q--) {
    int op, x;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      if (~repr[x]) {
        parent[len++] = repr[x];
      } else {
        repr[value[len] = x] = len;
        parent[len] = len;
        len++;
      }
    } else {
      int y;
      scanf("%d", &y);
      if (~repr[x] && x != y) {
        if (~repr[y]) {
          // merge
          parent[repr[x]] = repr[y];
          repr[x] = -1;
        } else {
          // rename
          repr[y] = repr[x];
          value[repr[y] = repr[x]] = y;
          repr[x] = -1;
        }
      }
    }
  }
  for (int i = 0; i < len; ++i) {
    printf("%d%c", value[find(i)], " \n"[i + 1 == len]);
  }
}