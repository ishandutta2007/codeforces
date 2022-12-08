#include <iostream>
#include <cstdio>

#include <bitset>
#include <cassert>

using namespace std;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MAXN = 1e5 + 100;

int N, K, Q;

int sum(int a, int b) {return ti((tll(a) + tll(b))%Q);}
int dif(int a, int b) {return ti((tll(a) - tll(b) + tll(Q) * 100LL)%Q);}
int prd(int a, int b) {return ti((tll(a) * tll(b))%Q);}
int pwr(int b, int p) {
  int r = 1;
  for(;p;p>>=1,b=prd(b, b)) if(p&1) r = prd(r, b);
  return r;
}

int dv[MAXN << 1], dvp[MAXN << 1];

void pcp() {
  dvp[0] = 0;
  for(int i = 1;i <= 2*N;i++) dv[i] = pwr(i, Q-2), dvp[i] = sum(dvp[i-1], dv[i]);
}

int v[MAXN << 1], f;

int x, c, t;
void calc(int l, int r, int h) {
  if(h <= 1 or r - l == 1) {
    if(x == -1) x = r - l;
    if(x == r - l) c++; else assert(x == r - l - 1);
    f = sum(f, prd(prd(r - l, r - l - 1), dv[4]));
    t++;
  } else if(r - l > 1) {
    int m = l + ((r - l)>>1);
    calc(l, m, h-1);
    calc(m, r, h-1);
  }
}

int q[3];

int count(int a, int b) {
  int r = 0;
  for(int i = 1;i <= a;i++)
    r = sum(r, dif(prd(b, dv[2]), dif(dvp[i + b], dvp[i])));
  return r;
}

int main() {
  scanf("%d%d%d", &N, &K, &Q);
  
  pcp();
  
  x = -1, c = t = f = 0;
  calc(0, N, K);
  
  q[0] = count(x, x);
  q[1] = count(x, x + 1);
  q[2] = count(x + 1, x + 1);
  
  //cerr << q[0] << " " << q[1] << " " << q[2] << "\n";
  
  for(int i = 0;i < c;i++)
    f = sum(f, sum(prd(q[0], c - i - 1), prd(q[1], t - c)));
  for(int i = c;i < t;i++)
    f = sum(f, prd(q[2], t - i - 1));
  
  printf("%d\n", f);
  
  return 0;
}