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

#define MAXN 111
int ans[MAXN][MAXN];

int main(int argc, char *argv[]) {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  if (n > a * b) {
    printf("-1\n");
  }
  else {
    REP(i, a) {
      REP(j, b) {
        if (i & 1) ans[i][j] = n;
        else ans[i][b - j - 1] = n;
        n = max(0, n - 1);
      }
    }
    REP(i, a) { REP(j, b) { if (j) printf(" "); printf("%d", ans[i][j]); } printf("\n"); }
  }
  return 0;
}