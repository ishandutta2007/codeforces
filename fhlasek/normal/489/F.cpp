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

int N, M, MOD;

#define MAXN 1111
char m[MAXN][MAXN];

int dp[MAXN][MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &M, &MOD);
  REP(i, M) scanf("%s", m[i]);
  int ones = 0;
  REP(j, N) {
    int cnt = 0;
    REP(i, M) cnt += m[i][j] - '0';
    ones += cnt == 1;
  }
  dp[M][ones] = 1;

  FOR(r, M, N - 1) {
    FOR(ones, 0, N) {
      int twos = (2 * r - ones) / 2, zeros = N - ones - twos;
      // if (dp[r][ones]) printf("row: %d ones: %d dp: %d\n", r, ones, dp[r][ones]);
      dp[r + 1][ones + 2] = (dp[r + 1][ones + 2] + (long long)dp[r][ones] * zeros * (zeros - 1) / 2) % MOD;
      dp[r + 1][ones] = (dp[r + 1][ones] + (long long)dp[r][ones] * zeros * ones) % MOD;
      if (ones >= 2) {
        dp[r + 1][ones - 2] = (dp[r + 1][ones - 2] + (long long)dp[r][ones] * ones * (ones - 1) / 2) % MOD;
      }
    }
  }

  printf("%d\n", dp[N][0]);
  return 0;
}