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

#define MAXN 444444
int N;
vector<int> graph[MAXN];

int f[MAXN];
int sz[MAXN];
int max_cut[MAXN];
int max_cut_up[MAXN];

int order[MAXN], O = 0;
void dfs(int v) {
  order[O++] = v;
  sz[v] = 1;
  max_cut[v] = 0;
  REP(i, graph[v].size()) {
    int n = graph[v][i];
    if (n != f[v]) {
      f[n] = v;
      dfs(n);
      sz[v] += sz[n];
      max_cut[v] = max(max_cut[v], max_cut[n]);
    }
  }
  if (sz[v] * 2 <= N) max_cut[v] = sz[v];
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N - 1) {
    int u, v;
    scanf("%d%d", &u, &v); u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(0);
  REP(i, N) {
    int v = order[i];
    int best = max_cut_up[v], bestid = -1, second = 0, secondid = -1;
    REP(j, graph[v].size()) {
      int n = graph[v][j];
      if (n == f[v]) continue;
      if (max_cut[n] > second) { second = max_cut[n]; secondid = j; }
      if (second > best) { swap(best, second); swap(bestid, secondid); }
    }
    REP(j, graph[v].size()) {
      int n = graph[v][j];
      if (n == f[v]) continue;
      if (bestid == j) max_cut_up[n] = second;
      else max_cut_up[n] = best;
      if (2 * (N - sz[n]) <= N) max_cut_up[n] = N - sz[n];
    }
  }

  REP(i, N) {
    bool ok = true;
    REP(j, graph[i].size()) {
      int n = graph[i][j];
      if (f[i] == n) continue;
      if (2 * (sz[n] - max_cut[n]) > N) ok = false;
    }
    if (2 * (N - sz[i] - max_cut_up[i]) > N) ok = false;
    if (i) printf(" ");
    if (ok) printf("1");
    else printf("0");
  }
  printf("\n");
  return 0;
}