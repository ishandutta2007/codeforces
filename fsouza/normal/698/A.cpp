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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define INF 1000000000

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> masks(n);
  for (int i = 0; i < n; ++i) {
    int m;
    scanf("%d", &m);
    masks[i] = m;
  }
  vector<vector<int>> dp(n+1, vector<int>(4, 0));
  dp[0][0] = 0;
  dp[0][1] = INF;
  dp[0][2] = INF;
  dp[0][3] = INF;
  for (int i = 0; i < n; ++i) {
    for (int doing = 0; doing < 4; ++doing) {
      int &result = dp[i+1][doing] = INF;
      if (!((doing | masks[i]) == masks[i])) continue;
      for (int prev = 0; prev < 4; ++prev) {
	if ((doing & prev) == 0) {
	  result = min(result, dp[i][prev] + (doing == 0 ? 1 : 0));
	}
      }
    }
  }
  int result = *min_element(dp[n].begin(), dp[n].end());
  printf("%d\n", result);

  return 0;
}