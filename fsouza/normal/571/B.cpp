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
#include <unordered_map>
#include <vector>

#define MAXK 5000

using namespace std;

typedef long long lint;

int dp[MAXK+1][MAXK+1];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> values(n);
  for (int &v : values) scanf("%d", &v);
  sort(values.begin(), values.end());

  int smallsize = n/k, bigsize = smallsize+1;
  int nbig = n%k, nsmall = k - nbig;

  for (int ns = nsmall; ns >= 0; --ns)
    for (int nb = nbig; nb >= 0; --nb)
      if (ns == nsmall && nb == nbig) dp[ns][nb] = 0;
      else {
	dp[ns][nb] = INT_MAX;
	int at = ns * smallsize + nb * bigsize;
	if (ns+1 <= nsmall) dp[ns][nb] = min(dp[ns][nb], values[at + smallsize-1] - values[at] + dp[ns+1][nb]);
	if (nb+1 <= nbig) dp[ns][nb] = min(dp[ns][nb], values[at + bigsize-1] - values[at] + dp[ns][nb+1]);
      }

  printf("%d\n", dp[0][0]);

  return 0;
}