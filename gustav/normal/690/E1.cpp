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

const int MAX = 605;
int m[MAX][MAX];

void solve() {
  int h, w;
  scanf("%d%d", &h, &w);

  REP(i, h) REP(j, w)
    scanf("%d", &m[i][j]);

  vector< int > ags;

  int hag;

  REP(i, h) {
    int j = (i + 1) % h;
    int ag = 0;
    REP(k, w) ag += abs(m[i][k] - m[j][k]);
    ags.push_back(ag);

    if (i == h / 2 - 1)
      hag = ag;
  }

  sort(ags.begin(), ags.end());

  int pos = lower_bound(ags.begin(), ags.end(), hag) - ags.begin();

  if ((double)pos / h > 0.95)
    puts("YES");
  else
    puts("NO");
}


int main(void) 
{
  int q;
  scanf("%d", &q);
  REP(i, q) solve();

  return 0;
}