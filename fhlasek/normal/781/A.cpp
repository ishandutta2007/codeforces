/* Written by Filip Hlasek 2017 */
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

#define MAXN 222222
vector<int> graph[MAXN];
int color[MAXN];

void dfs(int v, int f) {
  int last = -1;
  REP(i, graph[v].size()) if (graph[v][i] != f) {
    last++;
    while (last == color[v] || last == color[f]) last++;
    color[graph[v][i]] = last;
    dfs(graph[v][i], v);
  }
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  color[0] = 0;
  dfs(0, 0);
  int k = 0;
  REP(i, N) k = max(k, color[i]);
  printf("%d\n", k + 1);
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", color[i] + 1);
  }
  printf("\n");
  return 0;
}