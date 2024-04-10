#include <bits/stdc++.h>

int n[4], banned[150000];
std::vector<int> a[4];

int main() {
  for (int i = 0; i < 4; ++i) {
    scanf("%d", n + i);
  }
  for (int i = 0; i < 4; ++i) {
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  std::vector<std::pair<int, int>> dp(n[0]);
  for (int j = 0; j < n[0]; ++j) {
    dp[j] = {a[0][j], j};
  }
  int clock = 0;
  for (int i = 1; i < 4; ++i) {
    int m;
    scanf("%d", &m);
    std::vector<std::pair<int, int>> bans(m);
    for (int j = 0, a, b; j < m; ++j) {
      scanf("%d%d", &a, &b);
      bans[j] = {b - 1, a - 1};
    }
    std::sort(bans.begin(), bans.end());
    std::vector<std::pair<int, int>> new_dp(n[i]);
    std::sort(dp.begin(), dp.end());
    for (int j = 0, k = 0; j < n[i]; ++j) {
      clock++;
      while (k < m && bans[k].first == j) {
        banned[bans[k++].second] = clock;
      }
      int pivot = 0;
      while (pivot < n[i - 1] && banned[dp[pivot].second] == clock) {
        pivot++;
      }
      new_dp[j] = {pivot < n[i - 1] && dp[pivot].first < INT_MAX
                       ? dp[pivot].first + a[i][j]
                       : INT_MAX,
                   j};
    }
    dp.swap(new_dp);
  }
  int result = std::min_element(dp.begin(), dp.end())->first;
  printf("%d\n", result < INT_MAX ? result : -1);
}