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

const int MAX = 200005;
const int MAXL = 18;

int N;
int dep[MAX];
int anc[MAX][MAXL];

void add(int i, int p) {
  dep[i] = dep[p] + 1;
  anc[i][0] = p;
  FOR(lg, 1, MAXL) 
    anc[i][lg] = anc[anc[i][lg - 1]][lg - 1];
}

int lca(int i, int j) {
  if (dep[i] < dep[j]) swap(i, j);

  for (int lg = MAXL - 1; lg >= 0; --lg) 
    if (dep[i] - dep[j] >= (1 << lg))
      i = anc[i][lg];

  if (i == j) return i;

  for (int lg = MAXL - 1; lg >= 0; --lg) {
    if (anc[i][lg] != anc[j][lg]) {
      i = anc[i][lg];
      j = anc[j][lg];
    }
  }

  return anc[i][0];
}

int dist(int i, int j) {
  int k = lca(i, j);
  return dep[i] + dep[j] - 2 * dep[k];
}

int main(void) 
{
  scanf("%d", &N);

  REP(i, MAXL) anc[1][i] = 1;
  int a = 1, b = 1, d = 0;

  FOR(i, 2, N + 1) {
    int p;
    scanf("%d", &p);
    add(i, p);

    int ia = dist(i, a);
    if (ia > d) {
      b = i;
      d = ia;
    }
    int ib = dist(i, b);
    if (ib > d) {
      a = i;
      d = ib;
    }

    printf("%d ", d);
  }
  puts("");

  return 0;
}