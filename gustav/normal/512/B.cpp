#include <cstdio>
#include <cassert>

#include <map>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 305;
const int inf = 1000000005;

int N;
int l[MAXN];
int c[MAXN];

map< int, int > dp[MAXN];

int solve(int i, int g) {
  if (i == N) {
    if (g == 1) return 0;
    return inf;
  }

  if (dp[i].count(g))
    return dp[i][g];

  int ret = inf;
  ret = min(ret, solve(i + 1, g));
  ret = min(ret, solve(i + 1, __gcd(g, l[i])) + c[i]);

  dp[i][g] = ret;

  return ret;
}

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) scanf("%d", l + i);
  REP(i, N) scanf("%d", c + i);

  int sol = inf;

  REP(i, N) sol = min(sol, solve(i + 1, l[i]) + c[i]);

  printf("%d\n", sol < inf ? sol : -1);

  return 0;
}