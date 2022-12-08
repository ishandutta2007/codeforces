#include <iostream>
#include <cstdio>

#include <array>
#include <deque>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const ll INF = 1e18;
ll divf(ll n, ll d)
{
  if(d < 0) n*=-1, d*=-1;
  if(n < 0) return -((-n+d-1)/d);
  return n/d;
}
using i2 = array<ll, 2>;
struct L
{
public:
  ll i;
  ll m, b;
  mutable ll r;
  L(ll i, ll m, ll b, ll r = -1LL) : i(i), m(m), b(b), r(r) {}
  ll operator * (const L& o) const
  {
    if(o.m == m) return o.b < b ? -INF : INF;
    return divf(o.b - b - 1, m - o.m);
  }
  i2 operator [] (const ll& x) {return {i, m * x + b};}
};
#define IT iterator
struct H : public deque<L>
{
public:
  bool upd(const L& l, IT n)
  {
    if(n == end()) return l.r = INF, 0;
    if((l.r = l**n) >= n->r) return 1;
    return 0;
  }
  void ins(const L& l)
  {
    for(;upd(l, begin());) pop_front();
    push_front(l);
  }
  i2 operator [] (const ll& x)
  {
    for(;x > front().r;pop_front());
    return front()[x];
  }
} T;

ll l;
ll b, s;
int B, S;
int M;
int k;

void q1(void)
{
  T.clear();
  scanf("%d", &k);
  l += k;
  b = s = 0LL;
  T.ins({0LL, 0LL, 0LL});
}
void q2(void)
{
  scanf("%d", &k);
  T.ins({l, l, -s*l-b});
  l += k;
}
void q3(void)
{
  scanf("%d%d", &B, &S);
  b += B, s += S;
}
void ans(const i2& x) {printf("%lld %lld\n", 1+x[0], x[1] + b);}
int main(void)
{
  scanf("%lld%d", &l, &M);
  T.ins({0LL, 0LL, 0LL});
  for(int i = 0, q;i < M;i++)
  {
    scanf("%d", &q);
    if(q==1) q1();
    if(q==2) q2();
    if(q==3) q3();
    ans(T[s]);
  }
  return 0;
}