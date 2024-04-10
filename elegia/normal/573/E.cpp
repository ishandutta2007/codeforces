#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
  Line lazy, lne;
  int l, r, mpos;
  ll cert;
  Node *ls, *rs;

  ll gcert() const { return cert - x; }

  Line get() const { return lne.inc(x) + lazy.inc(x); }
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

pair<Line, int> max(const Line& lhs, const Line& rhs, int lpos, int rpos, ll x) { return lhs(x) < rhs(x) ? make_pair(rhs, rpos) : make_pair(lhs, lpos); }

struct KineticTournament {
  Node* segTree;

  Node* build(int l, int r);

  KineticTournament(int n) : segTree(build(1, n)) {}

  void update(Node* o) {
    tie(o->lne, o->mpos) = max(o->ls->get(), o->rs->get(), o->ls->mpos, o->rs->mpos, o->x);
    o->cert = min({compete(o->lne - o->ls->get(), o->x), compete(o->lne - o->rs->get(), o->x),
                   o->ls->gcert(), o->rs->gcert()});
  }

  void pushDown(Node* o) {
    if (o->x) {
      o->ls->x += o->x;
      o->rs->x += o->x;
      o->x = 0;
    }
    if (o->lazy.k || o->lazy.b) {
      o->ls->lazy = o->ls->lazy + o->lazy;
      o->rs->lazy = o->rs->lazy + o->lazy;
      o->lazy = 0;
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

  pair<ll, int> qry(Node* o, int l, int r) {
    if (o->l == l && o->r == r)
      return make_pair(o->get()(o->x), o->mpos);
    pushDown(o);
    pair<ll, int> ret;
    if (r <= o->ls->r)
      ret = qry(o->ls, l, r);
    else if (l >= o->rs->l)
      ret = qry(o->rs, l, r);
    else
      ret = max(qry(o->ls, l, o->ls->r), qry(o->rs, o->rs->l, r));
    update(o);
    return ret;
  }

  pair<ll, int> qry(int l, int r) {
    return qry(segTree, l, r);
  }

  void change(Node* o, int l, int r, const Line& modify) {
    if (o->l == l && o->r == r) {
      o->lazy = o->lazy + modify;
      return;
    }
    pushDown(o);
    if (r <= o->ls->r) change(o->ls, l, r, modify);
    else if (l >= o->rs->l) change(o->rs, l, r, modify);
    else {
      change(o->ls, l, o->ls->r, modify);
      change(o->rs, o->rs->l, r, modify);
    }
    update(o);
  }

  void change(int l, int r, const Line& modify) { return change(segTree, l, r, modify); }
};

const int N = 100010;

int n;
int a[N];

Node* KineticTournament::build(int l, int r) {
  static Node pool[N * 2], *top = pool;
  Node* p = top++;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->lne = Line(a[l], a[l]);
    p->cert = INF;
    p->mpos = l;
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  update(p);
  return p;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  KineticTournament kt(n);
  ll ans = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    ll choose;
    int pos;
    tie(choose, pos) = kt.qry(1, n);
    cur += choose;
    ans = max(ans, cur);
    kt.change(pos, pos, Line(-a[pos], -INF));
    if (pos > 1)
      kt.change(1, pos - 1, a[pos]);
    if (pos < n)
      kt.increase(pos + 1, n, 1);
  }
  printf("%lld\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}