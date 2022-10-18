/* Written by Filip Hlasek 2020 */
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

#define MAXN 111111

vector<int> graph[MAXN];
int N, A, B, DA, DB;

int vis[MAXN], VIS = 0, dist[MAXN];

int bfs(int v) {
  VIS++;
  queue<int> q;
  dist[v] = 0; vis[v] = VIS;
  q.push(v);
  while (!q.empty()) {
    v = q.front();
    q.pop();
    REP(i, graph[v].size()) if (vis[graph[v][i]] != VIS) {
      vis[graph[v][i]] = VIS;
      dist[graph[v][i]] = dist[v] + 1;
      q.push(graph[v][i]);
    }
  }
  return v;
}

bool alice() {
  if (2 * DA >= DB) return true;
  int furthest = bfs(A);
  if (dist[B] <= DA) return true;
  int furthest2 = bfs(furthest);
  return dist[furthest2] <= 2 * DA;  
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d%d", &N, &A, &B, &DA, &DB);
    REP(i, N) graph[i].clear();
    A--; B--;
    REP(i, N - 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--; v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    printf("%s\n", alice() ? "Alice" : "Bob");
  }
	
	return 0;
}