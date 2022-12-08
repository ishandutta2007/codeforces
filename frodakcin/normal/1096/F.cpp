#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MN = 2e5 + 10000;
const int MOD = 998244353;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
int dif(int a, int b) {return ti((tll(a) - tll(b) + 100LL*MOD)%MOD);}
int prd(int a, int b) {return ti((tll(a) * tll(b))%MOD);}
int pw(int b, int p) {
  int r = 1;
  for(;p;p>>=1,b=prd(b, b)) if(p&1) r = prd(r, b);
  return r;
}
int inv(int a) {return pw(a, MOD - 2);}
int dv(int n, int d) {return prd(n, inv(d));}
int FT[MN << 1];

int ways(int t, int o) {
  return prd(t, FT[t + o - 1]);
}

template<int MS = MN> struct BIT {
public:
  int v[MS];
  int s;
  void init(int z) {
    s = z;
    for(int i = 0;i <= s;i++) v[i] = 0;
  }
  void upd(int p, int d) {
    for(;p <= s;p += p&(p^(p-1))) v[p] += d;
  }
  int qry(int p) {
    int r = 0;
    for(;p;p &= (~p^(p-1))) r += v[p];
    return r;
  }
};
BIT<> bit;

int N;
int cinv(int * a, int s) {
  bit.init(N + 10);
  int r = 0;
  for(int i = 0;i < s;i++) {
    r = sum(r, bit.qry(N + 1 - a[i]));
    bit.upd(N + 1 - a[i], 1);
  }
  return r;
}

int F, E;
int p[MN], f[MN];
bool u[MN];
int c[MN];

int l, r;

int main() {
  FT[0] = 1;
  for(int i = 1;i < MN<<1;i++) FT[i] = prd(FT[i-1], i);
  
  scanf("%d", &N);
  F = E = 0;
  for(int i = 1;i <= N;i++) u[i] = false;
  for(int i = 0;i < N;i++) {
    scanf("%d", p + i);
    if(p[i] == -1) E++; else u[f[F++] = p[i]] = true;
  }
  c[0] = 0;
  for(int i = 1;i <= N;i++) c[i] = c[i - 1] + not(u[i]);
  
  int z = 0;
  
  l = r = 0;
  for(int i = 0;i < F;i++) r = sum(r, prd(E, c[i]));
  
  for(int i = 0, j = 0;i < N;i++) {
    if(p[i] == -1) j++;
    else {
      int b = c[p[i]], t = E - b, k = E - j;
      z = sum(z, sum(prd(t, ways(j, k)), prd(b, ways(k, j))));
    }
  }
  
  z = dv(z, FT[E]);
  z = sum(z, dv(prd(E, E - 1), 4));
  z = sum(z, cinv(f, F));
  
  printf("%d\n", z);
  
  return 0;
}