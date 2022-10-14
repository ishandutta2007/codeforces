// #include "debug.h"

#include <bits/stdc++.h>

const int N = 10;
const int M = 100'000;

int n, m, c[N], bans[N][M], suf_max[N + 1];
std::tuple<int, int, int, int> result;
std::vector<int> w[N];

void dfs(int i, int l, int r, int sum) {
  if (i < n) {
    int x = c[i] - 1;
    while (l < r) {
      int y = bans[i][r - 1];
      if (y == x) {
        x--;
      }
      int j = r - 1;
      while (l < j && bans[i][j - 1] == y) {
        j--;
      }
      dfs(i + 1, j, r, sum + w[i][y]);
      r = j;
    }
    if (x >= 0) {
      result = std::max(result, {sum + w[i][x] + suf_max[i + 1], i, l, x});
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
    w[i].resize(c[i]);
    for (int j = 0; j < c[i]; ++j) {
      scanf("%d", &w[i][j]);
    }
  }
  int m;
  scanf("%d", &m);
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &bans[i][j]);
      bans[i][j]--;
    }
  }
  static int order[M], new_order[M], count[200'000];
  std::iota(order, order + m, 0);
  for (int i = n; i--;) {
    memset(count, 0, sizeof(int) * c[i]);
    for (int j = 0; j < m; ++j) {
      count[bans[i][j]]++;
    }
    for (int j = 1; j < c[i]; ++j) {
      count[j] += count[j - 1];
    }
    for (int j = m; j--;) {
      new_order[--count[bans[i][order[j]]]] = order[j];
    }
    memcpy(order, new_order, sizeof(int) * m);
  }
  {
    static int sorted_bans[M];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sorted_bans[j] = bans[i][order[j]];
      }
      memcpy(bans[i], sorted_bans, sizeof(int) * m);
    }
  }
  for (int i = n; i--;) {
    suf_max[i] = w[i].back() + suf_max[i + 1];
  }
  result = {0, 0, 0, 0};
  dfs(0, 0, m, 0);
  std::vector<int> plan;
  {
    auto [_, a, b, x] = result;
    for (int i = 0; i < a; ++i) {
      plan.push_back(bans[i][b]);
    }
    plan.push_back(x);
    for (int i = a + 1; i < n; ++i) {
      plan.push_back(c[i] - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", plan[i] + 1, " \n"[i + 1 == n]);
  }
  //   printf("%d\n", result);
}