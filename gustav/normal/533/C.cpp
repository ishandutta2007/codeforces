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

int xp, yp, xv, yv;

int main(void) 
{
  scanf("%d%d%d%d", &xp, &yp, &xv, &yv);

  if (xp <= xv && yp <= yv) {
    puts("Polycarp");
    exit(0);
  }

  if (xp + yp <= max(xv, yv))
    puts("Polycarp");
  else
    puts("Vasiliy");

  return 0;
}