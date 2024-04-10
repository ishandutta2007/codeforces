#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 2005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char M[MAX][MAX];
int g[MAX][MAX];

stack< int > sx, sy;

void fail() {
  puts("Not unique");
  exit(0);
}

int get_deg(int i, int j) {
  int deg = 0;
  int dir = 0;
  REP(d, 4) {
    int ni = i + dx[d];
    int nj = j + dy[d];
    if (ni < 0 || ni >= n) continue;
    if (nj < 0 || nj >= m) continue;
    if (M[ni][nj] != '.') continue;
    ++deg;
    dir = d;
  }
  if (deg == 1) return dir + 1;
  return 0;
}

int main(void) 
{
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", M[i]);

  REP(i, n) REP(j, m) {
    if (M[i][j] != '.') continue;
    if (get_deg(i, j)) {
      g[i][j] = 1;
      sx.push(i);
      sy.push(j);
    }
  }

  auto add = [](int i, int j) {
    REP(d, 4) {
      int ni = i + dx[d];
      int nj = j + dy[d];
      if (ni < 0 || ni >= n) continue;
      if (nj < 0 || nj >= m) continue;
      if (M[ni][nj] != '.') continue;
      if (g[ni][nj]) continue;
      if (get_deg(ni, nj)) {
	g[ni][nj] = 1;
	sx.push(ni);
	sy.push(nj);
      }
    }
  };

  while (!sx.empty()) {
    int i = sx.top(); sx.pop();
    int j = sy.top(); sy.pop();
    int d = get_deg(i, j);

    if (M[i][j] != '.') continue;

    if (!d) continue;
    --d;


    int ni = i + dx[d];
    int nj = j + dy[d];

    if (d == 0) M[i][j] = '^', M[ni][nj] = 'v';
    if (d == 1) M[i][j] = '<', M[ni][nj] = '>';
    if (d == 2) M[i][j] = 'v', M[ni][nj] = '^';
    if (d == 3) M[i][j] = '>', M[ni][nj] = '<';

    add(i, j);
    add(ni, nj);
  }

  REP(i, n) REP(j, m)
    if (M[i][j] == '.')
      fail();

  REP(i, n) puts(M[i]);
  
  return 0;
}