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

#define MAXN 55
int A[MAXN][MAXN];
int ans[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) REP(j, N) {
    scanf("%d", &(A[i][j]));
  }
  FOR(n, 1, N) {
    REP(i, N) if (!ans[i]) {
      bool ok = true;
      REP(j, N) if (j != i && !ans[j] && A[i][j] != n) { ok = false; break; }
      if (!ok) continue;
      ans[i] = n;
      break;
    }
  }
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}