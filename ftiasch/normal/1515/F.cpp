#include <bits/stdc++.h>

const int N = 300'000;

int n, m, limit;
bool visited[N];
long long a[N];
std::vector<std::pair<int, int>> graph[N];
std::vector<int> prefix, suffix;

void dfs(int u) {
  visited[u] = true;
  for (auto [v, i] : graph[u]) {
    if (!visited[v]) {
      dfs(v);
      if (a[v] >= limit) {
        prefix.push_back(i);
        a[u] += a[v] - limit;
      } else {
        suffix.push_back(i);
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &limit);
  for (int i = 0, a_; i < n; ++i) {
    scanf("%d", &a_);
    a[i] = a_;
  }
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].emplace_back(b, i);
    graph[b].emplace_back(a, i);
  }
  if (std::accumulate(a, a + n, 0LL) < (n - 1LL) * limit) {
    puts("NO");
  } else {
    puts("YES");
    dfs(0);
    for (int i : prefix) {
      printf("%d\n", i + 1);
    }
    std::ranges::reverse(suffix);
    for (auto i : suffix) {
      printf("%d\n", i + 1);
    }
  }
}