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

#define MAXN 2222
#define MOD 1000000007

int dp[MAXN][MAXN], dp2[MAXN][MAXN];

int main(int argc, char *argv[]){

  REP(i, MAXN) dp[0][i] = dp[i][0] = dp2[0][i] = 1;
  int N, M;
  scanf("%d%d", &N, &M);

  FOR(h, 1, MAXN - 1) {
    int s = 1;
    FOR(w, 1, MAXN - 1) {
      s = (s + dp[h-1][w]) % MOD;
      dp[h][w] = (dp[h][w-1] + s) % MOD;
      dp2[h][w] = ((dp[h][w-1] + s) % MOD - dp[h-1][w]) % MOD;
    }
  }

  //REP(i, 5) { REP(j, 5) printf(" %d", dp2[j][i]); printf("\n"); }
  FOR(h, 1, MAXN - 1) FOR(w, 0, MAXN - 1) {
    dp[h][w] = (dp[h][w] + dp[h-1][w]) % MOD;
    dp2[h][w] = (dp2[h][w] + dp2[h-1][w]) % MOD;
  }

  int ans = 0;
  REP(t, N) {
    FOR(s, 0, M - 2) {
      ans = (ans + (long long)dp2[t][s] * dp[N - t - 1][s] % MOD * (M - s - 1)) % MOD;
    }
  }
  if(ans < 0) ans += MOD;
  printf("%d\n", ans);
   
  return 0;
}