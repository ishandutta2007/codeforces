#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 505;

int N, M;
int adj[MAXN][MAXN];
int a[MAXN][MAXN];

void fw() {
  REP(k, N) REP(i, N) REP(j, N)
    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main(void) 
{
  scanf("%d%d", &N, &M);

  REP(i, M) {
    int x, y; 
    scanf("%d%d", &x, &y); --x; --y;
    adj[x][y] = 1;
    adj[y][x] = 1;
  }

  memset(a, 0x3f, sizeof a);
  REP(i, N) a[i][i] = 0;
  REP(i, N) REP(j, N)
    if (adj[i][j]) a[i][j] = 1;
  fw();
  int path1 = a[0][N - 1];

  memset(a, 0x3f, sizeof a);
  REP(i, N) a[i][i] = 0;
  REP(i, N) REP(j, N)
    if (!adj[i][j]) a[i][j] = 1;
  fw();
  int path2 = a[0][N - 1];

  if (path1 > N || path2 > N) {
    puts("-1");
    exit(0);
  }

  assert(min(path1, path2) == 1);
  printf("%d\n", max(path1, path2));

  return 0;
}