#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int off = 1 << 17;
const int inf = 1000000000;

#define MAX 100005

#define L(n) ((n) << 1)
#define R(n) (L(n) | 1)

struct Node {
  int lmax;
  int rmax;
  int best;

  Node() {
    lmax = rmax = best = 0;
  }
};

Node t[off << 1];

Node join(Node l, Node r, int len) {
  Node ret;
  ret.best = max(l.best, r.best);
  ret.best = max(
    ret.best,
    l.rmax + r.lmax
  );

  ret.lmax = (l.lmax == len) ? 
    l.lmax + r.lmax :
    l.lmax;

  ret.rmax = (r.rmax == len) ?
    r.rmax + l.rmax :
    r.rmax;

  return ret;
}

void update(int pos) {
  pos += off;

  t[pos].lmax = 1;
  t[pos].rmax = 1;
  t[pos].best = 1;
  int len = 1;

  for (pos /= 2; pos; pos /= 2) {
    t[pos] = join(t[L(pos)], t[R(pos)], len);
    len *= 2;
  }
}

Node query(int l, int r) {
  if (l == r) return t[l + off];

  Node ln = t[l += off];
  Node rn = t[r += off];

  int len = 1;
  while (l / 2 != r / 2) {
    if (l % 2 == 0) ln = join(ln, t[l ^ 1], len);
    if (r % 2 == 1) rn = join(t[r ^ 1], rn, len);
    len *= 2;
    l /= 2; 
    r /= 2;
  }

  return join(ln, rn, len);
}

/*
Node query(int lo, int hi, int l = 0, int r = off, int n = 1) {
  if (l >= hi || r <= lo) return Node();
  if (l >= lo && r <= hi) return t[n];
  return join(
    query(lo, hi, l, (l + r) / 2, L(n)),
    query(lo, hi, (l + r) / 2, r, R(n)),
    (r - l) / 2
  );
}
*/

struct Event {
  int lo, hi, mid;
  int l, r, w;
  int type;
  int id;

  Event(int h, int pos) {
    mid = h;
    l = pos;
    type = 0;
  }

  Event(int l, int r, int w, int id) :
    l(l), r(r), w(w), id(id) {
      lo = 0; hi = inf;
      type = 1;
    }

  bool prep() {
    if (lo >= hi) return false;
    mid = (lo + hi + 1) / 2;
    return true;
  }

  void answer(int W) {
    if (W >= w) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
};

bool operator<(const Event &a, const Event &b) {
  if (a.mid == b.mid)
    return a.type < b.type;
  return a.mid > b.mid;
}

vector< Event > e;

int sol[MAX];

int main(void)
{
  int n, m, h;
  int l, r, w;
  
  scanf("%d", &n);

  REP(i, n) {
    scanf("%d", &h);
    e.push_back(Event(h, i));
  }

  scanf("%d", &m);

  REP(i, m) {
    scanf("%d%d%d", &l, &r, &w); --l; --r;
    e.push_back(Event(l, r, w, i));
  }

  while (true) {
    bool done = true;

    memset(t, 0, sizeof t);

    for (Event &ee : e) {
      if (ee.type == 1) {
        if (ee.prep())
          done = false;
      }
    }

    sort(e.begin(), e.end());

    for (Event &ee : e) {
      if (ee.type == 1) {
        if (ee.prep())
          ee.answer(query(ee.l, ee.r).best);
      } else {
        update(ee.l);
      }
    }

    if (done) break;
  }

  for (Event &ee : e)
    if (ee.type == 1)
      sol[ee.id] = ee.lo;

  REP(i, m)
    printf("%d\n", sol[i]);

  return 0;
}