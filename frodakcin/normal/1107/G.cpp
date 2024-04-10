#include <iostream>
#include <cstdio>

#include <array>
#include <stack>

using namespace std;

template<class T> void mx(T& a, const T& b) {if(a < b) a = b;}
template<class T> void mn(T& a, const T& b) {if(b < a) a = b;}

const int MN = 3e5 + 1000;

using ll = long long;
#define tl(X) static_cast<ll>(X)

using l4 = array<ll, 4>;

l4 operator + (const l4& a, const l4& b) {
  return {
    max(max(a[0], b[0]), a[1]+b[2]),
    max(b[1], a[1]+b[3]),
    max(a[2], a[3]+b[2]),
    a[3] + b[3]
  };
}
const l4 Z = {0, 0, 0, 0};

int c[MN], a, t, m;
template<int MS = MN << 3> struct ST {
public:
  l4 v[MS];
  int s;
  void up(int n) {
    v[n] = v[n<<1] + v[n<<1|1];
  }
  void init(int n, int l, int r) {
    if(r - l > 1) {
      int m = l + ((r-l)>>1);
      init(n<<1, l, m), init(n<<1|1, m, r);
      up(n);
    } else v[n] = {t = max(a-c[l], 0), t, t, a-c[l]};
  }
  void init(int S) {
    s = S;
    init(1, 0, s);
  }
  l4 qry(int n, int l, int r, int gl, int gr) {
    if(gl <= l and r <= gr) return v[n];
    int m = l + ((r-l)>>1);
    l4 v = Z;
    if(gl < m) v = v + qry(n<<1, l, m, gl, gr);
    if(m < gr) v = v + qry(n<<1|1, m, r, gl, gr);
    return v;
  }
  ll qry(int gl, int gr) {return qry(1, 0, s, gl, gr)[0];}
};
ST<> st;

int N;
int d[MN], L[MN], R[MN];
using i2 = array<int, 2>;
using si2 = stack<i2>;
void clr(si2& s) {while(not s.empty()) s.pop();}

const int INF = 2e9;

si2 s;
void pcplr() {
  clr(s);
  s.push({0, INF});
  for(int i = 0;i < N-1;i++) {
    while(d[i+1] - d[i] >= s.top()[1]) s.pop();
    L[i] = s.top()[0];
    s.push({i+1, d[i+1]-d[i]});
  }
  clr(s);
  s.push({N, INF});
  for(int i = N-2;i >= 0;i--) {
    while(d[i+1] - d[i] >= s.top()[1]) s.pop();
    R[i] = s.top()[0];
    s.push({i+1, d[i+1]-d[i]});
  }
}

int main() {
  scanf("%d%d", &N, &a);
  m = INF;
  for(int i = 0;i < N;i++) scanf("%d%d", d + i, c + i), mn(m, c[i]);
  st.init(N);
  
  pcplr();
  
  ll f = 0;
  mx(f, 1LL*a - m);
  for(int i = 0;i < N-1;i++) mx(f, st.qry(L[i], R[i]) - 1LL*(d[i+1]-d[i])*(d[i+1]-d[i]));
  printf("%lld\n", f);
  
  return 0;
}