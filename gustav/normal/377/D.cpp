#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

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

#define MAX 300005
#define MAXN 100005

struct event {
  int x;
  int l, c;
  int type;
  event(int x, int l, int c, int type) :
    x(x), l(l), c(c), type(type) {}
  friend bool operator<(const event &a, const event &b) {
    if (a.x == b.x) return (a.type < b.type);
    return a.x < b.x;
  }
};

struct tournament {
  static const int off = 1 << 19;
  int t[off << 1];
  int p[off << 1];
  int pos[off << 1];

  tournament() {
    memset(t, 0, sizeof t);
    memset(p, 0, sizeof p);
    memset(pos, 0, sizeof pos);
    for (int i = 0; i < off; ++i)
      for (int it = i + off; it; it /= 2)
        pos[it] = i;
  }

  void push(int n) {
    p[2 * n] += p[n];
    p[2 * n + 1] += p[n];

    t[2 * n] += p[n];
    t[2 * n + 1] += p[n];

    p[n] = 0;
  }

  void update(int l, int r, int v, int lo = 0, int hi = off, int n = 1) {
    if (lo >= r || hi <= l) return;
    if (lo >= l && hi <= r) {
      t[n] += v;
      p[n] += v;
      return;
    }

    push(n);
    update(l, r, v, lo, (lo + hi) / 2, 2 * n);
    update(l, r, v, (lo + hi) / 2, hi, 2 * n + 1);

    if (t[2 * n] > t[2 * n + 1]) {
      t[n] = t[2 * n];
      pos[n] = pos[2 * n];
    } else {
      t[n] = t[2 * n + 1];
      pos[n] = pos[2 * n + 1];
    }
  }

  pair< int, int > query(int l, int r, int lo = 0, int hi = off, int n = 1) {
    if (lo >= r || hi <= l) return { 0, 0 };
    if (lo >= l && hi <= r) return { t[n], pos[n] };
    push(n);
    return max(query(l, r, lo, (lo + hi) / 2, 2 * n),
               query(l, r, (lo + hi) / 2, hi, 2 * n + 1));
  }
} t;

vector< event > E;
multiset< int > C;

int n;
int l[MAXN];
int r[MAXN];
int v[MAXN];

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d%d%d", l + i, v + i, r + i);

  REP(i, n) {
    E.push_back(event(v[i], l[i], v[i], 0));
    E.push_back(event(r[i], l[i], v[i], 2));
    E.push_back(event(v[i], l[i], v[i], 1));
  }

  sort(E.begin(), E.end());

  int sol = 0;
  int L, R;

  for (event e : E) {
    if (e.type == 0) {
      t.update(e.l, e.c + 1, +1);
    } else if (e.type == 2) {
      t.update(e.l, e.c + 1, -1);
    } else {
      auto cnt = t.query(e.l, e.c + 1);
      if (cnt.first > sol) {
        sol = cnt.first;
        L = cnt.second;
        R = e.c;
      }
    }
  }

  printf("%d\n", sol);

  REP(i, n) {
    if (v[i] < L || v[i] > R) continue;
    if (l[i] > L || r[i] < R) continue;
    printf("%d ", i + 1);
  }
  
  puts("");

  return 0;
}