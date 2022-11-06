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

#define INFLL 1000000000000000000LL
#define MAXN 5000

using namespace std;

typedef long long lint;

int n, start, endpos;
lint x[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];

lint dp[MAXN][MAXN+1];

lint solve(int i, int out, int in) {
  if (i == n) {
    if (out == 0 && in == 0) return 0LL;
    else return INFLL;
  } else if (dp[i][out] != -1) {
    return dp[i][out];
  } else {
    lint &result = dp[i][out] = INFLL;
    lint res;

    if (i != 0 && (out == 0 && in == 0)) return result = INFLL;

    if (i == start) {
      {
	res = -x[i] + d[i] + solve(i+1, out+1, in);
	result = min(result, res);
      }
      if (in > 0) {
	res = x[i] + c[i] + solve(i+1, out, in-1);
	result = min(result, res);
      }
    } else if (i == endpos) {
      {
	res = -x[i] + b[i] + solve(i+1, out, in+1);
	result = min(result, res);
      }
      if (out > 0) {
	res = x[i] + a[i] + solve(i+1, out-1, in);
	result = min(result, res);
      }
    } else {
      {
	res = -x[i] - x[i] + d[i] + b[i] + solve(i+1, out+1, in+1);
	result = min(result, res);
      }
      if (out > 0) {
	res = -x[i] + x[i] + d[i] + a[i] + solve(i+1, out+1-1, in);
	result = min(result, res);
      }
      if (in > 0) {
	res = -x[i] + x[i] + c[i] + b[i] + solve(i+1, out, in-1+1);
	result = min(result, res);
      }
      if (out > 0 && in > 0) {
	res = +x[i] + x[i] + c[i] + a[i] + solve(i+1, out-1, in-1);
	result = min(result, res);
      }
    }

    return result;
  }
}

int main() {
  scanf("%d %d %d", &n, &start, &endpos), --start, --endpos;

  for (int i = 0; i < n; ++i) scanf("%lld", &x[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &c[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &d[i]);

  memset(dp, -1, sizeof(dp));

  printf("%lld\n", solve(0, 0, 0));

  return 0;
}