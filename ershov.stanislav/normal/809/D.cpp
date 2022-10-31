#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

struct node {
  node *l, *r;
  int cnt;
  int val;
  int toadd;

  node(int val = 0) : l(0), r(0), cnt(1), val(val), toadd(0) {}
};

int getcnt(node *a) {
  if (!a) {
    return 0;
  } else {
    return a->cnt;
  }
}

void update(node *a) {
  a->cnt = 1 + getcnt(a->l) + getcnt(a->r);
  a->toadd = 0;
}

void push(node *a) {
  if (a->l) {
    a->l->toadd += a->toadd;
    a->l->val += a->toadd;
  }
  if (a->r) {
    a->r->toadd += a->toadd;
    a->r->val += a->toadd;
  }
  a->toadd = 0;
}

node* merge(node * a, node * b) {
  if (!a) {
    return b;
  }
  if (!b) {
    return a;
  }
  push(a);
  push(b);
  if (rnd(a->cnt + b->cnt) < a->cnt) {
    a->r = merge(a->r, b);
    update(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    update(b);
    return b;
  }
}

void splitcnt(node *a, int cnt, node *&l, node *&r) {
  if (!a) {
    l = 0, r = 0;
    return;
  } else {
    push(a);
    int cntleft = getcnt(a->l);
    if (cntleft + 1 <= cnt) {
      splitcnt(a->r, cnt - cntleft - 1, a->r, r);
      l = a;
      update(a);
    } else {
      splitcnt(a->l, cnt, l, a->l);
      r = a;
      update(a);
    }
  }
}

void splitval(node *a, int val, node *&l, node *&r) {
  if (!a) {
    l = 0, r = 0;
    return;
  } else {
    push(a);
    if (a->val < val) {
      splitval(a->r, val, a->r, r);
      l = a;
      update(a);
    } else {
      splitval(a->l, val, l, a->l);
      r = a;
      update(a);
    }
  }
}

const int maxn = 3e5 + 100;

int n;
int ls[maxn], rs[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", ls + i, rs + i);
  }
  return true;
}

void print(node *v) {
  if (!v) {
    return;
  }
  push(v);
  print(v->l);
  eprintf("%d\n", v->val);
  print(v->r);
}

void solve() {
  node *root = 0;
  for (int i = 0; i < n; i++) {
    node *l, *mid, *r;
    splitval(root, ls[i], l, mid);
    splitval(mid, rs[i], mid, r);
    node *tmp;
    splitcnt(r, 1, tmp, r);
    if (mid) {
      mid->toadd++;
      mid->val++;
    }
    root = merge(l, new node(ls[i]));
    root = merge(root, mid);
    root = merge(root, r);
    //print(root);
    //eprintf("/\n");
  }
  printf("%d\n", root->cnt);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}