#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1e5 + 5;

int n;
llint t[MAXN];
llint dp[MAXN];

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) scanf("%lld", t + i);

  int p90 = -1;
  int p1440 = -1;

  FOR(k, 1, n + 1) {
    int i = k - 1;

    while (t[i] - t[p90 + 1] >= 90) ++p90;
    while (t[i] - t[p1440 + 1] >= 1440) ++p1440;

    dp[k] = dp[k - 1] + 20;
    dp[k] = min(dp[k], dp[p90 + 1] + 50);
    dp[k] = min(dp[k], dp[p1440 + 1] + 120);

    printf("%lld\n", dp[k] - dp[k - 1]);
  }
  

  

  return 0;
}