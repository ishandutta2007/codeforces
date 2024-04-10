#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

#include <set>
#include <unordered_map>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<


const int MAXN = 100005;
const int MAX = 200005;
const int inf = 1000000000;
const int off = 1 << 17;

int t[2 * off];

void update(int i, int v) {
  i += off;
  t[i] = v;
  for (i /= 2; i; i /= 2)
    t[i] = min(t[2 * i], t[2 * i + 1]);
}

int query(int l, int r, int lo = 0, int hi = off, int n = 1) {
  if (lo >= r || hi <= l) return inf;
  if (lo >= l && hi <= r) return t[n];
  return min(query(l, r, lo, (lo + hi) / 2, 2 * n),
	     query(l, r, (lo + hi) / 2, hi, 2 * n + 1));
}

int n, m, k, q;
int x[MAX], y[MAX];
int xa[MAX], ya[MAX];
int xb[MAX], yb[MAX];

enum { ROOK, RECT };
struct Event { int x, id, type; };

bool operator<(Event a, Event b) {
  if (a.x != b.x) return a.x < b.x;
  return a.type < b.type;
}

vector< Event > E;
int sol[MAX];

void solve() {
  memset(t, -1, sizeof t);
  E.clear();
  REP(i, k) E.push_back({x[i], i, ROOK});
  REP(i, q) E.push_back({xb[i], i, RECT});

  sort(E.begin(), E.end());

  for (auto e : E) {
    if (e.type == ROOK) 
      update(y[e.id], x[e.id]);
    else 
      if (query(ya[e.id], yb[e.id] + 1) >= xa[e.id]) sol[e.id] = 1;
  }
}

int main(void) 
{
  scanf("%d%d%d%d", &n, &m, &k, &q);
  REP(i, k) scanf("%d%d", x+i, y+i);
  REP(i, q) scanf("%d%d%d%d", xa+i, ya+i, xb+i, yb+i);
  REP(i, q) sol[i] = false;

  solve();
  REP(i, k) swap(x[i], y[i]);
  REP(i, q) swap(xa[i], ya[i]), swap(xb[i], yb[i]);
  solve();

  REP(i, q) {
    if (sol[i])
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}