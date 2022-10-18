#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
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

#define MAXN 100005
#define MAXM 100005

int N;
int s[MAXN], m[MAXN], f[MAXN];

int M;
int t[MAXM], l[MAXM], r[MAXN];

struct interval {
  int l, r, t;
  interval() {}
  interval(int l, int r, int t) : l(l), r(r), t(t) {}
  friend bool operator<(const interval &a, const interval &b) {
    return a.r < b.r;
  }
};

set< interval > I;

struct event {
  int delta, x, y;
  int qid, type;
  event() {}
  event(int delta, int x, int y, int qid, int type) :
    delta(delta), x(x), y(y), qid(qid), type(type) {}
  friend bool operator<(const event &a, const event &b) {
    if (a.delta == b.delta) return a.type < b.type;
    return a.delta < b.delta;
  }
};

vector< event > E;

llint rate[MAXN];
llint top[MAXN];

void update(llint *f, int x, int v) {
  for (int i = x + 1; i < MAXN; i += i & -i)
    f[i] += v;
}

llint query(llint *f, int x, int y) {
  llint ret = 0;
  for (int i = y + 1; i; i -= i & -i)
    ret += f[i];
  for (int i = x; i; i -= i & -i)
    ret -= f[i];
  return ret;
}

llint sol[MAXM];

void build_events() {
  REP(i, N) I.insert(interval(i, i, -1));
  REP(i, M) {
    --l[i], --r[i];
    for (auto it = I.lower_bound({ l[i], l[i], 0 }); 
              it != I.end() && it->l <= r[i];
              it = I.lower_bound({ l[i], l[i], 0 })) {

      interval ci = *it;
      I.erase(it);

      if (ci.l < l[i]) {
        I.insert(interval(ci.l, l[i] - 1, ci.t));
        I.insert(interval(l[i], ci.r, ci.t));
      } else if (ci.r > r[i]) {
        I.insert(interval(r[i] + 1, ci.r, ci.t));
        I.insert(interval(ci.l, r[i], ci.t));
      } else if (ci.t == -1) {
        sol[i] += min((llint)m[ci.l], (llint)f[ci.l] * t[i] + s[ci.l]);
      } else {
        E.push_back(event(t[i] - ci.t, ci.l, ci.r, i, 1));
      }
    }
    I.insert(interval(l[i], r[i], t[i]));
  }
  REP(i, N) E.push_back(event(f[i] ? (m[i] + f[i] - 1) / f[i] : 0, i, 0, 0, 0));
}

void sweep() {
  sort(E.begin(), E.end());
  REP(i, N) {
    update(rate, i, f[i]);
    if (f[i] == 0) m[i] = 0;
  }
  for (auto &e : E) {
    if (e.type == 0) { // pony e.x prelazi u max
      update(rate, e.x, -f[e.x]);
      update(top, e.x, +m[e.x]);
    } else { // query
      sol[e.qid] += e.delta * query(rate, e.x, e.y) + query(top, e.x, e.y);
    }
  }
}

int main(void)
{
  scanf("%d", &N);
  REP(i, N) scanf("%d%d%d", &s[i], &m[i], &f[i]);

  scanf("%d", &M);
  REP(i, M) scanf("%d%d%d", &t[i], &l[i], &r[i]);

  build_events();
  sweep();

  REP(i, M) cout << sol[i] << endl;

  return 0;
}