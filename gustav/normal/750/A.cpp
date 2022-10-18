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
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

int main(void) 
{
  int n, k;
  scanf("%d%d", &n, &k);

  int t = 240 - k;
  int sol = 0;
  for (int i = 1; i <= n; ++i) {
    if (t >= i * 5) {
      t -= i * 5;
      ++sol;
    }
  }

  printf("%d\n", sol);

  return 0;
}