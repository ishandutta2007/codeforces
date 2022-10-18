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

const int MAGIC = 330;
const int MAXN = MAGIC * MAGIC;

int m;
llint x[MAXN];
llint val[MAXN];
llint maximum[MAGIC];
llint shift[MAGIC];

void update(int pos, int d) {
  ++pos;
  do {
    --pos;
    val[pos] += d;
  } while (pos % MAGIC);

  int blk = pos / MAGIC;
  maximum[blk] = -inf;
  REP(i, MAGIC) {
    llint &v = val[blk * MAGIC + i];
    v += shift[blk];
    maximum[blk] = max(maximum[blk], v);
  }
  shift[blk] = 0;

  for (int i = blk - 1; i >= 0; --i)
    shift[i] += d;
}

llint get() {
  for (int i = MAGIC - 1; i >= 0; --i) {
    if (maximum[i] + shift[i] <= 0) continue;
    for (int j = MAGIC - 1; j >= 0; --j)
      if (val[i * MAGIC + j] + shift[i] > 0)
	return x[i * MAGIC + j];
    assert(false);
  }
  return -1;
}

int main(void) 
{
  scanf("%d", &m);

  REP(i, m) {
    int p, t;
    scanf("%d%d", &p, &t); --p;

    if (t == 0) {
      update(p, -1);
    } else {
      scanf("%lld", x + p);
      update(p, +1);
    }

    printf("%lld\n", get());
  }

  return 0;
}