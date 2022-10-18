#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
typedef long long llint;
typedef long double ldouble;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXS = 1000005 / 2;
const int MAXN = 105;

int N, M;
int x[MAXN];
ldouble dp[2][MAXS];
ldouble *f, *g;

int main(void) 
{
  scanf("%d%d", &N, &M);
  FOR(i, 1, N + 1) scanf("%d", x + i);

  if (M == 1) {
    puts("1.000000000");
    exit(0);
  }

  g = dp[0]; g[0] = 1.0;
  f = dp[1];

  FOR(i, 1, N + 1) {
    ldouble sum = 0.0;
    ldouble val = 0.0;
    f[0] = 0.0;
    FOR(s, 1, MAXS) {
      sum += g[s - 1];
      if (s > M) sum -= g[s - M - 1];
      val = sum;
      if (s - x[i] >= 0)
	val -= g[s - x[i]];
      f[s] = val;
    }
    swap(f, g);
  }

  int sum = 0;
  FOR(i, 1, N + 1) sum += x[i];

  ldouble tot = 0.0;
  FOR(s, 1, MAXS) tot += g[s];

  ldouble good = 0.0;
  FOR(s, 1, sum) good += g[s];

  ldouble p = good / tot;
  printf("%.10lf\n", (double)(1.0 + (M - 1) * p));

  return 0;
}