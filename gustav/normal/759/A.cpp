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

const int MAXN = 2e5 + 5;
int n;
int p[MAXN];
int b[MAXN];
int bio[MAXN];

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", p + i); 
    --p[i];
  }
  REP(i, n) scanf("%d", b + i);

  int cyc = 0;
  REP(i, n) {
    if (bio[i]) continue;
    for (int j = i; !bio[j]; j = p[j])
      bio[j] = 1;
    ++cyc;
  }

  int ones = 1;
  REP(i, n) ones ^= b[i];

  if (cyc == 1) cyc = 0;

  printf("%d\n", cyc + ones);

  return 0;
}