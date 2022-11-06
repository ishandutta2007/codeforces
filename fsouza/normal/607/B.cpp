#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define INF 1000000000

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

  vector<vector<int>> dp(n+1, vector<int>(n+1));
  vector<vector<int>> dp2(n+1, vector<int>(n+1));  

  for (int i = 0; i <= n; ++i)
    dp[i][i] = dp2[i][i] = 0;

  for (int i = 0; i+1 <= n; ++i) {
    dp[i][i+1] = 1;
    dp2[i][i+1] = 0;
  }

  for (int s = 2; s <= n; ++s)
    for (int i = 0; i+s <= n; ++i) {
      const int j = i+s;

      dp2[i][j] = INF;
      if (c[i] == c[j-1]) dp2[i][j] = min(dp2[i][j], dp2[i+1][j-1]);
      for (int k = i+1; k < j; ++k)
    dp2[i][j] = min(dp2[i][j], min(dp[i][k] + dp2[k][j],
                       dp2[i][k] + dp[k][j]));

      dp[i][j] = 1 + dp2[i][j];
      for (int k = i+1; k < j; ++k)
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

  printf("%d\n", dp[0][n]);
  
  return 0;
}