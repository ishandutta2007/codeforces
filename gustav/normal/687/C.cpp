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

const int MAX = 505;

int N, K;
int c[MAX];
int dp[2][MAX][MAX];

int main(void) 
{
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", c + i);

  memset(dp, 0, sizeof dp);
  REP(t, MAX) REP(k, MAX) dp[N % 2][t][k] = (t == 0 && k == 0);
  
  for (int i = N - 1; i >= 0; --i) {
    int I = i % 2;

    REP(t, MAX) REP(k, MAX) {
      dp[I][t][k] = dp[I ^ 1][t][k];
      if (k >= c[i]) {
	dp[I][t][k] |= dp[I ^ 1][t][k - c[i]];
	if (t >= c[i]) {
	  dp[I][t][k] |= dp[I ^ 1][t - c[i]][k - c[i]];
	}
      }
    }
  }

  int cnt = 0;
  REP(i, K + 1)
    if (dp[0][i][K])
      ++cnt;

  printf("%d\n", cnt);

  REP(i, K + 1)
    if (dp[0][i][K])
      printf("%d ", i);
  puts("");

  return 0;
}