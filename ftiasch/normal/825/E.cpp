#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> out(n), result(n);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    out[u]++;
    graph[v].push_back(u);
  }
  std::priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    if (!out[i]) {
      pq.push(i);
    }
  }
  int count = n;
  while (!pq.empty()) {
    int v = pq.top();
    pq.pop();
    result[v] = --count;
    for (int u : graph[v]) {
      if (!(--out[u])) {
        pq.push(u);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", result[i] + 1, " \n"[i + 1 == n]);
  }
}