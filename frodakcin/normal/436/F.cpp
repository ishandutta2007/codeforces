#include <iostream>
#include <cstdio>

#include <deque>
#include <array>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 100;
const int PV = 500;

typedef long long ll;
#define tll(X) static_cast<ll>(X)

const ll MAXX = 1e5 + 100;
const ll INF = 1e9 + 100;

typedef pair<ll, int> pli;
#define ff first
#define ss second

ll divf(ll n, ll d) {
  if(d < 0) n *= -1, d *= -1;
  if(n < 0) return -((-n + d - 1)/d);
  return n/d;
}
struct LINE {
public:
  ll m, b;
  mutable ll r;
  int i;
  ll operator * (const LINE& o) const {
    if(m == o.m) return o.b > b ? -INF : INF;
    return divf(o.b - b, m - o.m);
  }
  pli operator [] (const ll& x) const {return {m * x + b, i};}
};

#define IT iterator
struct CHT : deque<LINE> {
public:
  bool upd(const LINE& c, const LINE& n) {
    if((c.r = c*n) < n.r and c.r < MAXX) return false;
    return true;
  }
  void ins(LINE l) {
    l.r = INF;
    LINE c;
    while(not empty()) {
      c = back(); pop_back();
      upd(c, l);
      if((empty() and not(c.r < 0)) or (not empty() and back().r < c.r)) {push_back(c); break;}
    }
    push_back(l);
  }
  pli operator [] (const ll& x) {
    while(front().r < x) pop_front();
    return front()[x];
  }
} cht[PV + 10];

int N, W, A, B;

typedef array<int, 2> ai2;
#define av at(0)
#define bv at(1)
;
array<int, 2> u[MAXN];
ll d[MAXN];
int o[MAXN], c;

template<class T> inline void rph(T& a, const T& b) {if(a < b) a = b;}

int a[MAXN], as;
array<int, 2> q[MAXN * 2];
int C;

void work(int l, int r) {
  as = 0;
  a[as++] = A;
  for(int i = l;i < r;i++) if(q[i][0] == 1) a[as++] = q[i][1];
  sort(a, a + as);
  as = unique(a, a + as) - a;
  
  for(int i = 0;i < as;i++) cht[i].clear(), o[i] = 0;
  for(int i = 0, j = 0;i <= A;i++) {
    if(j < as and i > a[j]) j++;
    cht[j].ins({i, d[i], -1, i});
  }
  
  for(int i = l;i < r;i++) {
    if(q[i][0] == 1) {
      int l = lower_bound(a, a + as, q[i][1]) - a;
      for(int j = 0;j <= l;j++) o[j]++;
    } else {
      pli f(0LL, 0);
      for(int j = 0;j < as;j++) rph(f, cht[j][o[j]]);
      printf("%lld %d\n", f.ff + tll(W) * (N - q[i][1]) * (c++), f.ss);
    }
  }
  
  for(int i = A, j = as - 1, t = 0;i >= 0;i--) {
    if(j >= 0 and i <= a[j]) t = o[j--];
    d[i] += tll(i) * t;
  }
}

int main() {
  scanf("%d%d", &N, &W);
  
  A = B = 0;
  for(int i = 0, a, b;i < N;i++) scanf("%d%d", &a, &b), u[i] = {a, b}, rph(B, b), rph(A, a);
  A++;
  
  for(int i = 0;i <= A;i++) d[i] = 0LL;
  
  sort(u, u + N, [](const ai2& a, const ai2& b){return a.bv < b.bv or (not(b.bv < a.bv) and a.av < b.av);});
  
  C = 0;
  int i = 0;
  for(c = 0;c <= B + 1;c++) {
    for(;i < N and u[i].bv < c;i++) q[C++] = {1, u[i].av};
    q[C++] = {2, i};
  }
  c = 0;
  
  for(i = PV;i < C;i += PV) work(i - PV, i);
  if(i - PV < C) work(i - PV, C);
  
  return 0;
}