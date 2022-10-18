#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 300005;
const int MAXL = 19;

vector< int > T[MAXN];

int tick;
int dis[MAXN];
int preorder[MAXN];
int wei[MAXN];
int maxc[MAXN];
int p[MAXN];
int anc[MAXN][MAXL];

void dfs(int i) {
  wei[i] = 1;
  dis[i] = tick++;
  preorder[dis[i]] = i;

  maxc[i] = 0;

  for (int j : T[i]) {
    dfs(j);
    wei[i] += wei[j];
    maxc[i] = max(maxc[i], wei[j]);
  }
}

bool is_centroid(int i, int c) {
  if (maxc[c] * 2 > wei[i]) return false;
  if ((wei[i] - wei[c]) * 2 > wei[i]) return false;
  return true;
}

int test(int i, int j) {
  if (is_centroid(i, j)) return j;

  for (int lg = MAXL - 1; lg >= 0; --lg) {
    int a = anc[j][lg];
    if (wei[a] * 2 < wei[i]) j = a;
  }

  if (j != i) j = p[j];
  if (is_centroid(i, j)) return j;

  return -1;
}

// int get_centroid(int i) {
//   int cnt = 0;
//   for (;;) {
//     ++cnt;
//     if (cnt > 40) assert(false);
//     int r = rand() % wei[i];
//     int c = test(i, preorder[dis[i] + r]);
//     if (c != -1) return c;
//   }
//   assert(false);
// }

int centroid[MAXN];

void calc(int i) {
  for (int j : T[i]) {
    calc(j);
    int cand = test(i, centroid[j]);
    if (cand != -1) centroid[i] = cand;
  }
  if (is_centroid(i, i)) centroid[i] = i;
  assert(centroid[i] != -1);
}

int main(void) 
{
  srand(12345);
  int n, q;
  scanf("%d%d", &n, &q);

  FOR(i, 2, n + 1) {
    scanf("%d", p + i);
    T[p[i]].push_back(i);
  }

  p[1] = 1;
  dfs(1);

  FOR(i, 1, n + 1) 
    anc[i][0] = p[i];

  FOR(lg, 1, MAXL) FOR(i, 1, n + 1)
    anc[i][lg] = anc[anc[i][lg - 1]][lg - 1];

  memset(centroid, -1, sizeof centroid);
  calc(1);

  REP(i, q) {
    int x;
    scanf("%d", &x);
    printf("%d\n", centroid[x]);
  }

  return 0;
}