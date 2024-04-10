#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  const int maxs = 200;
  vector<vector<int>> dp(maxs+1, vector<int>(maxs+1));

  for (int s = 0; s <= maxs; ++s)
    for (int a = 0; a <= s; ++a) {
      const int b = s-a;
      dp[a][b] = 0;
      if (a-2 >= 0 && b > 0) dp[a][b] = max(dp[a][b], 1 + dp[a-2][b+1]);
      if (b-2 >= 0 && a > 0) dp[a][b] = max(dp[a][b], 1 + dp[a+1][b-2]);
    }
  
  int a1, a2;
  scanf("%d %d", &a1, &a2);
  printf("%d\n", dp[a1][a2]);
  
  return 0;
}