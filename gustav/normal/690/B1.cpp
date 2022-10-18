#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

char a[55][55];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s", a[i]);
    REP(j, n) a[i][j] -= '0';
  }

  int x1 = n, y1 = n, x2 = 0, y2 = 0;
  REP(i, n) REP(j, n) {
    if (a[i][j] == 4) {
      x1 = min(x1, i);
      x2 = max(x2, i);
      y1 = min(y1, j);
      y2 = max(y2, j);
    }
  }

  if (x1 <= x2 && y1 <= y2) {
    bool ok = true;
    FOR(x, x1, x2+1) FOR(y, y1, y2+1) ok &= a[x][y] == 4;
    FOR(x, x1, x2+1) {
      ok &= (y1 == 0 || a[x][y1-1] == 2);
      ok &= (y2 == n-1 || a[x][y2+1] == 2);
    }
    FOR(y, y1, y2+1) {
      ok &= (x1 == 0 || a[x1-1][y] == 2);
      ok &= (x2 == n-1 || a[x2+1][y] == 2);
    }
    ok &= (x1 == 0 || y1 == 0 || a[x1-1][y1-1] == 1);
    ok &= (x1 == 0 || y2 == n-1 || a[x1-1][y2+1] == 1);
    ok &= (x2 == n-1 || y1 == 0 || a[x2+1][y1-1] == 1);
    ok &= (x2 == n-1 || y2 == n-1 || a[x2+1][y2+1] == 1);

    REP(i, n) REP(j, n)
      if (i < x1-1 || i > x2+1 || j < y1-1 || j > y2+1) ok &= a[i][j] == 0;
    if (ok) {
      puts("Yes");
      return 0;
    }
  }

  puts("No");
  return 0;
}