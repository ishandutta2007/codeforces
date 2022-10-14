// #include "debug.h"

#include <bits/stdc++.h>

const int N = 10;
const int M = 10000;

int n, m, expected[N], ok[N][M], coef[M], cnt[N + N + 1], rank[M];
char buffer[M + 1];
std::pair<int, int> best, order[M];

void dfs(int i, int mask, int coef0) {
  if (i < n) {
    for (int j = 0; j < m; ++j) {
      if (ok[i][j]) {
        coef[j]--;
      }
    }
    dfs(i + 1, mask, coef0 + expected[i]);
    for (int j = 0; j < m; ++j) {
      if (ok[i][j]) {
        coef[j] += 2;
      }
    }
    dfs(i + 1, mask | 1 << i, coef0 - expected[i]);
    for (int j = 0; j < m; ++j) {
      if (ok[i][j]) {
        coef[j]--;
      }
    }
  } else {
    for (int j = 0; j < m; ++j) {
      cnt[n + coef[j]]++;
    }
    int cur = coef0;
    int rank = 1;
    for (int c = -n; c <= n; ++c) {
      while (cnt[n + c] > 0) {
        cur += c * rank;
        rank++;
        cnt[n + c]--;
      }
    }
    best = std::max(best, {cur, mask});
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%d", expected + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer);
      for (int j = 0; j < m; ++j) {
        ok[i][j] = buffer[j] == '1';
      }
    }
    best = {-1, -1};
    std::fill(coef, coef + m, 0);
    dfs(0, 0, 0);
    // std::cout << std::vector<int>(coef, coef + m) << std::endl;
    int mask = best.second;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        for (int j = 0; j < m; ++j) {
          coef[j] += ok[i][j];
        }
      } else {
        for (int j = 0; j < m; ++j) {
          coef[j] -= ok[i][j];
        }
      }
    }
    for (int j = 0; j < m; ++j) {
      order[j] = {coef[j], j};
    }
    std::sort(order, order + m);
    int cur = 1;
    for (int j = 0; j < m; ++j) {
      rank[order[j].second] = cur++;
    }
    for (int j = 0; j < m; ++j) {
      printf("%d%c", rank[j], " \n"[j + 1 == m]);
    }
    // printf("%d\n", best.first);
  }
}