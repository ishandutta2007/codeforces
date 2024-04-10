#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500;

int n, m, count, visit[N];
std::vector<int> graph[N];

void dfs(int u) {
  visit[u] = 0;
  for (int v : graph[u]) {
    if (visit[v] == -1) {
      dfs(v);
    } else {
      count += (visit[v] == 0);
    }
  }
  visit[u] = 1;
}

bool check() {
  for (int s = 0; s < n; ++s) {
    memset(visit, -1, sizeof(visit));
    count = 0;
    dfs(s);
    for (int i = 0; i < n; ++i) {
      if (!~visit[i]) {
        dfs(i);
      }
    }
    if (count <= 1) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    graph[a - 1].push_back(b - 1);
  }
  puts(check() ? "YES" : "NO");
}