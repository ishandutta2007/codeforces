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

const int MAX = 1000005;

int N, K;
int c[MAX];
int f[MAX];

int main(void) 
{
  FOR(i, 2, MAX) {
    if (f[i]) continue;
    for (int j = i; j < MAX; j += i)
      f[j] = i;
  }

  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", c + i);

  REP(i, N) {
    llint x = c[i];

    while (x != 1) {
      llint d = f[x];
      llint t = 1;

      while (x % d == 0) {
	x /= d;
	t *= d;
      }

      if (K % t || (K % (t * d))) 
	while (K % d == 0) K /= d;
    }
  }

  if (K == 1) 
    puts("Yes");
  else
    puts("No");

  return 0;
}