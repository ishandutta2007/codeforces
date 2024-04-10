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

const int MAXN = 200005;
const int off = 1 << 18;

#define L(i) (2 * (i))
#define R(i) (L(i) + 1)

int n, q;
int f[MAXN];
int u[MAXN];
int v[MAXN];

struct Node {
  int len;
  int lblock;
  int rblock;
  llint inside;

  llint total() {
    if (lblock == len) return f[lblock];
    return f[lblock] + f[rblock] + inside;
  }
};

Node merge(const Node &l, const Node &r) {
  if (l.lblock == l.len && r.lblock == r.len)
    return {l.len + r.len, l.len + r.len, l.len + r.len, 0};

  if (l.lblock == l.len)
    return {l.len + r.len, l.len + r.lblock, r.rblock, r.inside};
  
  if (r.lblock == r.len)
    return {l.len + r.len, l.lblock, l.rblock + r.len, l.inside};

  return {l.len + r.len, l.lblock, r.rblock, l.inside + r.inside + f[l.rblock + r.lblock]};
}

Node rev(const Node &n) {
  return {n.len, n.rblock, n.lblock, n.inside};
}

Node t[off << 1];

void build(int i) {
  if (i >= off) {
    t[i].len = 1;
    t[i].lblock = 0;
    t[i].rblock = 0;
    t[i].inside = 0;
    return;
  }
  build(L(i));
  build(R(i));
  t[i] = merge(t[L(i)], t[R(i)]);
}

void update(int i) {
  i += off;
  t[i].lblock = 1;
  t[i].rblock = 1;
  for (i /= 2; i; i /= 2)
    t[i] = merge(t[L(i)], t[R(i)]);
}

Node query(int l, int r, int lo = 0, int hi = off, int i = 1) {
  if (lo >= r || hi <= l) return {0, 0, 0, 0};
  if (lo >= l && hi <= r) return t[i];
  return merge(
	       query(l, r, lo, (lo + hi) / 2, L(i)),
	       query(l, r, (lo + hi) / 2, hi, R(i))
	       );
}

struct Edge {
  int b, id;
};

vector< Edge > T[MAXN];
int wei[MAXN];
int dep[MAXN];
int dad[MAXN];
int vertex[MAXN];

void dfs(int i, int d) {
  wei[i] = 1;
  dep[i] = d;
  for (auto jt : T[i]) {
    int j = jt.b;
    if (j == dad[i]) continue;
    dad[j] = i;
    vertex[jt.id] = j;
    dfs(j, d + 1);
    wei[i] += wei[j];
  }
}

int C;
int chain[MAXN];
int cdad[MAXN];
int cpos[MAXN]; // gdje sam u lancu?
int pos;

void hld(int i, int c) {
  chain[i] = c;
  cpos[i] = pos++;
  if (cdad[c] == -1) cdad[c] = i;

  int best = -1;
  for (auto jt : T[i]) {
    int j = jt.b;
    if (j == dad[i]) continue;
    if (best == -1 || wei[j] > wei[best]) best = j;
  }

  if (best != -1) hld(best, c);
  
  for (auto jt : T[i]) {
    int j = jt.b;
    if (j == dad[i] || j == best) continue;
    hld(j, ++C);
  }
}

Node hld_query(int i, int j) {
  Node l = {0, 0, 0, 0};
  Node r = {0, 0, 0, 0};
  while (chain[i] != chain[j]) {
    if (dep[cdad[chain[i]]] < dep[cdad[chain[j]]]) {
      r = merge(query(cpos[cdad[chain[j]]], cpos[j] + 1), r);
      j = dad[cdad[chain[j]]];
    } else {
      l = merge(l, rev(query(cpos[cdad[chain[i]]], cpos[i] + 1)));
      i = dad[cdad[chain[i]]];
    }
  }

  if (dep[i] > dep[j]) 
    l = merge(l, rev(query(cpos[j] + 1, cpos[i] + 1)));
  if (dep[j] > dep[i]) {
    r = merge(query(cpos[i] + 1, cpos[j] + 1), r);
  }

  return merge(l, r);
}

enum {EDGE, QUERY};
struct Event {
  int w;
  int id;
  int type;
};

llint sol[MAXN];

int main(void) 
{
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", f + i);

  vector< Event > E;

  REP(i, n - 1) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w); --a; --b;
    T[a].push_back({b, i});
    T[b].push_back({a, i});
    E.push_back({w, i, EDGE});
  }

  memset(dad, -1, sizeof dad);
  memset(cdad, -1, sizeof cdad);
  dfs(0, 0);
  hld(0, 0);

  build(1);

  REP(i, q) {
    int l;
    scanf("%d%d%d", &u[i], &v[i], &l); --u[i]; --v[i];
    E.push_back({l, i, QUERY});
  }

  sort(E.begin(), E.end(), [&](const Event &a, const Event &b) {
      if (a.w != b.w) return a.w > b.w;
      return a.type < b.type;
    });

  for (auto e : E) {
    if (e.type == EDGE) 
      update(cpos[vertex[e.id]]);
    else 
      sol[e.id] = hld_query(u[e.id], v[e.id]).total();
  }

  REP(i, q)
    printf("%lld\n", sol[i]);
  
  return 0;
}