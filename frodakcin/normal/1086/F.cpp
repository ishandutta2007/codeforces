#include <iostream>
#include <cstdio>

#include <array>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MOD = 998244353;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
int dif(int a, int b) {return ti((tll(a) - tll(b) + (tll(MOD)<<6LL))%MOD);}
int prd(int a, int b) {return ti((tll(a) * tll(b))%MOD);}
int sqr(int a) {return prd(a, a);}
int pw(int b, int p) {
  int r = 1;
  for(;p;p>>=1, b=prd(b, b)) if(p&1) r = prd(r, b);
  return r;
}

int dv2;
int sumlin(int v) {
  if(v < 0) return 0;
  return prd(prd(v, v + 1), dv2);
}
int sumlin(int l, int r) {
  return sumlin(r - 1) - sumlin(l - 1);
}
int dv6;
int sumsqr(int v) {
  if(v < 0) return 0;
  return prd(prd(v, v + 1), prd((v << 1) + 1, dv6));
}
int sumsqr(int l, int r) {
  return sumsqr(r - 1) - sumsqr(l - 1);
}

typedef array<int, 2> ar2;
typedef array<int, 3> ar3;
typedef vector<int> vi;
typedef vector<ar2> va2;

int get(const ar3& a, int b) {
  return sum(prd(a[2], prd(b, b)), sum(prd(a[1], b), a[0]));
}
int get(const vi& a, int l, int r) {
  int f = 0;
  f = sum(f, prd(a[2], sumsqr(l, r)));
  f = sum(f, prd(a[1], sumlin(l, r)));
  f = sum(f, prd(a[0], r - l));
  return f;
}
ar3 operator + (const ar3& a, const ar3& b) {
  return {sum(a[0], b[0]), sum(a[1], b[1]), sum(a[2], b[2])};
}

typedef array<int, 2> pt;
typedef array<int, 4> ar4;

const int MAXN = 60;
int N, T;
pt I[MAXN];

template <class T> void compress(T * n, int& s) {
  sort(n, n + s);
  s = unique(n, n + s) - n;
}

int y[MAXN << 1];
int ys;

template <int MAXS = MAXN << 3> struct ST {
public:
  ar2 v[MAXS];
  int z[MAXS];
  int s;
  ar2 cmb(const ar2& a, const ar2& b) {
    if(a[0] == b[0]) return {a[0], a[1] + b[1]};
    if(b[0] < a[0]) return b;
    return a;
  }
  void init(int n, int nl, int nr) {
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      init(n<<1, nl, m); init(n<<1|1, m, nr);
      v[n] = {0, y[nr] - y[nl]}, z[n] = 0;
    } else v[n] = {0, y[nr] - y[nl]}, z[n] = 0;
  }
  void init(int S) {
    init(1, 0, s = S);
  }
  void prop(int n, int nl, int nr) {
    v[n][0] += z[n];
    if(nr - nl > 1)
      z[n<<1] += z[n], z[n<<1|1] += z[n];
    z[n] = 0;
  }
  void upd(int gl, int gr, int q, int n, int nl, int nr) {
    if(gl <= nl and nr <= gr) {
      z[n] += q;
      prop(n, nl, nr);
    } else {
      int m = nl + ((nr - nl)>>1);
      prop(n, nl, nr);
      if(gl < m) upd(gl, gr, q, n<<1, nl, m); else prop(n<<1, nl, m);
      if(m < gr) upd(gl, gr, q, n<<1|1, m, nr); else prop(n<<1|1, m, nr);
      v[n] = cmb(v[n<<1], v[n<<1|1]);
    }
  }
  void upd(int gl, int gr, int q) {return upd(gl, gr, q, 1, 0, s);}
  int qry() {prop(1, 0, s); return v[1][0] == 0 ? (y[s] - y[0]) - v[1][1] : (y[s] - y[0]);}    //# of non-zeroes
};
ST<> st;
ar4 x[MAXN << 1];
int calc(int t) {
  for(int i = 0;i < N;i++) y[i<<1] = I[i][1] - t, y[i<<1|1] = I[i][1] + t + 1, x[i<<1] = {I[i][0] - t, I[i][1] - t, I[i][1] + t + 1, 1}, x[i<<1|1] = {I[i][0] + t + 1, I[i][1] - t, I[i][1] + t + 1, -1};
  ys = N<<1, compress(y, ys);
  for(int i = 0;i < N<<1;i++) x[i][1] = lower_bound(y, y + ys, x[i][1]) - y, x[i][2] = lower_bound(y, y + ys, x[i][2]) - y;
  st.init(--ys);
  
  ll f = 0;
  
  sort(x, x + (N<<1), [](const ar4& a, const ar4& b){return a[0] < b[0];});
  
  int c = 0;
  for(int i = 0, j;i < N<<1;i=j) {
    for(j = i;j < N<<1 and x[i][0] == x[j][0];j++) {
      st.upd(x[j][1], x[j][2], x[j][3]);
    }
    if((c = st.qry())) f += tll(c) * (x[j][0] - x[i][0]);
  }
  assert(c == 0);
  return ti(f%MOD);
}

int operator * (const pt& a, const pt& b) {
  return max((1 + abs(a[0] - b[0]))>>1, (1 + abs(a[1] - b[1]))>>1);
}

int c[MAXN * MAXN];

vi operator * (const vi& a, const vi& b) {
  vi r(a.size() + b.size() - 1, 0);
  for(int i = 0;i < a.size();i++) for(int j = 0;j < b.size();j++) r[i + j] = sum(r[i + j], prd(a[i], b[j]));
  return r;
}
vi operator *= (vi& a, const int& b) {
  for(int i = 0;i < a.size();i++) a[i] = prd(a[i], b);
  return a;
}
vi operator += (vi& a, const vi& b) {
  assert(not(a.size() < b.size()));
  for(int i = 0;i < b.size();i++) a[i] = sum(a[i], b[i]);
  return b;
}

vi interpolate(const va2& p) {
  vi r(p.size(), 0);
  for(int i = 0;i < p.size();i++) {
    vi n(1, 1);
    int d = 1;
    for(int j = 0;j < p.size();j++) if(j != i) {
      n = n * vi{dif(0, p[j][0]), 1};
      d = prd(d, dif(p[i][0], p[j][0]));
    }
    n *= prd(pw(d, MOD - 2), p[i][1]);
    assert(n.size() == r.size());
    r += n;
  }
  return r;
}

int solve(int t1, int t2) {
  if(t2 - t1 < 3) {
    int f = 0;
    for(int i = t1;i < t2;i++) f = sum(f, calc(i));
    return f;
  }
  
  vi q = interpolate(va2{{t1, calc(t1)}, {t1 + 1, calc(t1 + 1)}, {t1 + 2, calc(t1 + 2)}});
  //cerr << q[0] << " " << q[1] << " " << q[2] << "\n";
  //cerr << get(q, t1, t2) << "\n";
  return get(q, t1, t2);
}

int main() {
  dv2 = pw(2, MOD - 2);
  dv6 = pw(6, MOD - 2);
  
  scanf("%d%d", &N, &T);
  for(int i = 0;i < N;i++) scanf("%d%d", &I[i][0], &I[i][1]), y[i] = I[i][1];
  
  //sort(I, I + N, [](const pt& a, const pt& b) {return a[0] < b[0] or (not(b[0] < a[0]) and a[1] < b[1]);});
  
  for(int i = 0, t = 0;i < N;i++) for(int j = i + 1;j < N;j++) c[t++] = I[i] * I[j];
  sort(c, c + (N*(N - 1)>>1));
  ll f = 0LL;
  int p = 0;
  for(int i = 0;i < (N*(N-1))>>1;p = c[i++]) {
    if(c[i] < T) f = sum(f, solve(p, c[i])); else break;
  }
  f = sum(f, solve(p, T));
  
  printf("%d\n", dif(prd(T, calc(T)), f));
  
  return 0;
}