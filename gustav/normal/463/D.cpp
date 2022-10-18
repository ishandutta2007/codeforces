#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAXK 10
#define MAXN 1005

int n, k;
int p[MAXK][MAXN];
int pos[MAXK][MAXN];

int dp[MAXN][MAXN];

int solve(int last, int cur) {
  if (cur == n) return 0;

  int &ret = dp[last + 1][cur];
  if (ret >= 0) return ret;

  ret = solve(last, cur + 1);

  bool can_take = true;
  REP(i, k) 
    if (last >= 0 && pos[i][p[0][cur]] < pos[i][last]) 
      can_take = false;
  
  if (can_take)
    ret = max(ret, 1 + solve(p[0][cur], cur + 1));

  return ret;
}

int main(void)
{
  scanf("%d%d", &n, &k);

  REP(i, k) REP(j, n) {
    scanf("%d", &p[i][j]); --p[i][j];
    pos[i][p[i][j]] = j;
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(-1, 0));

  return 0;
}