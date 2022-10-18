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

int n, k;
llint a[MAXN];
map<llint,llint> cnt;

int main(void) 
{
  scanf("%d%d", &n, &k);

  FOR(i, 1, n + 1)
    scanf("%lld", a + i);
  REP(i, n) a[i + 1] += a[i];

  vector<llint> powers;
  if (k == 1) {
    powers.push_back(1);
  }
  else if (k == -1) {
    powers.push_back(1);
    powers.push_back(-1);
  } else {
    llint x = 1;
    while (abs(x) < 1e17) {
      powers.push_back(x);
      x *= k;
    }
  }

  llint sol = 0;
  REP(i, n + 1) {
    for (llint p : powers) {
      sol += cnt[a[i] - p];
    }
    ++cnt[a[i]];
  }

  printf("%lld\n", sol);

  return 0;
}