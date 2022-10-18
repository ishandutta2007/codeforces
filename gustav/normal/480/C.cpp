#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int mod = 1000000007;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAXN 5005

int n, a, b, k;
int dp[2][MAXN];
int sum[MAXN];

int main(void) {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  for (int i = 1; i <= n; ++i) dp[0][i] = 1;
  dp[0][b] = 0;

  for (int i = 1; i <= k; ++i) {
    int I = i % 2;
    for (int j = 1; j <= n; ++j)
      sum[j] = (sum[j - 1] + dp[I ^ 1][j]) % mod;
    for (int j = 1; j <= n; ++j) {
      dp[I][j] = (sum[min(n, j + abs(j - b) - 1)] - sum[max(1, j - abs(j - b) + 1) - 1] + mod) % mod;
      dp[I][j] = (dp[I][j] - dp[I ^ 1][j] + mod) % mod;
    }
    dp[I][b] = 0;
  }

  printf("%d\n", dp[k % 2][a]);

  return 0;
}