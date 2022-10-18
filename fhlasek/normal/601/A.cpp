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

#define MAXN 444

int d[MAXN][MAXN];
int D1[MAXN], D2[MAXN];

int main(int argc, char *argv[]) {
  int N, M, u, v;
  scanf("%d%d", &N, &M);
  REP(i, M) { scanf("%d%d", &u, &v); d[u - 1][v - 1] = d[v - 1][u - 1] = 1; }
  REP(i, N) D1[i] = D2[i] = MAXN;
  D1[0] = D2[0] = 0;

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    REP(i, N) if (d[v][i] == 0 && D1[i] > D1[v] + 1) {
      D1[i] = D1[v] + 1;
      q.push(i);
    }
  }

  q.push(0);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    REP(i, N) if (d[v][i] == 1 && D2[i] > D2[v] + 1) {
      D2[i] = D2[v] + 1;
      q.push(i);
    }
  }

  int ans = max(D1[N - 1], D2[N - 1]);
  if (ans == MAXN) ans = -1;
  printf("%d\n", ans);

  return 0;
}