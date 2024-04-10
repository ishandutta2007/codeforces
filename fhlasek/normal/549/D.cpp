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

#define MAXN 111
int N, M;
char a[MAXN][MAXN];
int A[MAXN][MAXN];
long long c[MAXN][MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%s", a[i]);
  REP(i, N) REP(j, M) A[i][j] = (a[i][j] == a[N - 1][M - 1]) ? 1 : -1;
  int ans = 0;
  FORD(i, N - 1, 0) FORD(j, M - 1, 0) {
    c[i][j] = c[i + 1][j] + c[i][j + 1] - c[i + 1][j + 1];
    if (c[i][j] != A[i][j]) {
      ans++;
      c[i][j] = A[i][j];
    }
  }
  printf("%d\n", ans);
  return 0;
}