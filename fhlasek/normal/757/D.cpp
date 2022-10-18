/* Written by Filip Hlasek 2017 */
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
int dp[80][1 << 20];

int N;
char input[111];
bool b[111];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  scanf("%s", input);
  REP(i, N) b[i] = input[i] - '0';

  REP(i, N) dp[i][0] = 1;
  int ans = 0;
  REP(i, N) {
    int n = 0;
    REP(j, N) {
      if (i + j >= N) break;
      n = 2 * n + b[i + j];
      if (!n) continue;
      if (n > 20) break;
      // printf("i: %d n: %d\n", i, n);
      REP(mask, 1 << 20) {
        int nmask = (mask | (1 << (n - 1)));
        dp[i + j + 1][nmask] += dp[i][mask];
        if (dp[i + j + 1][nmask] >= MOD) {
          dp[i + j + 1][nmask] -= MOD;
        }
      }
    }
    // REP(mask, 1 << 3) printf("i: %d mask: %d dp: %d\n", i, mask, dp[i + 1][mask]);
    REP(j, 20) ans = (ans + dp[i + 1][(1 << (j + 1)) - 1]) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}