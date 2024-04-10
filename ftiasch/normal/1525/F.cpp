// #include "debug.h"

#include <bits/stdc++.h>

const int N = 50;

int n, graph[N][N], matchy[N];
std::pair<long long, int> dp[N + 1][N + 1];
bool matchx[N], visited[N + N];

bool find(int u) {
  if (!visited[u]) {
    visited[u] = true;
    for (int v = 0; v < n; ++v) {
      if (graph[u][v] && (matchy[v] == -1 || find(matchy[v]))) {
        matchy[v] = u;
        return true;
      }
    }
  }
  return false;
}

void dfs(int u) {
  if (!visited[u]) {
    visited[u] = true;
    for (int v = 0; v < n; ++v) {
      if (graph[u][v]) {
        // if (matchy[v] != u) {
        visited[n + v] = true;
        // }
        if (~matchy[v]) {
          dfs(matchy[v]);
        }
      }
    }
  }
}

int main() {
  int m, l;
  scanf("%d%d%d", &n, &m, &l);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a][b] = true;
  }
  memset(matchy, -1, sizeof(matchy));
  for (int u = 0; u < n; ++u) {
    if (find(u)) {
      matchx[u] = true;
      memset(visited, 0, sizeof(visited));
    }
  }
  memset(visited, 0, sizeof(visited));
  for (int u = 0; u < n; ++u) {
    if (!matchx[u]) {
      dfs(u);
    }
  }
  std::vector<int> cuts;
  std::vector<bool> removed(n + n);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      cuts.push_back(i + 1);
      removed[i] = true;
    }
    if (visited[n + i]) {
      cuts.push_back(-(i + 1));
      removed[n + i] = true;
    }
  }
  for (int i = 0; i <= l; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = {-1, -1};
    }
  }
  assert(std::accumulate(matchx, matchx + n, 0) == cuts.size());
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      if (graph[u][v]) {
        assert(removed[u] || removed[n + v]);
      }
    }
  }
  dp[0][cuts.size()] = {0, -1};
  for (int i = 1; i <= l; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    // min_cut = max_flow < n - i
    for (int j = 0; j < n - i; ++j) {
      for (int k = j; k <= n; ++k) {
        long long prev = dp[i - 1][k].first;
        if (~prev) {
          dp[i][j] = std::max(dp[i][j],
                              {prev + std::max(x - 1LL * (k - j) * y, 0LL), k});
        }
      }
    }
  }
  std::pair<long long, int> last{-1, -1};
  for (int j = 0; j <= n; ++j) {
    long long v = dp[l][j].first;
    if (~v) {
      last = std::max(last, {v, j});
    }
  }
  std::vector<int> seq;
  //   std::cout << KV(cuts) << std::endl;
  for (int i = l, j = last.second; i > 0; --i) {
    int k = dp[i][j].second;
    seq.push_back(0);
    while (j < k) {
      seq.push_back(cuts[j++]);
    }
  }
  printf("%d\n", static_cast<int>(seq.size()));
  for (int i = seq.size(); i--;) {
    printf("%d%c", seq[i], " \n"[i == 0]);
  }
}