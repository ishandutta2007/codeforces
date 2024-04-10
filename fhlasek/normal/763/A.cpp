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

#define MAXN 111111
int N;
vector<int> graph[MAXN];
int degree[MAXN];
int C[MAXN];

queue<int> q;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    degree[a]++; degree[b]++;
  }
  REP(i, N) scanf("%d", C + i);

  REP(i, N) if (degree[i] == 1) q.push(i);

  while (!q.empty()) {
    int v = q.front(); q.pop();
    REP(i, (int)graph[v].size()) {
      int u = graph[v][i];
      if (degree[u] && C[u] == C[v]) {
        degree[v]--;
        degree[u]--;
        if (degree[u] == 1) q.push(u);
      }
    }
  }

  int best = 0;
  REP(i, N) if (degree[i] > degree[best]) best = i;
  bool ok = true;
  REP(i, N) if (degree[i] > 1 && i != best) { ok = false; break; }
  if (ok) printf("YES\n%d\n", best + 1);
  else printf("NO\n");

  return 0;
}