/* Written by Filip Hlasek 2015 */
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

#define MAXN 33333
#define SQRT 250

int dp[MAXN][2 * SQRT + 1];
int gem[MAXN];

int main(int argc, char *argv[]) {
  int N, D;
  scanf("%d%d", &N, &D);
  REP(i, N) {
    int p;
    scanf("%d", &p);
    gem[p]++;
  }
  REP(i, MAXN) REP(j, 2 * SQRT + 1) dp[i][j] = - MAXN;
  dp[D][SQRT] = gem[D];
  REP(i, MAXN) REP(j, 2 * SQRT + 1) if (dp[i][j] >= 0) {
    int d = j - SQRT + D;
    int n = i + d;
    if (d - 1 > 0 && n - 1 < MAXN) dp[n - 1][j - 1] = max(dp[n - 1][j - 1], dp[i][j] + gem[n - 1]);
    if (n < MAXN) dp[n][j] = max(dp[n][j], dp[i][j] + gem[n]);
    if (n + 1 < MAXN) dp[n + 1][j + 1] = max(dp[n + 1][j + 1], dp[i][j] + gem[n + 1]);
  }

  int ans = 0;
  REP(i, 30001) REP(j, 2 * SQRT + 1) ans = max(ans, dp[i][j]);
  printf("%d\n", ans);
  return 0;
}