#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1e9 + 7;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int sum(int a, int b) {return ti((tl(a) + tl(b))%MOD);}
int add(int& a, int b) {return a = sum(a, b);}
int dif(int a, int b) {return ti((tl(a) - tl(b) + 100LL * MOD)%MOD);}
int sub(int& a, int b) {return a = dif(a, b);}
int prd(int a, int b) {return ti((tl(a) * tl(b))%MOD);}
int mul(int& a, int b) {return a = prd(a, b);}
int pw(int b, int p) {
  int r = 1;
  for(;p;p>>=1,b=prd(b, b)) if(p&1) r=prd(r, b);
  return r;
}
int inv(int a) {return pw(a, MOD - 2);}
int dv(int n, int d) {return prd(n, inv(d));}

ll N;
int K;

const int NL2 = 60;
int D[NL2 + 12];
void pcpd() {
  D[0] = 0;
  for(int i = 1;i < NL2 + 11;i++) D[i] = inv(i);
}

int p[NL2][NL2];
void pcpp() {
  pcpd();
  p[1][1] = 1;
  for(int i = 2;i < NL2;i++) {
    for(int j = 0;j < NL2;j++) p[i][j] = 0;
    p[i][i] = 1;
    for(int k = 0;k < K;k++) {
      int s = 0;
      for(int j = i, k;j > 0;j--) {
        k = prd(p[i][j], D[j]);
        int t = s;
        add(s, k);
        p[i][j] = k;
        add(p[i][j], t);
      }
    }
  }
}

int fact(ll n) {
  int r = 1;
  for(ll i = 2;i*i <= n;i++) {
    if(n%i == 0) {
      int c = 1;
      while(n%i == 0) {
        c++;
        n/=i;
      }
      
      int v = 0;
      int x = 1;
      for(int k = 1;k <= c;k++) {
        add(v, prd(x, p[c][k]));
        mul(x, ti(i%MOD));
      }
      mul(r, v);
    }
  }
  
  if(n > 1) {
    mul(r, sum(p[2][1], prd(p[2][2], ti(n%MOD))));
  }
  return r;
}

int main() {
  scanf("%lld%d", &N, &K);
  
  pcpp();
  
  printf("%d\n", fact(N));
  
  return 0;
}