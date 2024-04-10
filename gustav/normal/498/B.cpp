#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 5005;

int n, T;
int pp[MAX];
int t[MAX];
double p[MAX];
double ps[MAX];
double pl[MAX];
double dp[2][MAX];

int main(void) 
{
  scanf("%d%d", &n, &T);

  REP(i, n) scanf("%d%d", pp + i, t + i);
  REP(i, n) {
    p[i] = 0.01 * pp[i];
    
    double cp = 0.0;
    double lp = p[i];
    REP(j, t[i] - 1) {
      cp *= (1.0 - p[i]);
      cp += p[i];
    }

    REP(j, t[i] - 2)
      lp *= (1.0 - p[i]);

    ps[i] = 1.0 - cp;
    pl[i] = lp;
  }

  for (int i = n - 1; i >= 0; --i) {
    int I = i % 2;
    dp[I][0] = 0.0;
    for (int tt = 1; tt <= T; ++tt) {
      dp[I][tt] = dp[I][tt - 1];

      if (t[i] == 1) {
  	dp[I][tt] = 1.0 + dp[I ^ 1][tt - 1];
      } else {
      	if (tt - t[i] - 1 >= 0) 
  	  dp[I][tt] -= ps[i] * (1 + dp[I ^ 1][tt - t[i] - 1]);

  	if (tt - t[i] >= 0)
  	  dp[I][tt] -= pl[i] * (1.0 + dp[I ^ 1][tt - t[i]]);

  	dp[I][tt] *= (1.0 - p[i]);

  	dp[I][tt] += p[i] * (1.0 + dp[I ^ 1][tt - 1]);

  	if (tt - t[i] >= 0)
  	  dp[I][tt] += ps[i] * (1.0 + dp[I ^ 1][tt - t[i]]);
      }
    }
  }
  printf("%.10lf\n", dp[0][T]);

  return 0;
}