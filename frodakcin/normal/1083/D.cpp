#include <iostream>
#include <cstdio>

#include <algorithm>
#include <vector>
#include <array>
#include <deque>

using namespace std;

const int MN = 1e5 + 1000;

void cmp(int * s, int * e) {
  int m[MN];
  for(int * a = s;a != e;a++) m[a-s]=*a;
  sort(m, m + (e-s));
  int v = unique(m, m + (e-s)) - m;
  for(;s != e;s++) *s = lower_bound(m, m + v, *s) - m;
}

#define ti(X) static_cast<int>(X)
using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MD = 1e9 + 7;
const ll MDD = 10LL * MD;

void add(ll& a, const ll& b) {a=(a+b)%MD;}

int N;
int a[MN];

using vi = vector<int>;
#define pb push_back

vi p[MN];
int c[MN];

int R(int i) {if(c[i] + 1 < p[a[i]].size()) return p[a[i]][c[i] + 1] - 1; else return N - 1;}
int L(int i) {if(c[i] > 0) return p[a[i]][c[i]-1] + 1; else return 0;}

const ll NN = -100LL;

ll sm(int v) {return tl(v+1)*v>>1;}

using a2 = array<ll, 2>;
using a4 = array<ll, 4>;

int x;
struct DT {
  DT() {z = {NN, NN}, v = {0LL, 0LL, 0LL, 0LL};};
  a2 z;
  a4 v;   //sum L, sum R, sum L*R, sum R*i
  void prop(int l, int r) {
    if(z[0] != NN) {
      v[0] = z[0]*(r-l)%MD;
      v[2] = z[0]*v[1]%MD;
      z[0] = NN;
    }
    if(z[1] != NN) {
      v[1] = z[1]*(r-l)%MD;
      v[2] = z[1]*v[0]%MD;
      v[3] = (sm(r-1) - sm(l-1))%MD*z[1]%MD;
      z[1] = NN;
    }
  }
  DT operator + (const DT& o) const {
    DT r;
    for(int i = 0;i < 4;i++) r.v[i] = (v[i] + o.v[i])%MD;
    return r;
  };
};
template<int MS = MN * 3> struct ST {
public:
  DT v[MS];
  int s;
  void init(int z) {s = z;}
  void prop(int n, int l, int r) {
    if(r - l > 1) for(int i : {0, 1}) if(v[n].z[i] != NN) v[n<<1].z[i] = v[n<<1|1].z[i] = v[n].z[i];
    v[n].prop(l, r);
  }
  void upd(int n, int l, int r, int gl, int gr, int w, int q) {
    if(gl <= l and r <= gr) {
      v[n].z[w] = q;
      prop(n, l, r);
      return;
    }
    prop(n, l, r);
    int m = l + ((r-l)>>1);
    if(gl < m) upd(n<<1, l, m, gl, gr, w, q); else prop(n<<1, l, m);
    if(m < gr) upd(n<<1|1, m, r, gl, gr, w, q); else prop(n<<1|1, m, r);
    v[n] = v[n<<1] + v[n<<1|1];
  }
  void upd(int gl, int gr, int w, int q) {upd(1, 0, s, gl, gr, w, q);}
  ll qry(int n, int l, int r, int gl, int gr) {
    if(gl <= l and r <= gr) return (v[n].v[3] + v[n].v[0]*x%MD - v[n].v[2] + MDD)%MD;
    int m = l + ((r-l)>>1);
    ll f = 0LL;
    if(gl < m) f += qry(n<<1, l, m, gl, gr);
    if(m < gr) f += qry(n<<1|1, m, r, gl, gr);
    return f%MD;
  }
  ll qry(int gl, int gr) {if(gl < gr) return qry(1, 0, s, gl, gr); else return 0LL;}
};
ST<> st;

using i2 = array<int, 2>;
using qi = deque<i2>;

void lb(qi& q, int l) {
  if(q.empty()) return;
  for(;;) {
    i2 x = q.front();
    q.pop_front();
    if(q.empty() or l < q.front()[0]) {
      q.push_front({l, x[1]});
      break;
    }
  }
}
int rbl(qi& q, int x, int v) {
  for(;;) {
    if(q.empty() or q.back()[1] > v) {
      q.push_back({x, v});
      return x;
    }
    x = q.back()[0]; q.pop_back();
  }
  return -1;
}
int rbr(qi& q, int x, int v) {
  for(;;) {
    if(q.empty() or q.back()[1] < v) {
      q.push_back({x, v});
      return x;
    }
    x = q.back()[0], q.pop_back();
  }
  return -1;
}

int main() {
  for(int i = 0;i < MN;i++) p[i].clear(), c[i] = -1;
  
  scanf("%d", &N);
  
  for(int i = 0;i < N;i++) scanf("%d", a + i);
  cmp(a, a + N);
  
  for(int i = 0;i < N;i++) c[i] = p[a[i]].size(), p[a[i]].pb(i);
  
  qi l, r;    //[pos, val]
  
  st.init(N + 10);
  
  ll f = 0;
  int e = 0, u;
  for(x = 0;x < N;x++) {
    u = L(x);
    if(e < u + 1) e = u + 1;
    lb(l, e);
    lb(r, e);
    st.upd(rbl(l, x, u), x + 1, 0, u);
    u = R(x), st.upd(rbr(r, x, u), x + 1, 1, u);
    
    if(e < x + 1) add(f, st.qry(e, x + 1) - (sm(x)-sm(e-1))%MD*x%MD + MD);
  }
  
  printf("%lld\n", f);
  
  return 0;
}