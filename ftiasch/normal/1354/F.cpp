#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 75;

int n, m, a[N], b[N], order[N], dp[N + 1][N + 1];

void update(int &x, int a) { x = std::max(x, a); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", a + i, b + i);
    }
    std::iota(order, order + n, 0);
    std::sort(order, order + n, [&](int i, int j) { return b[i] < b[j]; });
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      int ii = order[i];
      for (int j = 0; j <= m; ++j) {
        if (~dp[i][j]) {
          if (j < m) {
            update(dp[i + 1][j + 1], dp[i][j] + a[ii] + j * b[ii]);
          }
          update(dp[i + 1][j], dp[i][j] + (m - 1) * b[ii]);
        }
      }
    }
    std::vector<int> picks, unpicks;
    for (int i = n, j = m; i--;) {
      int ii = order[i];
      if (j && dp[i][j - 1] + a[ii] + (j - 1) * b[ii] == dp[i + 1][j]) {
        j--;
        picks.push_back(ii);
      } else {
        unpicks.push_back(ii);
      }
    }
    std::vector<int> plan;
    for (int i = m; i-- > 1;) {
      plan.push_back(picks[i] + 1);
    }
    for (int i = unpicks.size(); i--;) {
      plan.push_back(unpicks[i] + 1);
      plan.push_back(-(unpicks[i] + 1));
    }
    plan.push_back(picks[0] + 1);
    int sz = plan.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++i) {
      printf("%d%c", plan[i], " \n"[i + 1 == sz]);
    }
  }
}