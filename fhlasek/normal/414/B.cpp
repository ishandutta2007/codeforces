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

int N, K;
#define MAXN 2222
int dp[MAXN][MAXN];
#define MOD 1000000007

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &K);
  dp[0][1] = 1;
  REP(k, K) FOR(n, 1, N) if (dp[k][n]) for (int d = 1; n * d <= N; ++d) {
    dp[k + 1][n * d] += dp[k][n];
    if (dp[k + 1][n * d] >= MOD) dp[k + 1][n * d] -= MOD;
  }
  int ans = 0;
  FOR(n, 1, N) ans = (ans + dp[K][n]) % MOD;
  printf("%d\n", ans);
  return 0;
}