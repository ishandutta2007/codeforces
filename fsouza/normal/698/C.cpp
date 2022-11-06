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

#define MAXN 20

using namespace std;

typedef long long lint;
typedef double ldouble;

const ldouble E = 1e-9;

ldouble prob[MAXN], probsum[1<<MAXN], dp[1<<MAXN];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  probsum[0] = 0.0;
  for (int i = 0; i < n; ++i) {
    double pi;
    scanf("%lf", &pi);
    prob[i] = pi;
    probsum[1<<i] = prob[i];
  }
  for (int s = 0; s < 1<<n; ++s)
    if (__builtin_popcount(s) > 1) {
      int bit = s&-s;
      probsum[s] = probsum[bit] + probsum[s ^ bit];
    }

  int ngoodguys = 0;

  for (int i = 0; i < n; ++i)
    if (prob[i] > E)
      ++ngoodguys;

  dp[0] = 1.0;
  for (int s = 1; s < 1<<n; ++s) {
    if (__builtin_popcount(s) > k) continue;
    dp[s] = 0.0;
    bool ok = true;
    for (int i = 0; i < n; ++i)
      if ((s & 1<<i) && (prob[i] < E)) {
	ok = false;
	break;
      }
    if (!ok) continue;
    for (int i = 0; i < n; ++i)
      if (s & (1<<i))
	dp[s] += dp[s ^ (1<<i)] * prob[i] / probsum[(1<<n)-1-s+(1<<i)];
  }

  vector<ldouble> result(n);
  for (int s = 0; s < 1<<n; ++s)
    if (__builtin_popcount(s) == min(k, ngoodguys))
      for (int i = 0; i < n; ++i)
	if (s & (1<<i))
	  result[i] += dp[s];

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%.9f", (double)result[i]);
  }
  printf("\n");

  return 0;
}