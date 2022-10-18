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

#define MAXN 555
bool graph[MAXN][MAXN];
int N, M, deg[MAXN];
char ans[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int u, v;
    scanf("%d%d", &u, &v); u--; v--;
    deg[u]++; deg[v]++;
    graph[u][v] = graph[v][u] = true;
  }

  REP(i, N) REP(j, i) if (!graph[i][j]) {
    ans[i] = 'a';
    REP(k, N) if (k != i) {
      if (deg[k] == N - 1) ans[k] = 'b';
      else if (graph[i][k]) ans[k] = 'a';
      else ans[k] = 'c';
    }
    bool valid = true;
    REP(k, N) REP(l, k) {
      if (ans[k] == ans[l] && !graph[k][l]) valid = false;
      if (ans[k] == 'a' && ans[l] == 'c' && graph[k][l]) valid = false;
      if (ans[k] == 'c' && ans[l] == 'a' && graph[k][l]) valid = false;
    }
    if (valid) {
      printf("Yes\n");
      REP(i, N) printf("%c", ans[i]);
      printf("\n");
    }
    else printf("No\n");
    return 0;
  }
  printf("Yes\n");
  REP(i, N) printf("b");
  printf("\n");
  return 0;
}