#include <iostream>
#include <cstdio>

#include <array>
#include <vector>
#include <stack>

using namespace std;

const int MN = 1.2e5 + 1000;
const int MQ = 1.2e5 + 1000;

using ll = long long;

template<int MS = MN << 2> struct ST {
public:
  int v[MS], z[MS], c[MS], k[MS];
  ll f[MS];
  int s;
  void up(int n) {
    if(v[n<<1] < v[n<<1|1]) v[n] = v[n<<1], c[n] = c[n<<1];
    if(v[n<<1] > v[n<<1|1]) v[n] = v[n<<1|1], c[n] = c[n<<1|1];
    if(v[n<<1] == v[n<<1|1]) v[n] = v[n<<1], c[n] = c[n<<1]+c[n<<1|1];
    f[n] = f[n<<1] + f[n<<1|1];
  }
  void init(int n, int l, int r) {
    if(r - l == 1) f[n] = 0LL, v[n] = l, z[n] = 0, c[n] = 1, k[n] = 0;
    else {
      int m = l + ((r-l)>>1);
      init(n<<1, l, m), init(n<<1|1, m, r);
      up(n);
    }
  }
  void init(int q) {
    init(1, 0, s = q);
  }
  void fix0(int n, int d) {
    v[n] += d, z[n] += d;
  }
  void fix1(int n, int d) {
    k[n] += d, f[n] += 1LL*d*c[n];
  }
  void down(int n, int l, int r) {
    if(z[n]) {
      if(r - l > 1) fix0(n<<1, z[n]), fix0(n<<1|1, z[n]);
      z[n] = 0;
    }
    if(k[n]) {
      if(r - l > 1) {
        if(v[n<<1] == v[n]) fix1(n<<1, k[n]);
        if(v[n<<1|1] == v[n]) fix1(n<<1|1, k[n]);
      }
      k[n] = 0;
    }
  }
  void upd(int n, int l, int r, int gl, int gr, int x) {
    if(gl <= l and r <= gr) {
      fix0(n, x);
    } else {
      int m = l + ((r-l)>>1);
      down(n, l, r);
      if(gl < m) upd(n<<1, l, m, gl, gr, x); else down(n<<1, l, m);
      if(m < gr) upd(n<<1|1, m, r, gl, gr, x); else down(n<<1|1, m, r);
      up(n);
    }
  }
  void upd(int gl, int gr, int x) {upd(1, 0, s, gl, gr, x);}
  ll qry(int n, int l, int r, int gl, int gr) {
    down(n, l, r);
    if(gl <= l and r <= gr) return f[n];
    int m = l + ((r-l)>>1);
    ll w = 0LL;
    if(gl < m) w += qry(n<<1, l, m, gl, gr);
    if(m < gr) w += qry(n<<1|1, m, r, gl, gr);
    return w;
  }
  ll qry(int gl, int gr) {return qry(1, 0, s, gl, gr);}
  void count() {fix1(1, 1);}
};
ST<> st;

using i2 = array<int, 2>;
using vi2 = vector<i2>;
#define pb push_back
using si = stack<int>;

vi2 q[MN];
ll f[MQ];
int N, Q, a[MN];

int main() {
  scanf("%d", &N);
  for(int i = 0;i < N;i++) scanf("%d", a + i);
  scanf("%d", &Q);
  for(int i = 0, l, r;i < Q;i++) scanf("%d%d", &l, &r), q[--r].pb({--l, i});
  
  st.init(N + 5);
  
  si b, t;
  b.push(-1), t.push(-1);
  for(int i = 0, x;i < N;i++) {
    st.upd(0, N + 5, -1);
    while(b.size() > 1 and a[x = b.top()] > a[i]) b.pop(), st.upd(b.top()+1, x+1, a[x]-a[i]); b.push(i);
    while(t.size() > 1 and a[x = t.top()] < a[i]) t.pop(), st.upd(t.top()+1, x+1, a[i]-a[x]); t.push(i);
    st.count();
    for(i2 y : q[i]) f[y[1]] = st.qry(y[0], i+1);
  }
  
  for(int i = 0;i < Q;i++) printf("%lld\n", f[i]);
  
  return 0;
}