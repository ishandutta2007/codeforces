#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  const int maxv = 1000000;
  vector<int> many(maxv+1, 0);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    ++many[v];
  }
  int result = 0;
  vector<int> dp(maxv+1, 0);
  for (int v = maxv; v >= 1; --v) {
    dp[v] = many[v];
    for (int u = v+v; u <= maxv; u += v)
      dp[v] = max(dp[v], many[v] + dp[u]);
    result = max(result, dp[v]);
  }
  printf("%d\n", result);
  
  return 0;
}