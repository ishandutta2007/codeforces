#include <bits/stdc++.h>

const int N = 100'000;

int n, a[N], b[N], opposite[N << 1], color[N << 1];

void dfs(int u, int c) {
  if (color[u] == -1) {
    color[u] = c;
    dfs(u ^ 1, c ^ 1);
    dfs(opposite[u], c ^ 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
    a[i]--;
    b[i]--;
    opposite[a[i]] = b[i];
    opposite[b[i]] = a[i];
  }
  memset(color, -1, sizeof(color));
  for (int i = 0; i < n << 1; ++i) {
    dfs(i, 0);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", color[a[i]] + 1, color[b[i]] + 1);
  }
}