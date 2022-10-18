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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
#define LOG 18
#define A 10

vector<int> graph[MAXN];
int N;
int father[MAXN], depth[MAXN], root = 0;
int _lca[MAXN][LOG];
int pq[MAXN][LOG][A + 1], PQ[MAXN][LOG];

void ins(int s[], int &S, int v) {
  REP(i, S) {
    if (s[i] == v) return;
    if (s[i] > v) swap(s[i], v);
  }
  if (S < A) s[S++] = v;
}

void merge(int s1[], int &S1, int s2[], int &S2) {
  REP(i, S2) ins(s1, S1, s2[i]);
}

void dfs(int v, int f = 0) {
  father[v] = f;
  REP(i, graph[v].size()) {
    int n = graph[v][i];
    if (f == n) continue;
    depth[n] = depth[v] + 1;
    dfs(n, v);
  }
}

void initLCA() {
  REP(i, N) _lca[i][0] = father[i];
  REP(l, LOG - 1) REP(i, N) {
    _lca[i][l+1] = _lca[_lca[i][l]][l];
    merge(pq[i][l + 1], PQ[i][l + 1], pq[i][l], PQ[i][l]);
    merge(pq[i][l + 1], PQ[i][l + 1], pq[_lca[i][l]][l], PQ[_lca[i][l]][l]);
  }
}

int ans[A + 1], ANS;

int up(int v, int dist) {
  REP(i, LOG) if (dist & (1 << i)) {
    merge(ans, ANS, pq[v][i], PQ[v][i]);
    v = _lca[v][i];
  }
  return v;
}

void lca(int a, int b) {
  /*
  REP(i, N) {
    printf("i = %d\n", i + 1);
    REP(l, LOG - 1) {
      for (set<int>::iterator it = pq[i][l].begin(); it != pq[i][l].end(); ++it) {
        printf(" %d", *it);
      }
      printf("\n");
    }
  }
  */
  ANS = 0;
  if (depth[b] > depth[a]) swap(a, b);
  a = up(a, depth[a] - depth[b]);
  if (a == b) {
    merge(ans, ANS, pq[a][0], PQ[a][0]);
    return;
  }
  FORD(i, LOG - 1, 0) if (_lca[a][i] != _lca[b][i]) {
    merge(ans, ANS, pq[a][i], PQ[a][i]);
    a = _lca[a][i];
    merge(ans, ANS, pq[b][i], PQ[b][i]);
    b = _lca[b][i];
  }
  merge(ans, ANS, pq[a][1], PQ[a][1]);
  merge(ans, ANS, pq[b][0], PQ[b][0]);
}

int c[MAXN];

int main(int argc, char *argv[]) {
  int M, Q;
  scanf("%d%d%d", &N, &M, &Q);
  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  REP(i, M) {
    scanf("%d", c + i); c[i]--;
    ins(pq[c[i]][0], PQ[c[i]][0], i + 1);
  }
  dfs(0);
  initLCA();
  REP(i, Q) {
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a); l--; r--;
    lca(l, r);
    printf("%d", min(a, ANS));
    REP(i, min(a, ANS)) printf(" %d", ans[i]);
    printf("\n");
  }

  return 0;
}