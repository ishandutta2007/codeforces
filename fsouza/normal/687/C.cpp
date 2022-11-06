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

#define MAXK 500

using namespace std;

typedef long long lint;

bool dp[MAXK+1][MAXK+1];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  memset(dp, 0, sizeof(dp));
  dp[0][0] = true;

  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    for (int a = k; a >= 0; --a)
      for (int b = k; b >= 0; --b) {
	if (a >= v) dp[a][b] |= dp[a-v][b];
	if (b >= v) dp[a][b] |= dp[a][b-v];
      }
  }

  vector<int> result;

  for (int a = 0; a <= k; ++a)
    if (dp[a][k-a])
      result.push_back(a);

  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}