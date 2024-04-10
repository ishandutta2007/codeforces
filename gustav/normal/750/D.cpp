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

const int MAXN = 35;
const int MAX = 305; //////////////////////////////////////////////////////
const int X = MAX / 2;

const int dx[] = {+1, +1, +0, -1, -1, -1, +0, +1};
const int dy[] = {+0, +1, +1, +1, +0, -1, -1, -1};

int n, t[MAXN];
bool got_dir[MAXN][6][8][MAX][MAX];
bool bio[MAX][MAX];

void go(int i, int ct, int d, int x, int y) {
  if (i == n) return;
  bio[x][y] = 1;
  if (got_dir[i][ct][d][x][y]) return;
  got_dir[i][ct][d][x][y] = 1;
  if (ct == 0) {
    go(i + 1, t[i + 1], (d + 1) % 8, x, y);
    go(i + 1, t[i + 1], (d + 7) % 8, x, y);
    return;
  }
  go(i, ct - 1, d, x + dx[d], y + dy[d]);
}

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", t + i);

  go(0, t[0] - 1, 0, X, X);

  int sol = 0;
  REP(i, MAX) {
    REP(j, MAX) {
      sol += bio[i][j];
    }
  }

  printf("%d\n", sol);

  return 0;
}