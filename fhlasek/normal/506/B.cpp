/* Written by Filip Hlasek 2015 */
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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111

vector<int> graph[MAXN], rgraph[MAXN];
bool done[MAXN];

vector<int> vx;
int ans = 0;
void dfs1(int v) {
  done[v] = 1;
  REP(i, graph[v].size()) {
    int n = graph[v][i];
    if (!done[n]) dfs1(n);
  }
  vx.push_back(v);
}

vector<int> ngraph[MAXN];

int comp[MAXN], comp_size[MAXN];
void dfs2(int v, int c) {
  done[v] = 1;
  comp[v] = c;
  comp_size[c]++;
  REP(i, rgraph[v].size()) {
    int n = rgraph[v][i];
    if (!done[n]) dfs2(n, c);
    else if (comp[n] != c) {
      ngraph[c].push_back(comp[n]);
      ngraph[comp[n]].push_back(c);
    }
  }
}

bool dfs3(int v) {
  done[v] = true;
  bool ans = (comp_size[v] == 1);
//  printf("dfs3, v: %d ans: %d\n", v, (int)ans);
  REP(i, ngraph[v].size()) {
    int n = ngraph[v][i];
    if (!done[n]) {
      if (!dfs3(n)) ans = false;
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    graph[a].push_back(b);
    rgraph[b].push_back(a);
  }
  REP(i, N) if (!done[i]) dfs1(i);
  REP(i, N) done[i] = false;
  reverse(vx.begin(), vx.end());
  REP(i, N) if (!done[vx[i]]) dfs2(vx[i], i);
  REP(i, N) done[i] = false;
  ans = N;
  REP(i, N) if (!done[i] && comp_size[i] && dfs3(i)) ans--;
  /*
  REP(i, N) {
    printf("i: %d : %d\n", i, comp_size[i]);
    REP(j, ngraph[i].size()) printf("  %d\n", ngraph[i][j]);
  }*/
  printf("%d\n", ans);
  return 0;
}