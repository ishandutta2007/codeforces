#include <cstdio>

#include <algorithm>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Line {
  int k;
  ll b;

  Line() : k(0), b(0) {}

  Line(ll b) : k(0), b(b) {}

  Line(int k, ll b) : k(k), b(b) {}

  ll operator()(int x) const { return k * (ll)x + b; }

  Line operator+(const Line& rhs) const { return Line(k + rhs.k, b + rhs.b); }
  Line operator-() const { return Line(-k, -b); }
  Line operator-(const Line& rhs) const { return *this + (-rhs); }
  
  Line inc(ll x) const { return Line(k, b + k * (ll)x); }
};

struct Node {
  ll x;
  Line lne;
  int l, r;
  ll cert;
  Node *ls, *rs;
  
  int len() const { return r - l + 1; }
  
  ll gcert() const { return cert - x; }
  
#define DEFGET(V) Line g##V() const { return V.inc(x); }

  DEFGET(lne)
};

const ll INF = 1LL << 60;

ll compete(const Line& delt, ll x) {
  if (delt(x) > 0) {
    if (delt.k < 0) {
      ll chp = delt.b / -delt.k + 1;
      if (chp <= INF)
        return chp;
    }
  } else if (delt(x) < 0) {
    if (delt.k > 0) {
      ll chp = (-delt.b) / delt.k + 1;
      if (chp <= INF)
        return chp;
    }
  } else if (delt.k)
    return x + 1;
  return INF;
}

Line max(const Line& lhs, const Line& rhs, ll x) { return lhs(x) < rhs(x) ? rhs : lhs; }

struct KineticTournament {
  Node* segTree;

  Node* build(int l, int r);

  KineticTournament(int n) : segTree(build(1, n)) {}

  void update(Node* o) {
    o->lne = max(o->ls->glne(), o->rs->glne(), o->x);
    o->cert = min({compete(o->lne - o->ls->glne(), o->x), compete(o->lne - o->rs->glne(), o->x),
                   o->ls->gcert(), o->rs->gcert()});
  }

  void pushDown(Node* o) {
    if (o->x) {
      o->ls->x += o->x;
      o->rs->x += o->x;
      o->x = 0;
    }
  }

  void changeTraj(Node* o) {
    if (o->cert > o->x) return;
    pushDown(o);
    changeTraj(o->ls);
    changeTraj(o->rs);
    update(o);
  }

  void increase(Node* o, int l, int r, int x) {
    if (o->l == l && o->r == r) {
      o->x += x;
      return changeTraj(o);
    }
    pushDown(o);
    if (r <= o->ls->r)
      increase(o->ls, l, r, x);
    else if (l >= o->rs->l)
      increase(o->rs, l, r, x);
    else {
      increase(o->ls, l, o->ls->r, x);
      increase(o->rs, o->rs->l, r, x);
    }
    update(o);
  }
  
  void increase(int l, int r, int x) {
    increase(segTree, l, r, x);
  }

  ll qry(Node* o, int l, int r) {
    if (o->l == l && o->r == r)
      return o->lne(o->x);
    pushDown(o);
    ll ret;
    if (r <= o->ls->r)
      ret = qry(o->ls, l, r);
    else if (l >= o->rs->l)
        ret = qry(o->rs, l, r);
    else
      ret = max(qry(o->ls, l, o->ls->r), qry(o->rs, o->rs->l, r));
    update(o);
    return ret;
  }

  ll qry(int l, int r) {
    return qry(segTree, l, r);
  }
};

const int N = 200010;

int n, m;
int a[N], b[N], p[N], dfn[N], rd[N], dfnr[N];
vector<int> ch[N];

Node* KineticTournament::build(int l, int r) {
  static Node pool[N * 4], *top = pool;
  Node* p = top++;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->lne = Line(b[rd[l]], a[rd[l]] * (ll)b[rd[l]]);
    p->cert = INF;
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  update(p);
  return p;
}

void dfs(int u) {
  static int t;
  dfn[u] = ++t;
  rd[t] = u;
  for (int v : ch[u])
    dfs(v);
  dfnr[u] = t;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &p[i]);
    ch[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &b[i]);
  for (int i = 1; i <= n; ++i) {
    a[i] += a[p[i]];
    b[i] += b[p[i]];
  }
  for (int i = 1; i <= n; ++i)
    if (b[i] < 0) b[i] = -b[i];
  dfs(1);
  KineticTournament pos(n);
  for (int i = 1; i <= n; ++i) {
    b[i] = -b[i];
  }
  KineticTournament neg(n);
  while (m--) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1) {
      int y;
      scanf("%d", &y);
      pos.increase(dfn[x], dfnr[x], y);
      neg.increase(dfn[x], dfnr[x], y);
    } else
      printf("%lld\n", max(pos.qry(dfn[x], dfnr[x]), neg.qry(dfn[x], dfnr[x])));
  }
  return 0;
}