#include <iostream>
#include <cstdio>

#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MAXN = 1e5 + 100;
const int INF = 1e9 + 1000;

int N, Q;

struct P {
public:
  int s, m, r;
  int c;
  int upd() {return c = r ? m/r : INF;}
  P(int s = 0, int m = 0, int r = 1) : s(s), m(m), r(r) {upd();}
  int operator [] (const int& t) const {
    if(m < s + tll(t) * r) return m; else return s + tll(t) * r;
  }
  bool operator < (const P& o) const {return c < o.c;}
  bool operator < (const int& t) {return c < t;}
} p[MAXN];

ll brute(int l, int r, int t) {
  ll a = 0LL;
  for(int i = l;i < r;i++) a += p[i][t];
  return a;
}

typedef vector<P> vp;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back

struct DAT {
public:
  vp v;
  vl m, r;
  int L;
  void upd() {
    L = v.size(); m.assign(L, 0), r.assign(L, 0);
    for(int i = 0;i < L;i++) m[i] = i == 0 ? v[i].m : m[i-1] + v[i].m;
    for(int i = L - 1;i >= 0;i--) r[i] = i == L - 1 ? v[i].r : r[i+1] + v[i].r;
  }
  DAT() {v.clear(), m.clear(), r.clear();}
  ll operator [] (const int& t) {
    int l = -1, h = L;
    while(h > l + 1) {
      int m = l + ((h - l)>>1);
      if(v[m] < t) l = m;
      else h = m;
    }
    return (l != -1 ? m[l] : 0LL) + (h != L ? r[h] * t : 0LL);
  }
  DAT operator + (const DAT& o) const {
    DAT f;
    int i = 0;
    for(const P& q : v) {
      while(i < o.L and o.v[i] < q) f.v.pb(o.v[i++]);
      f.v.pb(q);
    }
    for(;i < o.L;i++) f.v.pb(o.v[i]);
    f.upd();
    return f;
  }
};

template <int MAXS = MAXN * 4>
struct ST {
public:
  DAT v[MAXS];
  int s;
  void init(int n, int nl, int nr) {
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      init(n<<1, nl, m);
      init(n<<1|1, m, nr);
      v[n] = v[n<<1] + v[n<<1|1];
    } else
      v[n].v.pb(p[nl]), v[n].upd();
  }
  void init(const int& z) {
    s = z;
    init(1, 0, s);
  }
  ll qry(int gl, int gr, int t, int n, int nl, int nr) {
    if(gl <= nl and nr <= gr) {
      return v[n][t];
    } else {
      int m = nl + ((nr - nl)>>1);
      ll r = 0LL;
      if(gl < m) r += qry(gl, gr, t, n<<1, nl, m);
      if(m < gr) r += qry(gl, gr, t, n<<1|1, m, nr);
      return r;
    }
  }
  ll qry(int gl, int gr, int t) {return qry(gl, gr, t, 1, 0, s);}
};
ST<> st;

struct R {
public:
  int l, r, c;
  bool operator < (const R& o) const {return r < o.r;}
  ll operator () (const int& a, const int& b, const int& t) const {
    return st.qry(a, b, t - c);
  }
  ll operator () (const int& t) const {
    return st.qry(l, r, t - c);
  }
};
typedef set<R> sr;
typedef set<R>::iterator sri;

sr x;

R o;
typedef queue<R> qr;
qr I;

void solve() {
  int t, l, r;
  scanf("%d%d%d", &t, &l, &r);
  l--;
  
  int y = l;
  sri it = x.upper_bound({0, l, 0});
  
  ll a = 0LL;
  //for(const auto & q : x) cerr << q.l << " " << q.r << " " << q.c << "\n";
  
  while(it != x.end() and r > it->l) {
    o = *it;
    it = x.erase(it);
  
    if(y < o.l)
      a += brute(y, o.l, t), y = o.l;
    if(o.l < l)
      I.push({o.l, l, o.c});
    if(r <= o.r) {
      a += o(y, r, t);
      if(r < o.r) I.push({r, o.r, o.c});
      y = r;
      break;
    }
    a += o(y, o.r, t);
    y = o.r;
  }
  if(y < r) a += brute(y, r, t);
  x.insert({l, r, t});
  while(not I.empty()) x.insert(I.front()), I.pop();
  
  printf("%lld\n", a);
}

int main() {
  scanf("%d", &N);
  
  for(int i = 0, a, b, c;i < N;i++) {
    scanf("%d%d%d", &a, &b, &c);
    p[i] = P(a, b, c);
    p[i].upd();
  }
  
  st.init(N);
  
  I = qr();
  scanf("%d", &Q);
  while(Q--) solve();
  
  return 0;
}