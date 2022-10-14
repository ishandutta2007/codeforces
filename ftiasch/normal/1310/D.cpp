#include <bits/stdc++.h>
#include <limits>
#include <random>

const int N = 80;

int n, k, cost[N][N], color[N], dp[2][N];

void update(int &x, int a) {
  if (x == -1 || x > a) {
    x = a;
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", cost[i] + j);
    }
  }
  auto result = -1;
  std::mt19937 gen;
  std::uniform_int_distribution<int> dist(0, 1);
  for (int _ = 0; _ < (1 << k - 1) * 30; ++_) {
    for (int i = 0; i < n; ++i) {
      color[i] = dist(gen);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < k; ++i) {
      memset(dp[i + 1 & 1], -1, sizeof(dp[i + 1 & 1]));
      for (int u = 0; u < n; ++u) {
        if (~dp[i & 1][u]) {
          for (int v = 0; v < n; ++v) {
            if (color[u] != color[v]) {
              update(dp[i + 1 & 1][v], dp[i & 1][u] + cost[u][v]);
            }
          }
        }
      }
    }
    if (~dp[k & 1][0]) {
      update(result, dp[k & 1][0]);
    }
  }
  printf("%d\n", result);
}