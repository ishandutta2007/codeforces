// #include "debug.h"

#include <bits/stdc++.h>

int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  int p = x + y;
  std::vector<bool> used(p);
  int result = 0;
  for (int r = 0; r < p; ++r) {
    if (!used[r]) {
      std::vector<int> cnt;
      for (int i = r; !used[i]; i = (i + x) % p) {
        used[i] = true;
        cnt.push_back(i >= n ? 0 : (n - i - 1) / p + 1);
      }
      //   std::cout << cnt << std::endl;
      int sub_result = 0;
      for (int first = 0; first < 2; ++first) {
        int dp[] = {INT_MIN, INT_MIN};
        dp[first] = first ? cnt[0] : 0;
        for (int i = 1; i < static_cast<int>(cnt.size()); ++i) {
          int dp0 = std::max(dp[0], dp[1]);
          int dp1 = dp[0] + cnt[i];
          dp[0] = dp0;
          dp[1] = dp1;
        }
        sub_result =
            std::max(sub_result, first ? dp[0] : std::max(dp[0], dp[1]));
      }
      result += sub_result;
    }
  }
  printf("%d\n", result);
}