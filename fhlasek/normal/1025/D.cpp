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

inline long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }

#define MAXN 777
int N;
int A[MAXN];

bool dp[MAXN][MAXN][2];
bool g[MAXN][MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);

  REP(i, N) REP(j, N) g[i][j] = gcd(A[i], A[j]) > 1;

  dp[N][N][0] = dp[N][N][1] = true;
  REP(i, N) {
    dp[i][i][0] = dp[i][i][1] = true;
    dp[i][i + 1][0] = (i == 0) || gcd(A[i], A[i - 1]) > 1;
    dp[i][i + 1][1] = (i == N - 1) || gcd(A[i], A[i + 1]) > 1;
  }

  FOR(len, 2, N) {
    REP(start, N - len + 1) {
      int end = start + len;
      FOR(mid, start, end - 1) {
        bool ok = dp[start][mid][1] && dp[mid + 1][end][0];
        dp[start][end][0] |= ok && (start == 0 || g[start - 1][mid]);
        dp[start][end][1] |= ok && (end == N || g[end][mid]);
      }
    }
  }

  printf("%s\n", dp[0][N][0] ? "Yes" : "No");

  return 0;
}