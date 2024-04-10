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

#define LOG 20
#define MAXN 222222
int N, A[MAXN], F[MAXN], W[MAXN];
vector<int> childern[MAXN];

int lca[MAXN][LOG];
long long sum[MAXN][LOG];
int ans[MAXN];

void dfs(int v) {

  lca[v][0] = F[v];
  sum[v][0] = W[v];
  REP(l, LOG - 1) {
    lca[v][l + 1] = lca[lca[v][l]][l];
    sum[v][l + 1] = sum[v][l] + sum[lca[v][l]][l];
  }

  int x = v;
  long long s = 0;
  FORD(l, LOG - 1, 0) if (s + sum[x][l] <= A[v]) {
    s += sum[x][l];
    x = lca[x][l];
  }

  if (x) ans[F[x]]--;

  REP(i, childern[v].size()) {
    dfs(childern[v][i]);
    ans[v] += 1 + ans[childern[v][i]];
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  FOR(i, 1, N - 1) {
    scanf("%d%d", F + i, W + i); F[i]--;
    childern[F[i]].push_back(i);
  }
  dfs(0);
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}