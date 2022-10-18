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

const int MAXN = 51;

int n;
char m[MAXN][MAXN];
char z[MAXN][MAXN];
char sol[2 * MAXN][2 * MAXN];

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) scanf("%s", m[i]);

  vector< pair< int, int > > v;
  FOR(x, -n + 1, n) FOR(y, -n + 1, n) {
    if (x == 0 && y == 0) continue;
    bool good = true;
    REP(i, n) {
      REP(j, n) {
	if (m[i][j] != 'o') continue;
	if (i + x < 0 || i + x >= n) continue;
	if (j + y < 0 || j + y >= n) continue;
	if (m[i + x][j + y] == '.') {
	  good = false;
	  break;
	}
      }
      if (!good) break;
    }
    if (good) v.push_back({x, y});
  }

  memset(z, '.', sizeof z);
  REP(i, n) REP(j, n) {
    if (m[i][j] != 'o') continue;
    z[i][j] = 'o';
    for (auto it : v) {
      int x = it.first;
      int y = it.second;	
      if (i + x < 0 || i + x >= n) continue;
      if (j + y < 0 || j + y >= n) continue;
      if (z[i + x][j + y] != '.') continue;
      z[i + x][j + y] = 'x';
    }
  }

  REP(i, n) REP(j, n) {
    if (z[i][j] != m[i][j]) {
      puts("NO");
      exit(0);
    }
  }


  memset(sol, '.', sizeof sol);

  sol[n - 1][n - 1] = 'o';

  for (auto it : v) {
    int x = it.first;
    int y = it.second;
    sol[n - 1 + x][n - 1 + y] = 'x';
  }

  puts("YES");
  REP(i, 2 * n - 1) {
    REP(j, 2 * n - 1) putchar(sol[i][j]);
    puts("");
  }

  return 0;
}