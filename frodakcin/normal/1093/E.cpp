#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 2e5 + 100;

int N, M;
int a[MAXN], b[MAXN], t[MAXN], aR[MAXN];

typedef vector<int> vi;
#define pb push_back

struct ND {
  int v;
  int s, h;
  ND * l, * r;
  ND(const int& v = 0, const int& s = 1, const int& h = 1) : v(v), s(s), h(h), l(nullptr), r(nullptr) {}
  bool operator < (const ND& o) {return v < o.v;}
  ND * swapl() {
    swap(s, l->s);swap(h, l->h);
    ND * o = l, * t;
    t=r;r=o->r;o->r=t;
    l=o->l;o->l=this;
    return o;
  }
  ND * swapr() {
    swap(s, r->s);swap(h, r->h);
    ND * o = r, * t;
    t=l;l=o->l;o->l=t;
    r=o->r;o->r=this;
    return o;
  }
  ND * swap_pos(ND * o) {
    assert(this != o);
    if(l == o) return swapl();
    if(r == o) return swapr();
    if(o->l == this) return o->swapl();
    if(o->r == this) return o->swapr();
    swap(s, o->s);swap(h, o->h);
    ND * t;
    t=l;l=o->l;o->l=t;
    t=r;r=o->r;o->r=t;
    return o;
  }
};
struct AVL {
  ND * h;
  AVL(ND * h = nullptr) : h(h) {}
  int gs(ND * n) const {if(n) return n->s; else return 0;}
  int gh(ND * n) const {if(n) return n->h; else return 0;}
  void chk(ND * n) {assert(n->s == gs(n->l) + gs(n->r) + 1 and n->h == max(gh(n->l), gh(n->r)) + 1);}
  void upd(ND * n) {
    assert(n);
    n->s = gs(n->l) + gs(n->r) + 1;
    n->h = max(gh(n->l), gh(n->r)) + 1;
  }
  ND * L(ND * n) {
    assert(n and n->r);
    ND * u = n->r;
    n->r = u->l;
    u->l = n;
    upd(n);upd(u);
    return u;
  }
  ND * R(ND * n) {
    assert(n and n->l);
    ND * u = n->l;
    n->l = u->r;
    u->r = n;
    upd(n);upd(u);
    return u;
  }
  ND * bal(ND * n) {
    int b = gh(n->l) - gh(n->r);
    if(b < -1) {
      if(gh(n->r->r) + 1 == n->r->h) {
        return L(n);
      } else {
        n->r = R(n->r);
        return L(n);
      }
    }
    if(b > 1) {
      if(gh(n->l->l) + 1 == n->l->h) {
        return R(n);
      } else {
        n->l = L(n->l);
        return R(n);
      }
    }
    return n;
  }
  ND * ins(ND * n, int v) {
    if(not n) return new ND(v);
    if(v < n->v) n->l = ins(n->l, v);
    else if(n->v < v) n->r = ins(n->r, v);
    upd(n);
    return bal(n);
  }
  void ins(int v) {h = ins(h, v);}
  ND * ersl(ND * n, ND *& p) {
    if(not n->l) {
      ND * r = n->r;
      n->l=p->l;n->r=p->r;
      p = n;
      return r;
    }
    n->l = ersl(n->l, p);
    upd(n);
    return bal(n);
  }
  ND * ers(ND * n, int v) {
    if(not n) return n;
    if(v < n->v) n->l = ers(n->l, v);
    else if(n->v < v) n->r = ers(n->r, v);
    else {
      if(n->r and n->l) {
        ND * nr = ersl(n->r, n);
        n->r = nr;
        upd(n);
        return bal(n);
      }
      if(n->l) return n->l;
      else return n->r;
    }
    upd(n);
    return bal(n);
  }
  void ers(int v) {h = ers(h, v);}
  
  int pos(ND * n, int v) const {
    if(not n) return 0;
    if(n->v < v) return 1 + gs(n->l) + pos(n->r, v);
    else return pos(n->l, v);
  }
  int pos(int v) const {return pos(h, v);}
  
  void fill(ND * n, vi& v) const {
    if(not n) return;
    fill(n->l, v);v.pb(n->v);fill(n->r, v);
  }
  void fillr(ND * n, vi& v) const {
    if(not n) return;
    fillr(n->r, v);v.pb(n->v);fillr(n->l, v);
  }
  
  ND * build(vi& v, int l, int r) {
    if(l >= r) return nullptr;
    if(r - l == 1) return new ND(v[l]);
    int m = l + ((r-l)>>1);
    ND * n = new ND(v[m]);
    n->l = build(v, l, m), n->r = build(v, m + 1, r);
    upd(n);
    return n;
  }
  AVL operator + (const AVL& a) {
    vi v[2];
    v[0].clear();v[1].clear();
    fillr(h, v[0]);fillr(a.h, v[1]);
    vi f(0, -1);
    //for(int i = 0;i < v[0].size();i++) cerr << v[1][i] << " "; cerr << "\n";
    while(not v[0].empty() or not v[1].empty()) {
      if(v[1].empty() or (not v[0].empty() and v[0].back() < v[1].back())) f.pb(v[0].back()), v[0].pop_back();
      else f.pb(v[1].back()), v[1].pop_back();
    }
    //for(int i = 0;i < f.size();i++) cerr << f[i] << " "; cerr << "\n";
    unique(f.begin(), f.end());   //<-- shouldn't be necessary actually
    AVL r;
    r.h = build(f, 0, f.size());
    return r;
  }
};
ostream& operator << (ostream& os, const ND * n) {
  if(n == nullptr) return os;
  return os << n->l << n->v << ", " << n->r;
}
ostream& operator << (ostream& os, const AVL& a) {return os << "[" << a.h << "]";}

int get(const AVL& avl, int gx, int gy) {
  return avl.pos(gy+1) - avl.pos(gx);
}

const int MAXS = MAXN * 4;
struct BIT {
  AVL v[MAXN];
  void upd(int g, int q, bool T) {
    for(int i = g;i <= N;i += (-i)&i)
      if(T) v[i].ins(q); else v[i].ers(q);
  }
  int qry(int g, int x, int y) {
    int r = 0;
    for(int i = g;i;i -= (-i)&i)
      r += v[i].pos(y + 1) - v[i].pos(x);
    return r;
  }
} bit;

int q[4], I;

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 1;i <= N;i++) scanf("%d", a + i), aR[a[i]] = i;
  for(int i = 1;i <= N;i++) scanf("%d", b + i), t[i] = b[i];
  
  for(int i = 1;i <= N;i++) b[i] = aR[t[i]];
  
  for(int i = 1;i <= N;i++) bit.upd(i, b[i], true);
  
  //return 0;
  while(M--) {
    scanf("%d", &I);
    if(I == 1) {
      for(int i = 0;i < 4;i++) scanf("%d", q + i);
      printf("%d\n", bit.qry(q[3], q[0], q[1]) - bit.qry(q[2] - 1, q[0], q[1]));
    } else {
      for(int i = 0;i < 2;i++) scanf("%d", q + i);
      swap(b[q[0]], b[q[1]]);
      bit.upd(q[1], b[q[0]], false);bit.upd(q[0], b[q[0]], true);
      bit.upd(q[0], b[q[1]], false);bit.upd(q[1], b[q[1]], true);
    }
  }
  
  return 0;
}