#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

#include <bitset>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int inf = 1000000005;
const int MAXV = 10000005;
bitset< MAXV > B;

int n, k, q;
int a[5555];

int main(void) 
{
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", a+i), B[a[i]] = 1;

  scanf("%d", &q);
  REP(i, q) {
    int x; 
    scanf("%d", &x);

    int sol = inf;
    REP(j, n) {
      for (int p = 1; p <= k && x - p * a[j] >= 0; ++p) {
	int y = x - p * a[j];
	if (y == 0) sol = min(sol, p);
	for (int q = 1; q <= k - p; ++q) {
	  if (y % q != 0) continue;
	  if (y / q >= MAXV) continue;
	  if (B[y / q]) sol = min(sol, p + q);
	}
      }
    }

    if (sol == inf)
      puts("-1");
    else
      printf("%d\n", sol);
  }

  return 0;
}