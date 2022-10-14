#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m, limit;
  scanf("%d%d%d", &n, &m, &limit);
  std::vector<char> s(m + 1);
  std::vector<int> dp(limit + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s.data());
    std::vector<int> lessons;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') {
        lessons.push_back(j);
      }
    }
    int sz = lessons.size();
    std::vector<int> time(sz + 1, INT_MAX);
    time[sz] = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i; j < sz; ++j) {
        int skip = sz - (j - i + 1);
        time[skip] = std::min(time[skip], lessons[j] - lessons[i] + 1);
      }
    }
    for (int i = limit; i >= 0; -- i) {
        int best = INT_MAX;
        for (int j = 0; j <= i && j <= sz; ++ j) {
            best = std::min(best, dp[i - j] + time[j]);
        }
        dp[i] = best;
    }
  }
  printf("%d\n", dp[limit]);
}