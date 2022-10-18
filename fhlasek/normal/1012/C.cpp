/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define INF 1000000000
#define MAXN 5005
int N;
int A[MAXN];

int dp[MAXN][MAXN][3];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);

  REP(k, N + 1) REP(l, 3) dp[0][k][l] = INF;
  dp[0][0][2] = 0;

  REP(i, N) {
    REP(k, N + 1) REP(l, 3) dp[i + 1][k][l] = INF;
    REP(k, N + 1) REP(l, 3) if (dp[i][k][l] != INF) {
      if (l == 0) {
        dp[i + 1][k][1] = min(dp[i + 1][k][1], dp[i][k][l]);
      } else if (l == 1) {
        dp[i + 1][k][2] = min(dp[i + 1][k][2], dp[i][k][l]);
        int prev = min(A[i - 2] - 1, A[i - 1]);
        int next = (i + 1) < N ? A[i + 1] : 0;
        int cost = dp[i][k][l] + max(0, prev - A[i] + 1) + max(0, next - A[i] + 1);
        dp[i + 1][k + 1][0] = min(dp[i + 1][k + 1][0], cost);
      } else if (l == 2) {
        dp[i + 1][k][2] = min(dp[i + 1][k][2], dp[i][k][l]);
        int prev = i ? A[i - 1] : 0;
        int next = (i + 1) < N ? A[i + 1] : 0;
        int cost = dp[i][k][l] + max(0, prev - A[i] + 1) + max(0, next - A[i] + 1);
        dp[i + 1][k + 1][0] = min(dp[i + 1][k + 1][0], cost);
      }
      // printf("i: %d k: %d l: %d dp: %d\n", i, k, l, dp[i][k][l]);
    }
  }
  REP(i, (N + 1) / 2) {
    if (i) printf(" ");
    printf("%d", min(dp[N][i + 1][0], min(dp[N][i + 1][1], dp[N][i + 1][2])));
  }
  printf("\n");
  return 0;
}