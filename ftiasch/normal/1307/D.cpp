#include <bits/stdc++.h>

const int N = 200000;

int n, m, k, order[N], d[2][N], queue[N];
std::vector<int> graph[N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", order + i);
    order[i]--;
  }
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int t = 0; t < 2; ++t) {
    std::fill(d[t], d[t] + n, n);
    int rear = 1;
    d[t][queue[0] = t ? n - 1 : 0] = 0;
    for (int head = 0; head < rear; ++head) {
      int u = queue[head];
      for (int v : graph[u]) {
        if (d[t][v] == n) {
          d[t][v] = d[t][u] + 1;
          queue[rear++] = v;
        }
      }
    }
  }
  std::sort(order, order + k, [&](int i, int j) {
    return d[0][i] + d[1][j] < d[0][j] + d[1][i];
  });
  int suffix = -n;
  int result = 0;
  for (int _ = k; _--;) {
    int i = order[_];
    result = std::max(result, d[0][i] + 1 + suffix);
    suffix = std::max(suffix, d[1][i]);
  }
  printf("%d\n", std::min(result, d[0][n - 1]));
}