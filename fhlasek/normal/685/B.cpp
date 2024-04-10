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

#define MAXN 333333
vector<int> graph[MAXN];
int N, P[MAXN];

int sz[MAXN], centroid[MAXN], max_sub[MAXN], max_sub_id[MAXN];

void dfs(int v) {
  sz[v] = 1;
  centroid[v] = v;
  REP(i, graph[v].size()) {
    int n = graph[v][i];
    dfs(n);
    sz[v] += sz[n];
    if (sz[n] > max_sub[v]) { max_sub[v] = sz[n]; max_sub_id[v] = n; }
  }
  if (sz[v] < 2 * max_sub[v]) {
    centroid[v] = centroid[max_sub_id[v]];
    while (sz[v] < 2 * (sz[v] - sz[centroid[v]])) centroid[v] = P[centroid[v]];
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  int Q;
  scanf("%d", &Q);
  REP(i, N - 1) {
    scanf("%d", P + i + 1); P[i + 1]--;
    graph[P[i + 1]].push_back(i + 1);
  }
  dfs(0);
  while (Q--) {
    int v;
    scanf("%d", &v);
    printf("%d\n", centroid[v - 1] + 1);
  }
  
  return 0;
}