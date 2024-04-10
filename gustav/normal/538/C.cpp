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

const int MAX = 100005;

int d[MAX];
int h[MAX];

int main(void) 
{
  int n, m;
  scanf("%d%d", &n, &m);

  REP(i, m) scanf("%d%d", d + i, h + i);

  int sol = h[0];

  if (d[0] != 1)
    sol = max(sol, h[0] + abs(d[0] - 1));

  if (d[m - 1] != n)
    sol = max(sol, h[m - 1] + abs(d[m - 1] - n));

  REP(i, m - 1) {
    int j = i + 1;
    int dh = abs(h[j] - h[i]);
    int dd = abs(d[j] - d[i]);
    if (dd < dh) {
      puts("IMPOSSIBLE");
      exit(0);
    }
    sol = max(sol, max(h[j], h[i]) + (dd - dh) / 2);
  }

  printf("%d\n", sol);

  return 0;
}