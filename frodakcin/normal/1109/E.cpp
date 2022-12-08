#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>
#include <array>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int N, M, Q;

const int MV = 1e5 + 100;
using i2 = array<int, 2>;
using vb = bitset<MV>;
using vi = vector<int>;
using vi2 = vector<i2>;
#define pb push_back
#define sz size()
#define bk back()

const int MP = 2e4;
const int MMP = 12;
const int MQ = 1e5 + 100;
const int MN = 1e5 + 100;
int p[MP], P;
vb w;
int d[MV], c[MV], n[MV];

void pcpp() {
  w.set();
  n[1] = -1, c[1] = 0, d[1] = -1;
  P = 0;
  for(int i = 2;i < MV;i++) {
    if(w[i]) {
      d[i] = P, c[i] = 1, n[i] = 1;
      p[P++] = i;
    }
    for(int j = 0, k;j < P&&(k=i*p[j]) < MV;j++) {
      w[k] = 0;
      d[k] = j;
      if(i%p[j]==0) {
        c[k] = c[i]+1, n[k] = n[i];
        break;
      } else
        c[k] = 1, n[k] = i;
    }
  }
}
int getfactors(int v, vi& f) {
  int T = v;
  for(int i = 0, j;i < P&&(j = p[i]) <= v;i++) {
    if(v%j == 0) {
      f.pb(i);
      v /= j;
      T = T/j*(j-1);
      while(v%j == 0) v /= j;
    }
  }
  if(v > 1)
    T = T/v*(v-1);
  return T;
}
int pw(int b, int p) {
  ll r = 1;
  for(;p;p>>=1,b=ti(tl(b)*b%M))if(p&1)r=r*b%M;
  return ti(r);
}

vi g;
vi h[MMP];
int T, a[MN];

void res(vi& v) {v.assign(g.sz, 0);}
struct DT {
public:
  vi d;
  int v[2], f;
  DT() {
    d.clear();
    for(int i : {0, 1}) v[i] = 1;
  }
  void init(int x) {
    f = x%M;
    d.assign(g.sz, 0);
    for(int i = 0, j;i < g.sz;i++) {
      j = p[g[i]];
      while(x%j == 0) x /= j, d[i]++;
    }
    v[0] = x;
    v[1] = 1;
  }
  void resf() {
    ll t = 1LL;
    for(int i = 0;i < g.sz;i++) t = t*h[i][d[i]]%M;
    f = ti(t*v[0]%M);
  }
  void av(int x) {
    v[0] = ti(tl(v[0])*x%M);
    f = ti(tl(f)*x%M);
  }
  void ad(const vi& x) {
    ll t = 1;
    for(int i = 0;i < g.sz;i++) t=t*h[i][d[i]+=x[i]]%M;
    f = ti(t*v[0]%M);
  }
  void avz(int x) {
    v[1] = ti(tl(v[1])*x%M);
    av(x);
  }
  void adz(const vi& x) {
    ad(x);
  }
  void az(int x, const vi& y) {
    avz(x);
    adz(y);
  }
};
template<int MS = MN<<2> struct ST {
public:
  DT v[MS];
  int s;
  void down(int n, int l, int r) {
    if(r-l>1) {
      v[n<<1].az(v[n].v[1], v[n].d);
      v[n<<1|1].az(v[n].v[1], v[n].d);
      res(v[n].d);
    }
    v[n].v[1] = 1;
    up(n);
  }
  void up(int n) {
    v[n].f = v[n].v[0] = (v[n<<1].f + v[n<<1|1].f)%M;
  }
  void init(int n, int l, int r) {
    if(r-l>1) {
      int m = l + ((r-l)>>1);
      init(n<<1, l, m), init(n<<1|1, m, r);
      v[n].init(1);
      up(n);
    } else
      v[n].init(a[l]);
  }
  void init(int S) {
    s = S;
    init(1, 0, s);
  }
  void upd(int n, int l, int r, int ql, int qr, int x, const vi& d) {   //If dividing, only works when r-l==1
    if(ql <= l&&r <= qr)
      v[n].az(x, d);
    else {
      down(n, l, r);
      int m = l + ((r-l)>>1);
      if(ql < m) upd(n<<1, l, m, ql, qr, x, d);
      if(m < qr) upd(n<<1|1, m, r, ql, qr, x, d);
      up(n);
    }
  }
  void upd(int ql, int qr, int x, const vi& d) {upd(1, 0, s, ql, qr, x, d);}
  int qry(int n, int l, int r, int ql, int qr) {
    if(ql <= l&&r <= qr) return v[n].f;
    else {
      down(n, l, r);
      int m = l + ((r-l)>>1);
      int f = 0;
      if(ql < m) f = (f+qry(n<<1, l, m, ql, qr))%M;
      if(m < qr) f = (f+qry(n<<1|1, m, r, ql, qr))%M;
      return f;
    }
  }
  int qry(int ql, int qr) {return qry(1, 0, s, ql, qr);}
};
ST<> st;

int lg(int b, int v) {
  int x = 1;
  while(v/=b)x++;
  return x;
}

void mul() {
  int l, r, x;
  scanf("%d%d%d", &l, &r, &x);
  vi v(g.sz, 0);
  for(int i = 0, j;i < g.sz;i++) {
    j = p[g[i]];
    for(;x%j==0;x/=j) v[i]++;
  }
  st.upd(--l, r, x, v);
}
void dv() {   //NOTE* This fails if r-l>1
  int l, r, x;
  scanf("%d%d", &l, &x), r = l;
  vi v(g.sz, 0);
  for(int i = 0, j;i < g.sz;i++) {
    j = p[g[i]];
    for(;x%j==0;x/=j) v[i]--;
  }
  st.upd(--l, r, pw(x, T-1), v);
}
void ans() {
  int l, r;
  scanf("%d%d", &l, &r);
  printf("%d\n", st.qry(--l, r));
}

int main() {
  pcpp();
  
  scanf("%d%d", &N, &M);
  T = getfactors(M, g);
  for(int i = 0, x, j, k;i < g.sz;i++) {
    h[i].clear();
    h[i].pb(1);
    k = MQ*lg(p[g[i]], MV);
    for(j = 0;j < k;j++)
      h[i].pb(ti(tl(h[i].bk)*p[g[i]]%M));
  }
  
  for(int i = 0;i < N;i++) scanf("%d", a + i);
  st.init(N);
  
  scanf("%d", &Q);
  for(int i = 0, q;i < Q;i++) {
    scanf("%d", &q);
    if(q == 1) mul();
    if(q == 2) dv();
    if(q == 3) ans();
  }
  
  return 0;
}