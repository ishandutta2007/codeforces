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

#define MAXN 1002
#define MAX 10005
#define MOD 1000000007
int N, a[MAXN];
int dp[MAXN][2 * MAX + 2];

void add_dp(int n, int diff, int change) {
  dp[n + 1][diff + MAX + change] += dp[n][diff + MAX];
  if (dp[n + 1][diff + MAX + change] >= MOD)
    dp[n + 1][diff + MAX + change] -= MOD;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", a + i);
    dp[i + 1][a[i] + MAX]++; if (dp[i][a[i] + MAX] >= MOD) dp[i][a[i] + MAX] -= MOD;
    dp[i + 1][-a[i] + MAX]++; if (dp[i][-a[i] + MAX] >= MOD) dp[i][-a[i] + MAX] -= MOD;
    FOR(j, -MAX, +MAX) if (dp[i][j + MAX]) { add_dp(i, j, a[i]); add_dp(i, j, -a[i]); }
  }
  int ans = 0;
  REP(i, N + 1) ans = (ans + dp[i][MAX]) % MOD;
  printf("%d\n", ans);
  return 0;
}