#include <iostream>
#include <cstdio>

#include <vector>
#include <stack>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
using vi = vector<int>;
#define pb push_back
#define pf push_front
#define emp empty()

template<class T> bool mn(T& a, const T& b) {return b < a ? a = b, 1 : 0;}

const int MN = 2.5e5 + 100;
const ll INF = 2e18;

struct BLK {
public:
  int k;
  vi a, c;
  BLK() {
    a.clear(), c.clear();
  }
  void in() {
    scanf("%d", &k);
    a.assign(k, 0);
    for(int& x : a) scanf("%d", &x);
    c.assign(k, 0);
    for(int& x : c) scanf("%d", &x);
  }
};
BLK b[MN];
int N, M, Q;

const int MM = 1e7 + 100;
int a[MM];
ll c[MM];
using si = stack<int>;
#define sz size()
#define tp top()
si s;
struct X {
public:
  int a;
  ll c;
};
using sx = stack<X>;
int v[2][MM];
void solve0() {
  s = si();
  int * d = v[0];
  d[0] = 0LL;
  s.push(0);
  for(int i = 0;i < M;i++) {
    while(s.sz > 1&&s.tp > i-a[i]+1) s.pop();
    d[i+1] = s.tp;
    s.push(i+1);
  }
}
void solve1() {
  s = si();
  int * d = v[1];
  d[M] = 0LL;
  s.push(M);
  for(int i = M-1;i >= 0;i--) {
    for(;s.sz>1&&s.tp < i+a[i];) s.pop();
    d[i] = s.tp;
    s.push(i);
  }
}
ll d[MM];
sx q;
void addq(const X& x) {
  for(;!q.emp&&q.tp.c >= x.c;)
    q.pop();
  q.push(x);
}
ll nexq(int x) {
  ll c = INF;
  for(;!q.emp&&x <= q.tp.a;q.pop())
    c = q.tp.c;
  if(c < INF) q.push({x, c});
  return c;
}
void solve() {
  q = sx();
  d[0] = 0LL;
  for(int i = 0;i < M;i++) {
    addq({i, d[i]});
    mn(d[v[1][i]], d[i] + c[i]);
    mn(d[i+1], nexq(v[0][i+1]) + c[i]);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 1;i <= N;i++)
    b[i].in();
  scanf("%d", &Q);
  for(int k = 0, i = 0, j, d, m;k < Q;k++) {
    scanf("%d%d", &d, &m);
    for(j = 0;j < b[d].k;j++, i++)
      a[i] = b[d].a[j], c[i] = tl(b[d].c[j])*m;
  }
  solve0();
  solve1();
  for(int i = 0;i <= M;i++) d[i] = INF;
  solve();
  printf("%lld\n", d[M]);
  return 0;
}