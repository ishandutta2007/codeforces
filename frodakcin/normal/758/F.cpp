#include <iostream>
#include <cstdio>

#include <bitset>
#include <algorithm>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MV = 1e7 + 10000;
const int PC = 7e5;    //~665k

template <int T> using bs = bitset<T>;

bs<MV> p;
int L[PC], d[MV], c[MV], n[MV];

const int INF = 1e9;

bool mul(int& a, int b) {
  if(not a or not b) return a = 0;
  if(a > INF/b) {a = INF; return true;}
  assert((a *= b) <= INF);
  return a == INF;
}
int pw(int b, int p) {
  int r = 1;
  for(;p;p>>=1, mul(b, b)) if(p&1 and mul(r, b)) return INF;
  return r;
}

void sieve() {
  L[0] = 0;
  p.set();
  
  for(int i = 2;i < MV;i++) {
    if(p[i]) {
      L[++L[0]] = i;
      n[i] = 1, c[i] = 1, d[i] = i;
    }
    for(int j = 1, k;j <= L[0] and (k=i*L[j]) < MV;j++) {
      assert(p[k]);
      p[k] = false;
      d[k] = L[j];
      if(d[i] == d[k]) {
        c[k] = c[i] + 1, n[k] = n[i];
        break;
      }
      c[k] = 1, n[k] = i;
    }
  }
}

int N;
int conv(int v) {
  if(v == 1) return 1;
  return conv(n[v]) * pw(d[v], c[v]%N);
}

int t[MV];

int nrt(int p, int v) {//pth root of v
  int l = 0, h = v;
  while(l + 1 < h) {
    int m = l + (h-l)/2;
    if(pw(m, p) < v) l = m;
    else h = m;
  }
  return l;
}

int l, r;

int main() {
  sieve();
  
  scanf("%d%d%d", &N, &l, &r);
  
  if(N == 1) {printf("%d\n", r - l + 1); return 0;}
  if(N == 2) {printf("%lld\n", tl(r - l + 1) * (r - l)); return 0;}
  N--;
  
  int f = 0;
  for(int i = l, j;i <= r;i++) {
    j = conv(i);
    f += nrt(N, 1 + r/j) - nrt(N, (l + j - 1)/j);
  }
  
  printf("%d\n", f - (r - l + 1));
  
  return 0;
}