/* Written by Filip Hlasek 2017 */
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

#define MAXN 111
int N, M;
int g[MAXN][MAXN];

#define INF MAXN * MAXN * 555
int a[MAXN], b[MAXN];

int solve(int a0, bool print=false) {
  a[0] = a0;
  REP(j, M) {
    if (g[0][j] < a[0]) return INF;
    b[j] = g[0][j] - a[0];
  }
  REP(i, N) {
    if (g[i][0] < b[0]) return INF;
    a[i] = g[i][0] - b[0];
  }
  REP(i, N) REP(j, M) if (g[i][j] != a[i] + b[j]) return INF;
  int ans = 0;
  REP(i, N) ans += a[i];
  REP(j, M) ans += b[j];
  if (print) {
    REP(i, N) REP(j, a[i]) printf("row %d\n", i + 1);
    REP(j, M) REP(i, b[j]) printf("col %d\n", j + 1);
  }
  return ans;
}


int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) REP(j, M) scanf("%d", &(g[i][j]));
  int ans = INF, besti = 0;
  REP(i, 501) {
    int s = solve(i);
    if (s < ans) {
      ans = s;
      besti = i;
    }
  }
  printf("%d\n", ans == INF ? -1 : ans);
  solve(besti, true);
  return 0;
}