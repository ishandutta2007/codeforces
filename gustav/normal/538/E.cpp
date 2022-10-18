#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 200005;
const int inf = 1000000000;

int n;
vector< int > T[MAXN];

int tot[MAXN];
int best[MAXN];

void dfs1(int i, int dep, int dad) {
  if (i != 1 && T[i].size() == 1) {
    tot[i] = 1;
    best[i] = 1;
    return;
  }

  tot[i] = 0;
  int trash_max = inf;
  int trash_min = 0;
  for (auto j : T[i]) {
    if (j != dad) {
      dfs1(j, dep + 1, i);
      tot[i] += tot[j];
      trash_max = min(trash_max, tot[j] - best[j]);
      trash_min += tot[j] - best[j] + 1;
    }
  }

  if (dep % 2 == 0) { // max
    best[i] = tot[i] - trash_max;
  } else {
    best[i] = tot[i] - trash_min + 1;
  }
}

void dfs2(int i, int dep, int dad) {
  if (i != 1 && T[i].size() == 1) {
    tot[i] = 1;
    best[i] = 1;
    return;
  }

  tot[i] = 0;
  int trash_max = 0;
  int trash_min = inf;
  for (auto j : T[i]) {
    if (j != dad) {
      dfs2(j, dep + 1, i);
      tot[i] += tot[j];
      trash_min = min(trash_min, best[j]);
      trash_max += best[j];
    }
  }

  if (dep % 2 == 0) { // max
    best[i] = trash_max;
  } else {
    best[i] = trash_min;
  }
}

int main(void) 
{
  scanf("%d", &n);

  if (n == 1) {
    puts("1 1");
    exit(0);
  }

  REP(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    T[a].push_back(b);
    T[b].push_back(a);
  }

  int m = 0;
  FOR(i, 2, n + 1)
    if ((int)T[i].size() == 1)
      ++m;

  dfs1(1, 0, 0);
  int mx = best[1];
  dfs2(1, 0, 0);
  int mn = best[1];
  printf("%d %d\n", mx, mn);

  return 0;
}