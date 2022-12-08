#include <iostream>
#include <cstdio>

#include <set>
#include <algorithm>
#include <cmath>
#include <array>
#include <utility>

#include <cassert>

using namespace std;

#define ti(X) static_cast<int>(X)
using ll = long long;
#define tl(X) static_cast<ll>(X)
using ld = double;
#define tld(X) static_cast<ld>(X)

const int MQ = 1e5 + 100;
const int MV = 1e9 + 100;

int p[MQ<<1], P;

const ld EPS = 1e-4;
bool equ(ld a, ld b) {return fabs(a-b)<EPS;}

struct DT {
public:
  int l, r;
  ll v, u;
  int z;
  DT() : l(0), r(0), v(0LL), u(0LL), z(MV) {}
  DT(int l, int r) : l(l), r(r), v(0LL), u(0LL), z(MV) {}
  void set(int l, int r) {this->l = l, this->r = r;}
  ld operator [] (ll& q) const {
    if(q == 0) return l;
    assert(q + v <= 0);
    return l + tld(q)*(r-l)/(-v);
  }
};
template<int MS = MQ<<3> struct ST {
public:
  DT v[MS];
  int s;
  void sv(int n, int d) {
    v[n].v = tl(v[n].r-v[n].l)*d;
    v[n].u = d<0?v[n].v:0LL;
  }
  void sz(int n, int d) {
    sv(n, d);
    v[n].z = d;
  }
  void down(int n, int l, int r) {
    if(v[n].z == MV) return;
    if(r-l>1) sz(n<<1, v[n].z), sz(n<<1|1, v[n].z);
    v[n].z = MV;
  }
  void up(int n) {
    v[n].v = v[n<<1].v + v[n<<1|1].v;
    v[n].u = min(v[n<<1].u, v[n<<1].v + v[n<<1|1].u);
  }
  void init(int n, int l, int r) {
    if(r-l>1) {
      int m = l + ((r-l)>>1);
      init(n<<1, l, m), init(n<<1|1, m, r);
    }
    v[n].set(p[l], p[r]);
  }
  void init(int S) {
    s = S;
    init(1, 0, s);
  }
  void upd(int n, int l, int r, int ql, int qr, int q) {
    if(ql <= l&&r <= qr) sz(n, q);
    else {
      down(n, l, r);
      int m = l + ((r-l)>>1);
      if(ql < m) upd(n<<1, l, m, ql, qr, q);
      if(m < qr) upd(n<<1|1, m, r, ql, qr, q);
      up(n);
    }
  }
  void upd(int ql, int qr, int q) {upd(1, 0, s, ql, qr, q);}
  ld qry(int n, int l, int r, int ql, int qr, ll& q) {
    down(n, l, r);
    if(ql <= l&&r <= qr) {
      if(q + v[n].u > 0) return q += v[n].v, -1.0;
      if(r-l>1) {
        int m = l + ((r-l)>>1);
        if(q + v[n<<1].u <= 0) return qry(n<<1, l, m, ql, qr, q);
        else return qry(n<<1|1, m, r, ql, qr, q += v[n<<1].v);
      } else return v[n][q];
    } else {
      int m = l + ((r-l)>>1);
      ld f = -1.0;
      if(ql < m) {
        f = qry(n<<1, l, m, ql, qr, q);
        if(!equ(f, -1.0)) return f;
      }
      if(m < qr) return qry(n<<1|1, m, r, ql, qr, q);
      return -1.0;
    }
  }
  ld qry(int ql, int qr, ll& q) {return qry(1, 0, s, ql, qr, q);}
};
ST<> st;

int Q;
int q[MQ][4];

void cmpr() {
  sort(p, p + P);
  P = unique(p, p + P) - p;
  for(int i = 0;i < Q;i++) {
    q[i][1] = lower_bound(p, p + P, q[i][1])-p;
    if(q[i][0]==3)
      q[i][2] = lower_bound(p, p+P, q[i][2])-p;
  }
  p[P] = MV;
}
using i2 = array<int, 2>;
bool operator < (const i2& a, const i2& b) {return a[0] < b[0] || (!(b[0] < a[0]) && a[1] < b[1]);}
using si = set<i2>;
#define IT iterator
using sit = si::IT;
si v;
void ins(int t, int s) {
  sit l = v.insert({t, s}).first;
  st.upd(t, (++l)->at(0), s);
}
void rem(int t) {
  sit p = v.lower_bound({t, -MV}), n = p;
  assert(p->at(0)==t);
  n = v.erase(n), p = n;
  if(p == v.begin()) st.upd(t, n->at(0), 0);
  else st.upd(t, n->at(0), (--p)->at(1));
}
int qry(int l, int r, ll& q) {
  if(q <= 0) return printf("%d\n", p[l]);
  l = v.lower_bound({l, -MV})->at(0);
  if(l >= r) return printf("-1\n"), 0;
  ld x = st.qry(l, r, q);
  if(equ(x, -1)) printf("-1\n");
  else printf("%.15f\n", x);
  return 0;
}
void solve() {
  v.insert({P, -1});
  ll t;
  for(int i = 0;i < Q;i++) {
    int * c = q[i];
    if(c[0] == 1) ins(c[1], c[2]);
    if(c[0] == 2) rem(c[1]);
    if(c[0] == 3) qry(c[1], c[2], t = tl(c[3]));
  }
}
int main() {
  scanf("%d", &Q);
  P = 0;
  for(int i = 0;i < Q;i++) {
    scanf("%d", q[i]);
    if(q[i][0] == 1) scanf("%d%d", q[i]+1, q[i]+2), p[P++] = q[i][1];
    if(q[i][0] == 2) scanf("%d", q[i]+1);
    if(q[i][0] == 3) scanf("%d%d%d", q[i]+1, q[i]+2, q[i]+3), p[P++] = q[i][1], p[P++] = q[i][2];
  }
  cmpr();
  st.init(P);
  solve();
  
  return 0;
}