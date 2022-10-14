#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<std::pair<int, int>> dp(n), sufmax(n + 1);
  sufmax[n] = {0, n};
  std::map<int, int> next_map;
  for (int i = n, j = INT_MAX; i--;) {
    auto iterator = next_map.find(a[i]);
    if (iterator != next_map.end()) {
      j = std::min(j, iterator->second + 1);
    }
    next_map[a[i]] = i;
    if (j <= n) {
      dp[i] = {1 + sufmax[j].first, sufmax[j].second};
    } else {
      dp[i] = {-1, -1};
    }
    sufmax[i] = std::max(std::make_pair(dp[i].first, i), sufmax[i + 1]);
  }
  if (~dp[0].first) {
    printf("%d\n", dp[0].first);
    for (int i = 0; i < n; ) {
      int j = dp[i].second;
      printf("%d %d\n", i + 1, j);
      i = j;
    }
  } else {
    puts("-1");
  }
}