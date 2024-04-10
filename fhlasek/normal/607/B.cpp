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

#define MAXN 1111
int dp[MAXN][MAXN];

int N, A[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  FOR(r, 1, N) FORD(l, r - 1, 0) {
    if (l + 1 == r) { dp[l][r] = 1; continue; }
    if (l + 2 == r) { dp[l][r] = 1 + (A[l] != A[l + 1]); continue; }
    dp[l][r] = N;
    if (A[l] == A[r - 1]) { dp[l][r] = dp[l + 1][r - 1]; }
    FOR(i, 1, r - l - 1) dp[l][r] = min(dp[l][r], dp[l][i + l] + dp[i + l][r]);
  }
  printf("%d\n", dp[0][N]);
  return 0;
}