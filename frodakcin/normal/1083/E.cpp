#include <iostream>
#include <cstdio>

#include <deque>
#include <algorithm>

#include <cassert>

using namespace std;

typedef long long ll;
#define tll(X) static_cast<ll>(X)

ll divf(ll n, ll d) {
  assert(d);
  if(d < 0) d *= -1LL, n *= -1LL;
  if(n < 0) return -((-n + d - 1)/d);
  else return n/d;
}

const ll INF = 1e18 + 1e10;

struct LINE {
public:
  ll m, b;
  LINE (const ll& m, const ll& b) : m(m), b(b) {}
  mutable ll r;
  ll operator [] (const ll& x) const {return m * x + b;}
  ll operator * (const LINE& o) const {
    if(m == o.m) return b > o.b ? -INF : INF;
    return divf(o.b-b, m-o.m);
  }
};

#define IT iterator

struct MCHT : deque<LINE> {
public:
  bool upd(LINE& c, IT n) {
    if(n == end()) {c.r = INF; return false;}
    if((c.r = c**n) < n->r) return false;
    return true;
  }
  void ins(LINE l) {
    while(upd(l, begin())) pop_front();
    push_front(l);
  }
  ll qry(ll x) {
    assert(not empty());
    LINE l = back();
    pop_back();
    while(not empty() and not(back().r < x)) l = back(), pop_back();
    push_back(l);
    return l[x];
  }
} cht;

const int MAXN = 1e6 + 100;

int N;
void rph(ll& a, const ll& b) {if(a < b) a = b;}
ll a, d;

struct RECT {
public:
  int x, y;
  ll a, c;
  void upd() {c =  tll(x) * tll(y) - a;}
  RECT(int x = -1, int y = -1, ll a = 0LL) : x(x), y(y), a(a) {upd();}
  bool operator < (const RECT& o) const {return x < o.x;}
} R[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0;i < N;i++) scanf("%d%d%lld", &R[i].x, &R[i].y, &R[i].a), R[i].upd();
  sort(R, R + N);
  
  a = 0LL;
  cht.ins(LINE(0LL, 0LL));
  
  for(int i = 0;i < N;i++) {
    d = cht.qry(R[i].y) + R[i].c;
    rph(a, d);
    cht.ins(LINE(-R[i].x, d));
    //cerr << i << " " << d << "\n";
  }
  
  printf("%lld\n", a);
  
  return 0;
}