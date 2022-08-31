#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 500010;
const ll INF = 1LL << 61;

struct Node {
  int l, r;
  ll lazy, d;
  Node *ls, *rs;

#ifndef ONLINE_JUDGE
  void*operator new(size_t) {
    static Node pool[N * 2];
    static Node* p = pool;
    return p++;
  }
#endif

  ll get() const { return d + lazy; }

  void upd() {
    d = min(ls->get(), rs->get());
  }

  void pd() {
    if (lazy) {
      d += lazy;
      ls->lazy += lazy;
      rs->lazy += lazy;
      lazy = 0;
    }
  }

  void ch(int l, int r, int x) {
    if (this->l == l && this->r == r) {
      lazy += x;
      return;
    }
    pd();
    if (r <= ls->r)
      ls->ch(l, r, x);
    else if (l >= rs->l)
      rs->ch(l, r, x);
    else {
      ls->ch(l, ls->r, x);
      rs->ch(rs->l, r, x);
    }
    upd();
  }

  ll qry(int l, int r) {
    if (this->l == l && this->r == r)
      return get();
    pd();
    if (r <= ls->r)
      return ls->qry(l, r);
    if (l >= rs->l)
      return rs->qry(l, r);
    return min(ls->qry(l, ls->r), rs->qry(rs->l, r));
  }

};

int n, m;
vector<pair<pair<int, int>, int>> qry[N];
int idr[N], prt[N];
ll ans[N], dep[N];
vector<pair<int, int>> ch[N];

Node* seg;

Node* build(int l, int r) {
  Node* p = new Node;
  p->l = l;
  p->r = r;
  p->lazy = 0;
  if (l == r) {
    if (ch[l].empty())
      p->d = dep[l];
    else
      p->d = INF;
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->upd();
  return p;
}

void dfs(int u) {
  for (const auto& pr : qry[u])
    ans[pr.second] = seg->qry(pr.first.first, pr.first.second);
  for (const auto& pr : ch[u]) {
    int l = pr.first, r = idr[l], w = pr.second;
    seg->ch(l, r, -w);
    if (l != 1)
      seg->ch(1, l - 1, w);
    if (r != n)
      seg->ch(r + 1, n, w);
    dfs(l);
    seg->ch(l, r, w);
    if (l != 1)
      seg->ch(1, l - 1, -w);
    if (r != n)
      seg->ch(r + 1, n, -w);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; ++i) {
    int p, w;
    scanf("%d%d", &p, &w);
    prt[i] = p;
    ch[p].emplace_back(i, w);
    dep[i] = dep[p] + w;
  }
  for (int i = 1; i <= m; ++i) {
    int v, l, r;
    scanf("%d%d%d", &v, &l, &r);
    qry[v].emplace_back(make_pair(l, r), i);
  }
  seg = build(1, n);
  for (int i = n; i; --i) {
    if (!idr[i])
      idr[i] = i;
    if (!idr[prt[i]])
      idr[prt[i]] = idr[i];
  }
  dfs(1);
  for (int i = 1; i <= m; ++i)
    printf("%lld\n", ans[i]);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}