#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int inf = 1e9;

int main(void) 
{
  int lo = -inf;
  int hi = +inf;
  int v = 0;

  int n;
  scanf("%d", &n);

  REP(i, n) {
    int c, d;
    scanf("%d%d", &c, &d);

    if (d == 1) 
      lo = max(lo, 1900 - v);
    else
      hi = min(hi, 1899 - v);

    v += c;
  }

  if (lo > hi)
    puts("Impossible");
  else if (hi == inf)
    puts("Infinity");
  else
    printf("%d\n", hi + v);

  return 0;
}