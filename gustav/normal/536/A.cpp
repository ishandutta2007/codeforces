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

llint bites(llint A, llint B, llint m, llint l, llint r) {
  if (r - l + 1 < m)
    return A + (r - 1) * B;
  llint tot = (r - l + 1) * (A + (l - 1) * B + A + (r - 1) * B) / 2;
  return max(A + (r - 1) * B, (tot + m - 1) / m);
}

int A, B, n;

int main(void) 
{
  scanf("%d%d%d", &A, &B, &n);

  REP(i, n) {
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);
    
    llint lo = l - 1, hi = l + t + 1, mid;
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if (bites(A, B, m, l, mid) > t)
	hi = mid - 1;
      else
	lo = mid;
    }

    if (lo < l)
      puts("-1");
    else
      printf("%lld\n", lo);
  }

  return 0;
}