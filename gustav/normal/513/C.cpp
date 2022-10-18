#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long double ld;

const int MAXN = 6;
const int MAX = 10005;

bool bio[MAX][1 << 5];
ld dp[MAX][1 << 5];

int n;
int l[MAXN];
int r[MAXN];

ld solve(int val, int mask) {
  if (mask == (1 << n) - 1) return 1.0;
  if (val == MAX) return 0.0;

  ld &ret = dp[val][mask];
  if (bio[val][mask]) return ret;
  bio[val][mask] = true;

  ret = solve(val + 1, mask);

  int rmask = (1 << n) - 1 - mask;
  for (int nmask = rmask; nmask; nmask = ((nmask - 1) & rmask)) {
    bool ok = true;
    REP(i, n) {
      if (((nmask >> i) & 1) == 0) continue;
      if (l[i] > val || r[i] < val) ok = false;
    }
    if (!ok) continue;
    
    ld mul = 1.0;
    if (__builtin_popcount(mask) < n - 1 && 
	__builtin_popcount(mask | nmask) >= n - 1)
      mul = val;

    ret += mul * solve(val + 1, mask | nmask);
  }

  return ret;
}

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) scanf("%d%d", l + i, r + i);

  ld sol = solve(0, 0);
  REP(i, n) sol /= (r[i] - l[i] + 1);

  printf("%.10lf\n", (double)sol);

  return 0;
}