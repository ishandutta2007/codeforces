#include <bits/stdc++.h>

const int N = 300'001;

int n, a[N], b[N], dp[N], next[N + 1];
std::pair<int, int> pre[N];

int find_next(int u) {
  if (next[u] != u) {
    next[u] = find_next(next[u]);
  }
  return next[u];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= n + 1; ++i) {
    next[i] = i;
  }
  dp[n] = 0;
  std::queue<int> queue;
  queue.push(n);
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    int i = find_next(u - a[u]);
    while (i <= u) {
      int j = i + b[i];
      if (dp[j] == -1) {
        dp[j] = dp[u] + 1;
        pre[j] = {u, i};
        queue.push(j);
      }
      next[i] = i + 1;
      i = find_next(i);
    }
  }
  printf("%d\n", dp[0]);
  if (~dp[0]) {
    std::vector<int> plan;
    for (int i = 0; i != n; i = pre[i].first) {
      plan.push_back(pre[i].second);
    }
    for (int i = plan.size(); i--;) {
      printf("%d%c", plan[i], " \n"[i == 0]);
    }
  }
}