#include <iostream>
#include <cstdio>

#include <bitset>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

inline int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
inline int dif(int a, int b) {return ti((tll(a) - tll(b) + 100LL * MOD)%MOD);}
inline int prd(int a, int b) {return ti((tll(a) * tll(b))%MOD);}
int pw(int b, int p) {
  int r = 1;
  for(;p;b=prd(b, b),p>>=1) if(p&1) r = prd(r, b);
  return r;
}

const int MAXN = 3e5 + 100;

int D[MAXN];
int dvO(int n, int d) {return prd(n, pw(d, MOD - 2));}
int dv(int n, int d) {
  if(d < MAXN) return prd(n, D[d]);
  return dvO(n, d);
}

int F[2][MAXN];
inline int C(int n, int k) {return prd(F[0][n], prd(F[1][k], F[1][n-k]));}

void pcpM() {
  for(int i = 1;i < MAXN;i++) D[i] = dvO(1, i);
  F[0][0] = F[1][0] = 1;
  for(int i = 1;i < MAXN;i++) F[0][i] = prd(F[0][i-1], i), F[1][i] = prd(F[1][i-1], D[i]);
}
int N;
int G[MAXN];
void pcpM2() {
  G[0] = 0;
  for(int i = 0;i <= N - 1;i++) G[i + 1] = sum(G[i], C(N-1, i));
}

const int MAXP = 3e4 + 100;   //~26000
const int MAXV = 3e5 + 100;
typedef bitset<MAXV> vb;

int P[MAXP], Ps;
vb T;
int Q[MAXV], A[MAXV], S[MAXV];

void pcpP() {
  Ps = 0;
  T.set();
  for(int i = 2;i < MAXV;i++) {
    if(T[i]) {
      S[i] = Ps, A[i] = 1, Q[i] = 1;
      P[Ps++] = i;
    }
    for(int j = 0, q;j < Ps and i * P[j] < MAXV;j++) {
      q = i*P[j];
      T[q] = false, S[q] = j;
      if(S[q] == S[i]) Q[q] = Q[i] + 1, A[q] = A[i]; else Q[q] = 1, A[q] = i;
      if(i%P[j] == 0) break;
    }
  }
}

typedef vector<int> vi;
#define pb push_back
vi c[MAXP];
void fill(int n) {
  if(n == 1) return;
  c[S[n]].pb(Q[n]);
  fill(A[n]);
}

int f;
void solve(int i) {
  vi& t = c[i];
  if(t.empty()) return;
  sort(t.begin(), t.end(), greater<int>());
  int d = 0;
  for(int l = 0, r;l < t.size();l++) {
    r = N - l - 1;
    if(l < r) d = sum(d, prd(t[l], dif(G[r], G[l])));
    if(r < l) d = dif(d, prd(t[l], dif(G[l], G[r])));
  }
  f = sum(f, d);
}

int main() {
  
  pcpM();
  pcpP();
  
  scanf("%d", &N);
  pcpM2();
  
  for(int i = 0, t;i < N;i++) scanf("%d", &t), fill(t);
  f = 0;
  for(int i = 0;i < Ps;i++) solve(i);
  
  printf("%d\n", f);
  
  return 0;
}