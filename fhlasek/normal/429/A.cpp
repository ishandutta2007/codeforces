/* Written by Filip Hlasek 2014 */
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
int N;
vector<int> graph[MAXN];

vector<int> ans;

int start[MAXN], end[MAXN];

void dfs(int v, int f, int s1, int s2) {
  int s = s2;
  if (start[v] ^ end[v] ^ s2) {
    ans.push_back(v);
    s = 1 - s;
  }
  REP(i, graph[v].size()) if (graph[v][i] != f) dfs(graph[v][i], v, s, s1);
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  REP(i, N) scanf("%d", start + i);
  REP(i, N) scanf("%d", end + i);

  dfs(0, -1, 0, 0);

  printf("%d\n", (int)ans.size());
  REP(i, ans.size()) printf("%d\n", ans[i] + 1);
  return 0;
}