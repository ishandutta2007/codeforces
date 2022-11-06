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

#define MAXN 100000

using namespace std;

typedef long long lint;

int dp1[MAXN+1][2];
int dp2[MAXN+1][2][2];

int main() {
  int n;
  scanf("%d", &n);
  string str(n, ' ');
  scanf(" %s", &str[0]);

  dp1[0][0] = dp1[0][1] = 0;
  for (int s = 1; s <= n; ++s) {
    int v = str[s-1]-'0';
    dp1[s][v] = 1+dp1[s-1][v^1];
    dp1[s][v^1] = dp1[s-1][v^1];
  }

  memset(dp2, 0, sizeof(dp2));
  for (int s = 1; s <= n; ++s)
    for (int inv = 0; inv < 2; ++inv) {
      int v = (str[n-s]-'0')^inv;
      dp2[s][v][inv] = 1+max(dp2[s-1][v^1][inv], dp2[s-1][v^1][0]);
      dp2[s][v^1][inv] = max(dp2[s-1][v^1][inv], dp2[s-1][v^1][0]);
    }

  int result = 0;
  for (int i = 0; i < n; ++i) {
    int v = (str[i]-'0')^1;
    result = max(result, dp1[i][v^1] + dp2[n-i][v][1]);
  }

  printf("%d\n", result);
  
  return 0;
}