#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 998244353;

using ll = long long;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
int add(int& a, int b) {return a = sum(a, b);}
int dif(int a, int b) {return ti((tll(a) - tll(b) + 100LL * MOD)%MOD);}
int sub(int& a, int b) {return a = dif(a, b);}
int prd(int a, int b) {return ti((tll(a) * tll(b))%MOD);}
int pw(int b, int p) {
  int r = 1;
  for(;p;p>>=1,b=prd(b, b)) if(p&1) r=prd(r, b);
  return r;
}
int inv(int a) {return pw(a, MOD - 2);}

const int MV = 1e6;
int D[MV];
int F[2][MV];
void pcpm() {
  D[0] = 0, D[1] = 1;
  for(int i = 2;i < MV;i++) D[i] = inv(i);
  F[0][0] = F[1][0] = 1;
  for(int i = 1;i < MV;i++) F[0][i] = prd(F[0][i-1], i), F[1][i] = prd(F[1][i-1], D[i]);
}
int dv(int n, int d) {if(d < MV) return prd(n, D[d]); else return prd(n, inv(d));}
int C(int n, int k) {
  if(n < 0 or k < 0 or n < k) return 0;
  return prd(F[0][n], prd(F[1][k], F[1][n-k]));
}

int dstr(int p, int t, int m) {
  if((t == 0 and m > 0) or (p == 0 and t == 0)) return 1;         //Not sure how to deal with this
  if(t < 0) return 0;
  
  int r = 0;
  for(int i = 0;i <= p and i*m <= t;i++) {
    int k = t - i*m;
    int d = prd(C(p, i), C(k + p - 1, p - 1));
    if(i&1) sub(r, d); else add(r, d);
  }
  //cerr << p << " " << t << " " << m << " " << r << "\n";
  return r;
}

const int MP = 100 + 10;
const int MS = 5e3 + 100;

int P, R, S;

int main() {
  pcpm();
  
  scanf("%d%d%d", &P, &S, &R);
  
  if(P == 1) {
    printf("1\n");
    return 0;
  }
  
  int w, t;
  
  w = 0;
  for(int r = R;r <= S;r++)
    for(int o = 0;o < P;o++)
      add(w, dv(prd(C(P-1, o), dstr(P - 1 - o, S - r*(o+1), r)), o + 1));
  
  t = 0;
  for(int r = R;r <= S;r++) add(t, C(S - r + P - 2, P - 2));
  
  printf("%d\n", dv(w, t));
  
  return 0;
}