#include <bits/stdc++.h>

const int N = 1000001;

int n, q, a[N], dp[N], top, delta;
std::pair<int, int> stack[N];
std::vector<std::pair<char, int>> children[N];

void dfs(int p, int u) {
  bool in = dp[u] == -1;
  dp[u] = ~p ? dp[p] + 1 : 0;
  int value = dp[u] - delta;
  if (!top || stack[top - 1].second > value) {
    stack[top++] = {u, value};
  }
  if (in) {
    delta++;
    dp[u] = std::min(dp[u], stack[top - 1].second + delta);
  }
  std::sort(children[u].begin(), children[u].end());
  for (auto iterator : children[u]) {
    dfs(u, iterator.second);
  }
  while (top && stack[top - 1].first == u) {
    top--;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1, p; i <= n; ++i) {
    char c[2];
    scanf("%d%s", &p, c);
    children[p].emplace_back(*c, i);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", a + i);
    dp[a[i]] = -1;
  }
  dfs(-1, 0);
  for (int i = 0; i < q; ++i) {
    printf("%d\n", dp[a[i]]);
  }
}