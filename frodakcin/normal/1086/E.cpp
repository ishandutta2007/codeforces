#include <iostream>
#include <cstdio>

#include <set>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e3 + 100;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
int dif(int a, int b) {return ti((tll(a) - tll(b) + 100LL * MOD)%MOD);}
int prd(int a, int b) {return ti((tll(a) * tll(b))%MOD);}
int pw(int b, int p) {
  int r = 1;
  for(;p;p>>=1, b=prd(b, b)) if(p&1) r = prd(r, b);
  return r;
}
int dvO(int n, int d) {return prd(n, pw(d, MOD - 2));}

int D[MAXN];

int dv(int n, int d) {
  if(d < MAXN) return prd(n, D[n]);
  return dvO(n, d);
}

int N;

int a[MAXN][MAXN];
int F[2][MAXN];
int C(int t, int b) {return prd(F[0][t], prd(F[1][b], F[1][t-b]));}

void pcpM() {
  for(int i = 1;i < MAXN;i++) D[i] = dvO(1, i);
  F[0][0] = F[1][0] = 1;
  for(int i = 1;i < MAXN;i++) F[0][i] = prd(F[0][i-1], i), F[1][i] = prd(F[1][i-1], D[i]);
}

int dp[MAXN][MAXN];

typedef set<int> si;
template<int MAXS = MAXN> struct BIT {
public:
  int v[MAXS];
  int s;
  void init(int z, int q = 0) {
    s = z;
    for(int i = 0;i <= s;i++) v[i] = (i&(i^(i-1)))*q;
  }
  void upd(int q, int d) {
    for(;q <= s;q += q&(q^(q-1))) v[q] += d;
  }
  int qry(int q) {
    int r = 0;
    for(;q > 0;q &= ~(q^(q-1))) r += v[q];
    return r;
  }
};

BIT<> c[2];
si u;
int p[MAXN];

void wk(int x) {
  if(u.empty() or *u.lower_bound(x) != x) u.insert(x); else u.erase(x);
}
int compute(int * t, int * b) {
  int r = 0, o = 0;
  u.clear(); c[0].init(N, 0), c[1].init(N, 1); for(int i = 0;i <= N;i++) p[i] = 1;
  for(int i = 0;i < N;i++) {
    wk(t[i]); 
    c[p[b[i]]].upd(b[i], -1);p[b[i]] = 2;
    if(p[t[i]] == 1) p[t[i]] = 0, c[0].upd(t[i], 1), c[1].upd(t[i], -1);
    
    int k = (N - i - 1) - (static_cast<int>(u.size())>>1);
    if(k >= 0) r = sum(r, prd(c[0].qry(b[i] - 1) - (p[t[i]] == 0 and b[i] > t[i]), dp[N-i-1][k]));
    if(k > 0) r = sum(r, prd(c[1].qry(b[i] - 1) - (p[t[i]] == 1 and b[i] > t[i]), dp[N-i-1][k-1]));
    
    wk(b[i]);
  }
  return r;
}

int main() {
  
  pcpM();
  
  scanf("%d", &N);
  if(N == 1) {printf("0\n"); return 0;}
  
  for(int i = 0;i <= N;i++) dp[i][0] = F[0][i], dp[0][i] = 1;
  for(int i = 1;i <= N;i++) for(int j = 1;j <= i;j++)
    dp[i][j] = dif(dp[i][j-1], dp[i-1][j-1]);
  
  for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) scanf("%d", a[i] + j);
  int z = 1, f = 0;
  for(int i = N - 2;i >= 0;i--) {
    f = sum(f, prd(z, compute(a[i], a[i + 1])));
    //cerr << f << "\n";
    z = prd(z, dp[N][N]);
  }
  int g = 0;
  BIT<> h;
  h.init(N, 1);
  for(int i = 0;i < N;i++) {
    h.upd(a[0][i], -1);
    g = sum(g, prd(h.qry(a[0][i] - 1), F[0][N - i - 1]));
  }
  f = sum(f, prd(z, g));
  
  printf("%d\n", f);
  
  return 0;
}