#include <iostream>
#include <cstdio>

#include <utility>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 100;

int N, r[MAXN];

typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair

void fix(pii& p, int a, int b) {
  if(p.ff == -1 or a < p.ff) p.ff = a;
  if(p.ss == -1 or p.ss < b) p.ss = b;
}

struct ST {
  int l[MAXN* 6], h[MAXN * 6];
  int sz;
  
  void set(int n, int v1, int v2) {
    if(v1 < 0) v1 = 0;
    if(not (v2 < sz)) v2 = sz - 1;
    l[sz + n] = v1, h[sz + n] = v2;
  }
  void set(int n, const pii& v) {
    set(n, v.ff, v.ss);
  }
  pii get(int n) {
    return mp(l[sz + n], h[sz + n]);
  }
  void build() {
    for(int i = sz - 1;i > 0;i--) l[i] = min(l[i<<1], l[i<<1|1]), h[i] = max(h[i<<1], h[i<<1|1]);
  }
  pii qry(int a, int b) {
    pii f(-1, -1);
    for(a += sz, b += sz + 1;a < b;a>>=1, b>>=1) {
      if(a&1) fix(f, l[a], h[a]), a++;
      if(b&1) b--, fix(f, l[b], h[b]);
    }
    return f;
  }
  pii qry(const pii& a) {return qry(a.ff, a.ss);}
  void pout() {for(int i = sz;i < 2*sz;i++) printf("%d: %d, %d\n", i, l[i], h[i]); printf("\n"); }
} st[20];

int& gr(int n) {
  assert(not (n < 0) and n < 3*N);
  while(not(n < N)) n -= N;
  return r[n];
}

int log2(int v) {
  int r = 0;
  while(v>>=1) r++;
  return r;
}

bool valid(const pii& p) {
  return p.ss - p.ff + 1 < N;
}

int main() {
  scanf("%d", &N);
  if(N == 1) {printf("%d\n", 0); return 0;}
  for(int i = 0;i < N;i++) scanf("%d", r + i);
  for(int i = 0;(1 << i) <= N;i++) st[i].sz = N*3;
  
  for(int i = 0;i < 3*N;i++) {
    st[0].set(i, i - gr(i), i + gr(i));
  }
  st[0].build();
  for(int s = 1;(1 << s) <= N;s++) {
    for(int i = 0;i < 3*N;i++) {
      st[s].set(i, st[s-1].qry(st[s-1].get(i)));
    }
    st[s].build();
  }
  
  pii r, t;
  for(int i = N, c, b = log2(N);i < 2*N;i++, c = 0) {
    r = mp(i, i);
    
    for(int j = b;j >= 0;j--) {
      if(c + (1 << j) > N) continue;
      if(valid(t = st[j].qry(r))) c += (1 << j), r = t;
    }
    
    printf("%d ", ++c);
  }
  printf("\n");
  
  return 0;
}