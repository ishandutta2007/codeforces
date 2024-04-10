#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 4 * 200005;
const int inf = 1000000000 + 1;
const int off = 1 << 20;

#define L(i) (2 * (i))
#define R(i) (L(i) + 1)


struct Tournament {
  struct Data {
    int min, max;
  };

  Data merge(Data a, Data b) {
    return {min(a.min, b.min), max(a.max, b.max)};
  }

  Data t[off * 2];

  Tournament() {
    REP(i, 2 * off) t[i] = {inf, -inf};
  }

  void update(int i, int v) {
    i += off;
    t[i].min = min(t[i].min, v);
    t[i].max = max(t[i].max, v);
    for (i /= 2; i; i /= 2)
      t[i] = merge(t[L(i)], t[R(i)]);
  }

  Data query(int l, int r, int lo = 0, int hi = off, int i = 1) {
    if (lo >= r || hi <= l) return {inf, -inf};
    if (lo >= l && hi <= r) return t[i];
    return merge(query(l, r, lo, (lo + hi) / 2, L(i)),
		 query(l, r, (lo + hi) / 2, hi, R(i)));
  }

  int get_min(int l, int r) { return query(l, r).min; }
  int get_max(int l, int r) { return query(l, r).max; }
};

Tournament sweep, tmin, tmax;

enum {VIDEO, CHANNEL};
struct Event {
  int x, y;
  int type;
  int id;
};

bool operator<(const Event &a, const Event &b) {
  if (a.x != b.x) return a.x > b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.type < b.type;
}

int l[MAX], r[MAX];
int a[MAX], b[MAX], c[MAX];


int main(void) 
{
  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d%d", l + i, r + i);
  REP(i, m) scanf("%d%d%d", a + i, b + i, c + i);

  vector< int > _cx, _cy;
  REP(i, n) _cx.push_back(l[i]), _cy.push_back(r[i]);
  REP(i, m) _cx.push_back(a[i]), _cy.push_back(b[i]);

  //  sort(_cx.begin(), _cx.end());
  //  _cx.resize(unique(_cx.begin(), _cx.end()) - _cx.begin());
  sort(_cy.begin(), _cy.end());
  _cy.resize(unique(_cy.begin(), _cy.end()) - _cy.begin());

  //  auto cx = [&](int x) { return lower_bound(_cx.begin(), _cx.end(), x) - _cx.begin(); };
  auto cy = [&](int x) { return lower_bound(_cy.begin(), _cy.end(), x) - _cy.begin(); };

  vector< Event > E;

  REP(i, n) 
    E.push_back({l[i], r[i], VIDEO, i});
  
  REP(i, m)
    E.push_back({a[i], b[i], CHANNEL, i});

  sort(E.begin(), E.end());

  llint sol = 0;
  int J;

  for (auto &e : E) {
    if (e.type == VIDEO) {
      sweep.update(cy(e.y), e.y - e.x);
    } else {
      int qmax = sweep.get_max(0, cy(e.y) + 1);
      if (qmax >= 0) {
	llint val = (llint)qmax * c[e.id];
	if (val > sol) {
	  sol = val;
	  J = e.id;
	}
      }
    }
  }

  vector< int > _c;
  for (int x : _cx) _c.push_back(x);
  for (int x : _cy) _c.push_back(x);
  sort(_c.begin(), _c.end());
  _c.resize(unique(_c.begin(), _c.end()) - _c.begin());

  auto C = [&](int x) { return lower_bound(_c.begin(), _c.end(), x) - _c.begin(); };

  REP(i, n) {
    tmax.update(C(l[i]), r[i]);
    tmin.update(C(r[i]), l[i]);
  }

  REP(i, m) {
    int qmax = tmax.get_max(0, C(a[i]) + 1);
    if (qmax >= a[i]) {
      llint val = (llint)(min(qmax, b[i]) - a[i]) * c[i];
      if (val > sol) {
	sol = val;
	J = i;
      }
    }

    int qmin = tmin.get_min(C(b[i]), MAX);
    if (qmin <= b[i]) {
      llint val = (llint)(b[i] - max(qmin, a[i])) * c[i];
      if (val > sol) {
	sol = val;
	J = i;
      }
    }
  }

  if (sol == 0) {
    puts("0");
    exit(0);
  }

  REP(i, n) {
    llint cval = (llint)(min(r[i], b[J]) - max(l[i], a[J])) * c[J];
    if (cval == sol) {
      printf("%lld\n", sol);
      printf("%d %d\n", i + 1, J + 1);
      exit(0);
    }
  }

  return 0;
}