/* Written by Filip Hlasek 2013 */
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

#define MOD 1000000007
#define MAXN 55
int dp[2][4*MAXN][MAXN][MAXN];
bool pos[2][4*MAXN][MAXN][MAXN];
int comb[MAXN][MAXN];

int main(int argc, char *argv[]){
  int a50 = 0, a100 = 0, K, N;
  REP(i, MAXN) REP(j, MAXN) {
    if(j == 0 || i == j) comb[i][j] = 1;
    else if(i > j) comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
  }
  scanf("%d%d", &N, &K);
  REP(i, N) { int tmp; scanf("%d", &tmp); if(tmp == 50) a50++; else a100++; }
  dp[0][0][a50][a100] = 1;
  pos[0][0][a50][a100] = true;
  REP(step, 4 * N) REP(n50, a50 + 1) REP(n100, a100 + 1) {
    if (pos[0][step][n50][n100]) {
      REP(p50, n50 + 1) REP(p100, n100 + 1) {
        if (p50 + p100 < 1) continue;
        if (p50 * 50 + p100 * 100 > K) break;
        pos[1][step+1][n50-p50][n100-p100] = true;
        dp[1][step+1][n50-p50][n100-p100] = (dp[1][step+1][n50-p50][n100-p100] + ((long long)dp[0][step][n50][n100] * comb[n50][p50]) % MOD * comb[n100][p100]) % MOD;
      }
    }
    if (pos[1][step][n50][n100]) {
      REP(p50, a50 - n50 + 1) REP(p100, a100 - n100 + 1) {
        if (p50 + p100 < 1) continue;
        if (p50 * 50 + p100 * 100 > K) break;
        pos[0][step+1][n50+p50][n100+p100] = true;
        dp[0][step+1][n50+p50][n100+p100] = (dp[0][step+1][n50+p50][n100+p100] + ((long long)dp[1][step][n50][n100] * comb[a50-n50][p50]) % MOD * comb[a100-n100][p100]) % MOD;
      }
    }
  }
  REP(step, 4 * N + 1) if (pos[1][step][0][0]) {
    printf("%d\n%d\n", step, dp[1][step][0][0]);
    return 0;
  }
  printf("-1\n0\n");
  return 0;
}