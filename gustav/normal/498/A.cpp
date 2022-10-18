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

int sgn(llint x) { 
  if (x < 0) return -1;
  if (x > 0) return +1;
  assert(false);
}

int main(void) 
{
  llint x1, y1;
  scanf("%lld%lld", &x1, &y1);
  llint x2, y2;
  scanf("%lld%lld", &x2, &y2);

  int sol = 0;

  int n;
  scanf("%d", &n);
  REP(i, n) {
    llint A, B, C;
    scanf("%lld%lld%lld", &A, &B, &C);
    if (sgn(A * x1 + B * y1 + C) !=
	sgn(A * x2 + B * y2 + C))
      ++sol;
  }

  printf("%d\n", sol);

  return 0;
}