#include <cstdio>

#include <vector>
#include <valarray>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef valarray<int> VAI;

const int N = 100010, L = 9;

int C;
int MOD;
int pr[L];
vector<int> qw[L];

int gqw(int i, int k) {
  while (qw[i].size() <= k) {
    int ori = qw[i].size();
    qw[i].resize(ori << 1);
    for (int j = 0; j < ori; ++j)
      qw[i][j + ori] = qw[i][j + ori - 1] * (ll)pr[i] % MOD;
  }
  return qw[i][k];
}

int gv(const VAI& dest) {
  int ret = 1;
  for (int i = 0; i < C; ++i)
    ret = ret * (ll)gqw(i, dest[i]) % MOD;
  return ret;
}

pair<int, VAI> pump(int v) {
  VAI pf(C);
  for (int i = 0; i < C; ++i) {
    while (v % pr[i] == 0) {
      v /= pr[i];
      ++pf[i];
    }
  }
  return make_pair(v, pf);
}

void exGcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, MOD, x, y);
  if (x < 0)
    x += MOD;
  return x;
}

struct Node {
  int l, r;
  int v, lazy;
  VAI pf;
  Node *ls, *rs;
  
  int get() const {
    //LOG("%d %d\n", v, int(v * (ll)gv(pf)));
    return v * (ll)gv(pf) % MOD * lazy % MOD;
  }
  
  void down() {
    v = get();
    ls->pf += pf;
    rs->pf += pf;
    pf = 0;
    if (lazy != 1) {
      ls->lazy = ls->lazy * (ll)lazy % MOD;
      rs->lazy = rs->lazy * (ll)lazy % MOD;
      lazy = 1;
    }
  }
  
  void up() {
    v = ls->get() + rs->get();
    if (v >= MOD)
      v -= MOD;
  }

  void ch(int l, int r, int v, const VAI& ex) {
    if (this->l == l && this->r == r) {
      lazy = lazy * (ll)v % MOD;
      pf += ex;
      return;
    }
    down();
    if (r <= ls->r)
      ls->ch(l, r, v, ex);
    else if (l >= rs->l)
      rs->ch(l, r, v, ex);
    else {
      ls->ch(l, ls->r, v, ex);
      rs->ch(rs->l, r, v, ex);
    }
    up();
  }
  
  int qry(int l, int r) {
    if (this->l == l && this->r == r) {
      //LOG("REAL %d\n", v);
      return get();
    }
    down();
    if (r <= ls->r)
      return ls->qry(l, r);
    if (l >= rs->l)
      return rs->qry(l, r);
    int ret = ls->qry(l, ls->r) + rs->qry(rs->l, r);
    if (ret >= MOD) ret -= MOD;
    return ret;
  }
};

int n;

Node* seg;

Node* build(int l, int r) {
  static Node pool[N * 2];
  static Node* ptop = pool;
  Node* p = ptop++;
  p->l = l;
  p->r = r;
  p->pf.resize(C);
  p->lazy = 1;
  if (l == r) {
    int a;
    scanf("%d", &a);
    pair<int, VAI> res = pump(a);
    p->v = res.first % MOD;
    p->pf = res.second;
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->up();
  //LOG("%d %d: %d\n", l, r, p->get());
  return p;
}

void prepare() {
  int x = MOD;
  for (int y = 2; y * y <= x; ++y)
    if (x % y == 0) {
      while (x % y == 0)
        x /= y;
      pr[C++] = y;
    }
  if (x != 1)
    pr[C++] = x;
  for (int i = 0; i < C; ++i)
    qw[i] = vector<int>(1, 1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  scanf("%d%d", &n, &MOD);
  prepare();
  seg = build(1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int opt, x, y, z;
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1) {
      scanf("%d", &z);
      pair<int, VAI> res = pump(z);
      seg->ch(x, y, res.first % MOD, res.second);
    } else if (opt == 2) {
      pair<int, VAI> res = pump(y);
      seg->ch(x, x, inv(res.first % MOD), -res.second);
    } else {
      printf("%d\n", seg->qry(x, y));
    }
  }
  return 0;
}