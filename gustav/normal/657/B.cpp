#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 400005;

int n, k;
llint a[MAXN];
llint b[MAXN];
int m;

bool normalize() {
  m = 0;
  while (b[m] || m < n) {
    if (abs(b[m]) >= 2) {
      b[m + 1] += b[m] / 2;
      b[m] %= 2;
    }
    if (b[m] < 0) {
      b[m + 1] -= 1;
      b[m] = 1;
    }
    ++m;
    if (m == MAXN) return false;
  }
  return true;
}

int main(void) 
{
  scanf("%d%d", &n, &k); ++n;
  REP(i, n) scanf("%lld", a + i);

  int sgn = 1;
  REP(i, n) b[i] = a[i];
  if (!normalize()) {
    REP(i, MAXN) b[i] = 0;
    REP(i, n) b[i] = -a[i];
    assert(normalize());
    sgn *= -1;
  }

  int r = 0; while (!b[r]) ++r;

  llint y = 0;
  for (int i = m - 1; i >= r; --i) {
    y = y * 2 + b[i];
    if (y > 10LL * k) {
      puts("0");
      exit(0);
    }
  }

  y *= sgn;

  int sol = 0;
  while (r >= 0 && abs(y) <= 10LL * k) {
    if (r <= n - 1) {
      if (r != n - 1 || a[r] - y != 0) {
	if (abs(a[r] - y) <= k) {
	  ++sol;
	}
      }
    }
    --r;
    y *= 2;
  }

  printf("%d\n", sol);

  return 0;
}