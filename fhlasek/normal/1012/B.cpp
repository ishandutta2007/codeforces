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

#define MAXN 222222
int N, M, Q;
int byX[MAXN], byY[MAXN];
vector<int> graph[MAXN];
bool done[MAXN];

void dfs(int v) {
  done[v] = true;
  REP(i, graph[v].size()) if (!done[graph[v][i]]) dfs(graph[v][i]);
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &M, &Q);
  if (!Q) { printf("%d\n", N + M - 1); return 0; }
  REP(i, Q) {
    int X, Y;
    scanf("%d%d", &X, &Y);
    X--; Y--;
    if (byX[X]) {
      graph[byX[X] - 1].push_back(i);
      graph[i].push_back(byX[X] - 1);
    }
    byX[X] = i + 1;
    if (byY[Y]) {
      graph[byY[Y] - 1].push_back(i);
      graph[i].push_back(byY[Y] - 1);
    }
    byY[Y] = i + 1;
  }
  int ans = -1;
  REP(i, Q) if (!done[i]) {
    ans++;
    dfs(i);
  }
  REP(i, N) if (!byX[i]) ans++;
  REP(i, M) if (!byY[i]) ans++;
  printf("%d\n", ans);
  return 0;
}