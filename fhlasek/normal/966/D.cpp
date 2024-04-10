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
#include <unordered_set>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 333333
vector<int> graph[MAXN];
int N, M;

unordered_set<long long> edges;

int neighbor[MAXN];

bool done[MAXN];
vector<int> component;

void dfs(int a) {
  done[a] = true;
  component.push_back(a);
  REP(i, graph[a].size()) if (neighbor[graph[a][i]] && !done[graph[a][i]]) {
    dfs(graph[a][i]);
  }
}

int Prev[MAXN], Dist[MAXN];
queue<int> q;

void bfs(int a) {
  REP(j, component.size()) Dist[component[j]] = N + 1;
  Dist[a] = 0;
  q.push(a);
  while (!q.empty()) {
    a = q.front();
    q.pop();
    REP(i, graph[a].size()) if (neighbor[graph[a][i]]) {
      int b = graph[a][i];
      if (Dist[b] > Dist[a] + 1) {
        Dist[b] = Dist[a] + 1;
        q.push(b);
        Prev[b] = a;
      }
    }
  }
  REP(j, component.size()) if (Dist[component[j]] == 2) {
    int b = component[j];
    printf("5\n1 %d %d %d %d %d\n", b + 1, Prev[b] + 1, Prev[Prev[b]] + 1, b + 1, N);
    return;
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;

    edges.insert((long long)u * N + v);
    edges.insert((long long)v * N + u);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  if (edges.count(N - 1)) {
    printf("1\n1 %d\n", N);
    return 0;
  }

  REP(i, graph[0].size()) neighbor[graph[0][i]] = true;

  REP(i, graph[0].size()) {
    int a = graph[0][i];
    if (edges.count((long long)a * N + N - 1)) {
      printf("2\n1 %d %d\n", a + 1, N);
      return 0;
    }
  }

  REP(i, graph[0].size()) {
    int a = graph[0][i];
    REP(j, graph[a].size()) {
      int b = graph[a][j];
      if (b && !neighbor[b] && edges.count((long long)b * N + N - 1)) {
        printf("3\n1 %d %d %d\n", a + 1, b + 1, N);
        return 0;
      }
    }
  }

  REP(i, graph[0].size()) {
    int a = graph[0][i];
    REP(j, graph[a].size()) {
      int b = graph[a][j];
      if (b && !neighbor[b]) {
        printf("4\n1 %d %d 1 %d\n", a + 1, b + 1, N);
        return 0;
      }
    }
  }

  REP(i, graph[0].size()) {
    int a = graph[0][i];

    if (done[a]) continue;

    component.clear();
    dfs(a);

    REP(i, component.size()) {
      int deg = 0;
      int a = component[i];
      REP(j, graph[a].size()) if (neighbor[graph[a][j]]) deg++;

      if (deg == (int)component.size() - 1) continue;

      bfs(a);
      return 0;
    }

  }

  printf("-1\n");

  return 0;
}