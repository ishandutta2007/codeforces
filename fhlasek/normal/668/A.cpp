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

#define MAXN 1111
int A[MAXN][MAXN];

#define MAXQ 111111
int T[MAXQ], R[MAXQ], C[MAXQ], X[MAXQ];

int main(int argc, char *argv[]) {
  int N, M, Q;
  scanf("%d%d%d", &N, &M, &Q);
  REP(i, Q) {
    scanf("%d", T + i);
    if (T[i] == 1) scanf("%d", R + i);
    else if (T[i] == 2) scanf("%d", C + i);
    else scanf("%d%d%d", R + i, C + i, X + i);
    R[i]--; C[i]--;
  }
  FORD(i, Q - 1, 0) {
    if (T[i] == 3) A[R[i]][C[i]] = X[i];
    else if (T[i] == 1) {
      int tmp = A[R[i]][M - 1];
      FORD(j, M - 2, 0) A[R[i]][j + 1] = A[R[i]][j];
      A[R[i]][0] = tmp;
    }
    else {
      int tmp = A[N - 1][C[i]];
      FORD(j, N - 2, 0) A[j + 1][C[i]] = A[j][C[i]];
      A[0][C[i]] = tmp;
    }
  }
  REP(i, N) {
    REP(j, M) {
      if (j) printf(" ");
      printf("%d", A[i][j]);
    }
    printf("\n");
  }

  return 0;
}