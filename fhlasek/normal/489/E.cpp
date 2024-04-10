/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111
int N, L;
int X[MAXN], B[MAXN];

double dp[MAXN];
int Prev[MAXN];

int ans[MAXN], A;

bool solve(double score) {
  REP(i, N + 1) dp[i] = -1000000000;
  dp[0] = 0;

  REP(i, N) {
    int x = i ? X[i - 1] : 0;
    // printf("i: %d dp: %.15lf\n", i, dp[i]);
    FOR(j, i + 1, N) {
      int dx = X[j - 1] - x;
      double frustration = sqrt(abs(dx - L));
      double pict = B[j - 1];
      double gain = score * pict - frustration;
      if (dp[i] + gain > dp[j]) {
        dp[j] = dp[i] + gain;
        Prev[j] = i;
      }
    }
  }

  // printf("score: %.15lf dp: %.15lf\n", score, dp[N]);

  if (dp[N] < 0) return false;

  int x = N;
  A = 0;
  while (x) {
    ans[A++] = x;
    x = Prev[x];
  }

  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &L);
  REP(i, N) scanf("%d%d", X + i, B + i);
  double left = 0, right = 2000000;
  while (right - left > 1e-10) {
    // printf("left: %.9lf right: %.9lf\n", left, right);
    double middle = (left + right) / 2;
    if (solve(middle)) right = middle;
    else left = middle;
  }
  solve(left);
  reverse(ans, ans + A);
  REP(i, A) { if (i) printf(" "); printf("%d", ans[i]); } printf("\n");
  return 0;
}