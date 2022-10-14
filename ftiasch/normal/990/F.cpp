#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, m, supply[N], to[N << 1], next[N << 1], head[N], flow[N << 1];
bool used[N], visited[N];

void dfs(int u) {
  visited[u] = true;
  for (int e = head[u]; ~e; e = next[e]) {
    if (!used[e >> 1]) {
      used[e >> 1] = true;
      int v = to[e];
      if (!visited[v]) {
        dfs(v);
        flow[e] = -supply[v];
        flow[e ^ 1] = supply[v];
        supply[u] += supply[v];
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", supply + i);
  }
  if (std::accumulate(supply, supply + n, 0) != 0) {
    puts("Impossible");
    return 0;
  }
  scanf("%d", &m);
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
  }
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  dfs(0);
  puts("Possible");
  for (int i = 0; i < m << 1; i += 2) {
      printf("%d\n", flow[i]);
  }
}