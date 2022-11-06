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

const int mod = 1e9+7;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int size = n-m;
  string str(m, ' ');
  scanf("%s", &str[0]);

  vector<vector<int>> dp(size+1, vector<int>(size+1, 0));
  dp[0][0] = 1;
  for (int s = 0; s+1 <= size; ++s)
    for (int delta = 0; delta <= s; ++delta)
      if (dp[s][delta]) {
	dp[s+1][delta+1] = (dp[s+1][delta+1] + dp[s][delta]) % mod;
	if (delta-1 >= 0)
	  dp[s+1][delta-1] = (dp[s+1][delta-1] + dp[s][delta]) % mod;
      }

  int mindelta = 0, middledelta;
  {
    int delta = 0;
    for (int i = 0; i < m; ++i) {
      if (str[i] == '(') ++delta;
      else --delta;
      mindelta = min(mindelta, delta);
    }
    middledelta = delta;
  }

  int result = 0;
  for (int leftsize = 0; leftsize <= size; ++leftsize)
    for (int leftdelta = 0; leftdelta <= leftsize; ++leftdelta) {
      int rightsize = size - leftsize;
      int rightdelta = -leftdelta-middledelta;
      int inv = -rightdelta;
      if (inv >= 0 && inv <= rightsize && leftdelta + mindelta >= 0)
	result = (result + ((lint)dp[leftsize][leftdelta] *
			    dp[rightsize][inv])) % mod;
    }
  printf("%d\n", result);
  
  return 0;
}