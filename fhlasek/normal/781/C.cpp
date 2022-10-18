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

#define MAXN 1111111
vector<int> graph[MAXN];
int N, M, K;
bool visited[MAXN];
int ans[MAXN], A = 0;

void dfs(int v) {
  visited[v] = true;
  ans[A++] = v;
  REP(i, graph[v].size()) if (!visited[graph[v][i]]) {
    dfs(graph[v][i]);
    ans[A++] = v;
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &M, &K);
  REP(i, N) visited[i] = false;
  REP(i, N) graph[i].clear();
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(0);
  int C = (2 * N + K - 1) / K;
  REP(i, K) {
    int a = max(0, min(C, A - C * i));
    if (!a) { printf("1 1\n"); }
    else {
      printf("%d", a);
      REP(j, a) printf(" %d", ans[i * C + j] + 1);
      printf("\n");
    }
  }
  return 0;
}