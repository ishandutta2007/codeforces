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

const int MAXN = 1000005;

int n, q;
int a[MAXN];
int dad[MAXN];
int len[MAXN];

int main(void) 
{
  scanf("%d%d", &n, &q);
  REP(i, n) scanf("%d", a + i);

  REP(qq, q) {
    llint b;
    scanf("%lld", &b);

    llint sum = 0;
    int cdad = 0;
    int clen = 0;
    int best = 0;

    REP(it, 2) {
      REP(i, n) {
	sum += a[i];
	clen += 1;
	while (sum - a[cdad] > b || clen > n + 1) {
	  sum -= a[cdad];
	  cdad = (cdad + 1) % n;
	  clen -= 1;
	}
	dad[i] = cdad;
	len[i] = clen;
	if (len[i] < len[best]) best = i;
      }
    }

    int sol = n;
    REP(i, len[best]) {
      int p = (dad[best] + i) % n;
      int passed = 0;
      int csol = 0;
      while (passed < n) {
	passed += len[p] - 1;
	p = dad[p];
	++csol;
      }
      sol = min(sol, csol);
    }

    printf("%d\n", sol);
  }

  return 0;
}