#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  string a(n, ' '), b(m, ' ');
  scanf(" %s %s", &a[0], &b[0]);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  int result = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = max({0, dp[i - 1][j] - 1, dp[i][j - 1] - 1});
      if (a[i - 1] == b[j - 1])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 4 - 2);
      result = max(result, dp[i][j]);
    }
  printf("%d\n", result);
  return 0;
}