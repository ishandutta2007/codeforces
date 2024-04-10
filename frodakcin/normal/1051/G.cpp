#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

const int MAXN = 2e5 + 100;
const int MAXS = MAXN * 20;

ll ans;
int N;

struct STC {
public:
  int c[MAXS][2], v1[MAXS];
  ll v2[MAXS];
  int NXT;
  STC() : NXT(1) {v2[0] = v1[0] = 0, c[0][0] = c[0][1] = 0;}
  int nn() {
    for(int i = 0;i < 2;i++) c[NXT][i] = 0;
    v1[NXT] = 0;
    v2[NXT] = 0LL;
    return NXT++;
  }
  
  void ins(int b, int& n, int nl = 1, int nr = N + 1) {
    if(n == 0) n = nn();
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      if(b < m) ans += tll(b)*v1[c[n][1]], ins(b, c[n][0], nl, m);
      else ans += v2[c[n][0]], ins(b, c[n][1], m, nr);
    }
    else if(nr - nl == 1) assert(nl == b);
    else assert(false);
    v1[n]++;
    v2[n]+=tll(b);
  }
  void mrg(int& n1, int n2, int nl = 1, int nr = N + 1) {
    if(n1 == 0) {
      n1 = n2;
      return;
    }
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      ans += v2[c[n1][0]] * v1[c[n2][1]] + v2[c[n2][0]] * v1[c[n1][1]];
      if(c[n2][0]) mrg(c[n1][0], c[n2][0], nl, m);
      if(c[n2][1]) mrg(c[n1][1], c[n2][1], m, nr);
    } else if (nr - nl == 1);
    else assert(false);
    v1[n1] += v1[n2];
    v2[n1] += v2[n2];
  }
} stc;

int dsup[MAXN], dsus[MAXN], l[MAXN], r[MAXN], h[MAXN];
void dsui(const int& n) {
  for(int i = 0;i <= n;i++) dsup[i] = i, dsus[i] = 0;
}
int dsuf(const int& n) {
  if(dsup[n] == n) return n;
  else return dsup[n] = dsuf(dsup[n]);
}
bool dsum(int a, int b, bool f = false) {
  if(f) assert(r[a] == l[b]);
  a = dsuf(a), b = dsuf(b);
  if(a == b) return false;
  if(dsus[a] < dsus[b]) swap(a, b);
  dsup[b] = a, dsus[a] += dsus[b], dsus[b] = 0;
  
  if(!f) return true;
  if(l[a] < l[b]) ans -= stc.v2[h[b]]*(l[b] - l[a]);
  if(l[b] < l[a]) ans -= stc.v2[h[a]]*(l[a] - l[b]);
  stc.mrg(h[a], h[b]);
  if(l[b] < l[a]) l[a] = l[b];
  if(r[a] < r[b]) r[a] = r[b];
  return true;
}
void solve(int a, int b) {
  ans -= tll(a)*b;
  
  int d = dsuf(a);
  if(dsus[d] == 0) l[d] = r[d] = a, h[d] = 0;
  r[d]++, dsus[d]++;
  
  ans += tll(b)*l[d];
  stc.ins(b, h[d]);
  if(r[d] < MAXN) {
    int t = dsuf(r[d]);
    dsum(d, t, dsus[t] > 0);
  }
}

int main() {
  scanf("%d", &N);
  dsui(MAXN);
  ans = 0;
  
  for(int i = 0, a, b;i < N;i++) {
    scanf("%d%d", &a, &b);
    solve(a, b);
    printf("%lld\n", ans);
  }
  
  return 0;
}