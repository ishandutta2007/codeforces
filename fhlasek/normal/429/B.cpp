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

#define MAXN 1111
int a1[MAXN][MAXN], a2[MAXN][MAXN], b1[MAXN][MAXN], b2[MAXN][MAXN];

int N, M, a[MAXN][MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) REP(j, M) scanf("%d", &(a[i][j]));

  REP(i, N) REP(j, M) {
    a1[i][j] = a[i][j];
    if (i) a1[i][j] = max(a1[i][j], a[i][j] + a1[i-1][j]);
    if (j) a1[i][j] = max(a1[i][j], a[i][j] + a1[i][j-1]);
  }
  FORD(i, N - 1, 0) FORD(j, M - 1, 0) {
    a2[i][j] = a[i][j];
    if (i + 1 < N) a2[i][j] = max(a2[i][j], a[i][j] + a2[i+1][j]);
    if (j + 1 < M) a2[i][j] = max(a2[i][j], a[i][j] + a2[i][j+1]);
  }

  FORD(i, N - 1, 0) REP(j, M) {
    b1[i][j] = a[i][j];
    if (i + 1 < N) b1[i][j] = max(b1[i][j], a[i][j] + b1[i+1][j]);
    if (j) b1[i][j] = max(b1[i][j], a[i][j] + b1[i][j-1]);
  }
  REP(i, N) FORD(j, M - 1, 0) {
    b2[i][j] = a[i][j];
    if (i) b2[i][j] = max(b2[i][j], a[i][j] + b2[i-1][j]);
    if (j + 1 < M) b2[i][j] = max(b2[i][j], a[i][j] + b2[i][j+1]);
  }

  int best = 0;
  FOR(i, 1, N - 2) FOR(j, 1, M - 2) {
    // printf("i: %d j: %d %d %d %d %d\n", i, j, a1[i-1][j], b1[i][j-1], a2[i+1][j], b2[i][j+1]);
    // printf("i: %d j: %d %d %d %d %d\n", i, j, a1[i][j-1], b1[i-1][j], a2[i][j+1], b2[i+1][j] );
    best = max(best, a1[i-1][j] + b1[i][j-1] + a2[i+1][j] + b2[i][j+1]);
    best = max(best, a1[i][j-1] + b1[i+1][j] + a2[i][j+1] + b2[i-1][j]);
  }
  printf("%d\n", best);

  return 0;
}