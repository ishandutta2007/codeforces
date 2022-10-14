#include <bits/stdc++.h>

const int N = 3000;

int n, rear = 0, parent[N][N], size[N][N];
std::vector<int> tree[N];
long long dp[N][N];
std::pair<int, int> queue[N * N / 2];

void prepare(int r, int u) {
  size[r][u] = 1;
  for (int v : tree[u]) {
    if (v != parent[r][u]) {
      parent[r][v] = u, prepare(r, v), size[r][u] += size[r][v];
      if (!r) {
        dp[u][v] = dp[v][u] = 0, queue[rear++] = std::make_pair(u, v);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--, b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  memset(dp, -1, sizeof(dp));
  for (int r = 0; r < n; ++r) {
    parent[r][r] = -1, prepare(r, r);
  }
  long long result = 0;
  for (int d = 1, head = 0; d < n; ++d) {
    int rear0 = rear;
    for (; head < rear0; ++head) {
      int a = queue[head].first, b = queue[head].second;
      for (int _ = 0; _ < 2; ++_) {
        for (int v : tree[b]) {
          if (v != parent[a][b]) {
            if (dp[a][v] == -1) {
              queue[rear++] = std::make_pair(a, v);
            }
            auto nv =
                dp[a][b] + 1LL * d * size[b][a] * (size[a][b] - size[a][v]);
            dp[a][v] = dp[v][a] = std::max(dp[a][v], nv);
          }
        }
        std::swap(a, b);
      }
      result = std::max(result, dp[a][b] + d);
    }
  }
  printf("%lld\n", result);
}