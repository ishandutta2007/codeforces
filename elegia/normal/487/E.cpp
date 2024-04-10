#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Node {
  int l, r, v;
  Node *ls, *rs;
  
  void ch(int k, int v) {
    if (l == r) {
      this->v = v;
      return;
    }
    if (k <= ls->r)
      ls->ch(k, v);
    else
      rs->ch(k, v);
    this->v = min(ls->v, rs->v);
  }
  
  int qry(int l, int r) const {
    if (this->l == l && this->r == r)
      return v;
    if (r <= ls->r)
      return ls->qry(l, r);
    if (l >= rs->l)
      return rs->qry(l, r);
    return min(ls->qry(l, ls->r), rs->qry(rs->l, r));
  }
};

struct Edge {
  int v;
  Edge* next;
};

const int N = 100010;

int n, m, q, bcn;
int w[N * 2], low[N], dfn[N * 2], idfn[N * 2], top[N * 2];
int sub[N * 2], heav[N * 2], prt[N * 2], dep[N * 2];
priority_queue<int, vector<int>, greater<int> > h[N * 2], dh[N * 2];
Edge *g[N], *bg[N * 2];

Node* seg;

void adde(Edge** g, int u, int v);
void link(Edge** g, int u, int v);
void bl(int u);
void dfs(int u);
void hld(int u);
Node* build(int l, int r);

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &w[i]);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    link(g, u, v);
  }
  bcn = n;
  bl(1);
  dfs(1);
  memset(dfn, 0, sizeof(dfn));
  top[1] = 1;
  hld(1);
  seg = build(1, bcn);
  while (q--) {
    char c;
    while ((c = getchar()), !isupper(c));
    if (c == 'A') {
      int u, v;
      scanf("%d%d", &u, &v);
      int ans = numeric_limits<int>::max();
      int x = top[u], y = top[v];
      while (x != y) {
        if (dep[x] < dep[y]) {
          swap(x, y);
          swap(u, v);
        }
        ans = min(ans, seg->qry(dfn[x], dfn[u]));
        u = prt[x];
        x = top[u];
      }
      if (dep[u] > dep[v])
        swap(u, v);
      ans = min(ans, seg->qry(dfn[u], dfn[v]));
      if (u > n)
        ans = min(ans, w[prt[u]]);
      printf("%d\n", ans);
    } else {
      int a, v;
      scanf("%d%d", &a, &v);
      seg->ch(dfn[a], v);
      int p = prt[a];
      if (a != 1) {
        dh[p].push(w[a]);
        h[p].push(v);
        while (!dh[p].empty() && dh[p].top() == h[p].top()) {
          dh[p].pop();
          h[p].pop();
        }
        seg->ch(dfn[p], w[p] = h[p].top());
      }
      w[a] = v;
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

Node* build(int l, int r) {
  static Node pool[N * 4];
  static Node* ptop = pool;
  Node* p = ptop;
  ++ptop;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->v = w[idfn[l]];
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->v = min(p->ls->v, p->rs->v);
  return p;
}

void hld(int u) {
  static int t;
  dfn[u] = ++t;
  idfn[t] = u;
  if (heav[u]) {
    top[heav[u]] = top[u];
    hld(heav[u]);
  }
  for (Edge* p = bg[u]; p; p = p->next)
    if (!dfn[p->v]) {
      top[p->v] = p->v;
      hld(p->v);
    }
}

void dfs(int u) {
  sub[u] = 1;
  for (Edge* p = bg[u]; p; p = p->next)
    if (!sub[p->v]) {
      prt[p->v] = u;
      dep[p->v] = dep[u] + 1;
      dfs(p->v);
      sub[u] += sub[p->v];
      if (u > n)
        h[u].push(w[p->v]);
      if (sub[p->v] > sub[heav[u]])
        heav[u] = p->v;
    }
  if (u > n)
    w[u] = h[u].top();
}

void bl(int u) {
  static stack<int> stk;
  static int t;
  low[u] = dfn[u] = ++t;
  stk.push(u);
  for (Edge* p = g[u]; p; p = p->next)
    if (!dfn[p->v]) {
      prt[p->v] = u;
      bl(p->v);
      low[u] = min(low[u], low[p->v]);
      if (low[p->v] >= dfn[u]) {
        int v;
        ++bcn;
        link(bg, bcn, u);
        do {
          v = stk.top();
          stk.pop();
          link(bg, bcn, v);
        } while (v != p->v);
      }
    } else if (p->v != prt[u])
      low[u] = min(low[u], dfn[p->v]);
}

void link(Edge** g, int u, int v) {
  adde(g, u, v);
  adde(g, v, u);
}

void adde(Edge** g, int u, int v) {
  static Edge pool[N * 6];
  static Edge* p = pool;
  p->v = v;
  p->next = g[u];
  g[u] = p;
  ++p;
}