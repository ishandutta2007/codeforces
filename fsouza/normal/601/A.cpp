#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define INF 1000000000
#define MAXN 400

using namespace std;

typedef long long lint;

int rail[MAXN][MAXN];
int road[MAXN][MAXN];
int mark[MAXN], dist[MAXN];

int dijkstra(int n, int adj[MAXN][MAXN]) {
  for (int i = 0; i < n; ++i) {
    dist[i] = INF;
    mark[i] = 0;
  }
  dist[0] = 0;
  int cur = 0;

  while (cur != -1) {
    mark[cur] = 1;
    for (int u = 0; u < n; ++u)
      if (!mark[u] && adj[cur][u] && dist[u] > dist[cur]+1)
    dist[u] = dist[cur] + 1;
    cur = -1;
    for (int v = 0; v < n; ++v)
      if (!mark[v] && (cur == -1 || dist[v] < dist[cur]))
    cur = v;
  }

  return dist[n-1];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      rail[i][j] = 0;
  
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    rail[a][b] = rail[b][a] = 1;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      road[i][j] = 1 - rail[i][j];

  int ret = max(dijkstra(n, rail), dijkstra(n, road));
  if (ret == INF) ret = -1;
  printf("%d\n", ret);
  
  return 0;
}