#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define INF 1000000000
#define MAXN 150
#define MAXS (MAXN*(MAXN-1)/2)

using namespace std;

typedef long long lint;

static int _dp[2][MAXN+1][MAXS+1];
inline int &dp(int i, int x, int s) { return _dp[i&1][x][s]; }
vector<vector<int>> solve(vector<int> values, int maxx, int maxs) {
  int n = values.size();

  for (int s = 0; s <= maxs; ++s)
    dp(n, 0, s) = 0;
  for (int x = 1; x <= maxx; ++x)
    for (int s = 0; s <= maxs; ++s)
      dp(n, x, s) = -INF;
  for (int i = n-1; i >= 0; --i) {
    for (int s = 0; s <= maxs; ++s)
      dp(i, 0, s) = 0;
    for (int x = 1; x <= maxx; ++x)
      for (int s = 0; s <= maxs; ++s) {
	int &res = dp(i, x, s);
	res = -INF;
	if (x <= s) res = dp(i+1, x, s - x);
	res = max(res, values[i] + dp(i+1, x-1, s));
      }
  }

  vector<vector<int>> result(maxx+1, vector<int>(maxs+1));
  for (int x = 0; x <= maxx; ++x)
    for (int s = 0; s <= maxs; ++s)
      result[x][s] = dp(0, x, s);

  return result;
}

int main() {
  int n, k, maxs;
  scanf("%d %d %d", &n, &k, &maxs);
  maxs = min(maxs, n*(n-1)/2);
  
  vector<int> values(n);
  for (int i = 0; i < n; ++i) scanf("%d", &values[i]);
  vector<int> left, right;
  for (int i = k-1; i >= 0; --i) left.push_back(values[i]);
  for (int i = k; i < n; ++i) right.push_back(-values[i]);

  int maxx = min(left.size(), right.size());
  vector<vector<int>> resleft = solve(left, maxx, maxs);
  vector<vector<int>> resright = solve(right, maxx, maxs);

  int current = accumulate(values.begin(), values.begin()+k, 0);
  int result = INT_MAX;
  for (int x = 0; x <= maxx; ++x) {
    for (int s = 0; s <= maxs; ++s) {
      int s2 = maxs - s - x*x;
      if (s2 >= 0 && resleft[x][s] != -INF && resright[x][s2] != -INF)
	result = min(result, current - resleft[x][s] - resright[x][s2]);
    }
  }

  printf("%d\n", result);
  
  return 0;
}