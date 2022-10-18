/* Written by Filip Hlasek 2016 */
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
#define MAXN 222222
int dp[2][MAXN];

int main(int argc, char *argv[]) {
  int A, B, K, T;
  scanf("%d%d%d%d", &A, &B, &K, &T);
  K = 2 * K + 1;
  dp[0][0] = 1;
  REP(t, T) {
    int a = t % 2, b = 1 - a;
    int ans = 0;
    REP(i, K * (t + 1) + 1) {
      ans += dp[a][i];
      if (ans >= MOD) ans -= MOD;
      if (i >= K) {
        ans -= dp[a][i - K];
        if (ans < 0) ans += MOD;
      }
      dp[b][i] = ans;
    }
  }
  int ans = 0;
  /*
  REP(i, T * K  + 1) REP(j, T * K + 1) {
    if (i + A > j + B) {
      ans = (ans + (long long)dp[T % 2][i] * dp[T % 2][j]) % MOD;
    }
  }
  */
  int tmp = 0, j = 0;
  REP(i, T * K + 1) {
    while (i + A > j + B) tmp = (tmp + dp[T % 2][j++]) % MOD;
    ans = (ans + (long long)dp[T % 2][i] * tmp) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}