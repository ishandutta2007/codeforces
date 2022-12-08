#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

const int MAXQ = 3e5 + 100;
const int MAXT = 1e6 + 100;
const int MAXS = MAXT * 5;

struct ST {
  ll v[MAXS], v2[MAXS];
  void res(int n) {
    v[n] = v[n<<1] + v[n<<1|1];
    v2[n] = max(v2[n<<1|1], v2[n<<1] + v[n<<1|1]);
  }
  void res(ll& vn, ll& v2n, int n) {
    vn += v[n];
    v2n = max(v2[n], v2n + v[n]);
  }
  void init(int n, int nl, int nr) {
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      init(n<<1, nl, m);
      init(n<<1|1, m, nr);
      res(n);
    } else {
      v[n] = 0LL, v2[n] = tll(nl);
    }
  }
  void init() {init(1, 0, MAXT);}
  
  void upd(int g, int q, int n, int nl, int nr) {
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      if(g < m) upd(g, q, n<<1, nl, m);
      else upd(g, q, n<<1|1, m, nr);
      res(n);
    } else {
      v[n] += tll(q), v2[n] += tll(q);
    }
  }
  void upd(int g, int q) {upd(g, q, 1, 0, MAXT);}
  
  void qry(ll& vf, ll& v2f, int n, int nl, int nr, int gr) {
    if(gr < nr) {
      int m = nl + ((nr - nl)>>1);
      qry(vf, v2f, n<<1, nl, m, gr);
      if(m < gr) qry(vf, v2f, n<<1|1, m, nr, gr);
    } else {
      res(vf, v2f, n);
    }
  }
  void qry(ll& vf, ll& v2f, int rb) {vf = v2f = 0LL; qry(vf, v2f, 1, 0, MAXT, rb);}
} st;

int Q;
char o;
int t[MAXQ], d[MAXQ];
ll a[2];

int main() {
  st.init();
  scanf("%d", &Q);
  for(int i = 1;i <= Q;i++) {
    scanf(" %c%d", &o, t + i);
    if(o == '+') {
      scanf("%d", d + i);
      st.upd(t[i], d[i]);
    } else if(o == '-') {
      st.upd(t[t[i]], -d[t[i]]);
    } else {
      st.qry(a[0], a[1], t[i] + 1);
      printf("%lld\n", a[1] - tll(t[i]));
    }
  }
  return 0;
}