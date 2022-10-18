#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 3005;

int R, C, N;
int m[MAX][2 * MAX];

int id(int i, int j) {
  return i * 2 * C + j;
}

int uf[MAX * 2 * MAX];
int find(int i) { return uf[i] == i ? i : uf[i] = find(uf[i]); }
void unite(int i, int j) { uf[find(i)] = find(j); }

int main(void) 
{
  scanf("%d%d%d", &R, &C, &N);
  REP(i, R * 2 * C) uf[i] = i;

  int sol = 0;

  REP(i, N) {
    int x, y;
    scanf("%d%d", &x, &y); --x; --y;

    vector< int > ns, nss;
    for (int dx = -1; dx <= +1; ++dx) {
      for (int dy = -1; dy <= +1; ++dy) {
	int cx = x + dx;
	int cy = (y + dy + 2 * C) % (2 * C);

	if (cx < 0 || cx >= R) continue;
	if (!m[cx][cy]) continue;

	ns.push_back(id(cx, cy));
	nss.push_back(id(cx, (cy + C) % (2 * C)));
      }
    }

    bool ok = true;

    for (int a : ns) 
      for (int b : nss) 
	if (find(a) == find(b)) 
	  ok = false;

    if (ok) {
      ++sol;
      m[x][y] = 1;
      m[x][(y + C) % (2 * C)] = 1;

      for (int a : ns)
	unite(a, id(x, y));

      for (int a : nss)
	unite(a, id(x, (y + C) % (2 * C)));
    } 
  }

  printf("%d\n", C == 1 ? 0 : sol);

  return 0;
}