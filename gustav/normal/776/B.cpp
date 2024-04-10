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

const int MAXN = 100005;

int sieve[MAXN];

int main(void) 
{
  FOR(i, 2, MAXN) sieve[i] = 1;
  FOR(i, 2, MAXN) 
    for (int j = 2 * i; j < MAXN; j += i)
      sieve[j] = 0;

  int n;
  scanf("%d", &n);

  int cntp = 0;
  int cntnp = 0;

  vector<int> sol;

  FOR(i, 2, n + 2) {
    if (sieve[i]) ++cntp, sol.push_back(1);
    else ++cntnp, sol.push_back(2);
  }

  printf("%d\n", (cntp != 0) + (cntnp != 0));
  for (int x : sol) printf("%d ", x);
  puts("");

  return 0;
}