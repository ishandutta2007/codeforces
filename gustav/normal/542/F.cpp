#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXT = 105;
const int MAXN = 1005;

int n, T;
int t[MAXN];
int q[MAXN];
int dp[2][MAXN][MAXT];

int main(void) 
{
  scanf("%d%d", &n, &T);

  vector< pair< int, int > > vp;
  REP(i, n) {
    int a, b;
    scanf("%d%d", &a, &b);
    a = T - a;
    vp.push_back({a, b});
  }

  sort(vp.rbegin(), vp.rend());
  REP(i, n) t[i] = vp[i].first, q[i] = vp[i].second;

  int sol = 0;
  memset(dp, -1, sizeof dp);

  for (int i = n; i >= 0; --i) {
    int I = i % 2;
    for (int dep = 0; dep < T; ++dep) {
      for (int j = 0; j <= n; ++j) {
	int &ret = dp[I][j][dep];
	if (i == n) { ret = 0; continue; }
	if (dep <= 10 && j >= (1 << dep)) { ret = 0; continue; }
	ret = dp[I ^ 1][j][dep];
	if (t[i] >= dep)
	  ret = max(ret, q[i]);

	if (j % 2 && dep) {
	  ret = max(ret, dp[I][(j + 1) / 2][dep - 1]);
	  if (t[i] >= dep)
	    ret = max(ret, dp[I ^ 1][(j + 1) / 2][dep - 1] + q[i]);
	}

	if (t[i] >= dep)
	  ret = max(ret, dp[I ^ 1][j + 1][dep] + q[i]);
      }
    }
  }

  REP(dep, T) sol = max(sol, dp[0][0][dep]);

  printf("%d\n", sol);
    
  return 0;
}