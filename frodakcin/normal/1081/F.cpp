#include <iostream>
#include <cstdio>

#include <bitset>
#include <cassert>

using namespace std;

const int MAXN = 300 + 10;

int N, T;

typedef bitset<MAXN> vb;

void flip(vb& v, int l, int r) {
  for(int i = l;i < r;i++) v.flip(i);
}
int count(const vb& a, const vb& m, int l, int r) {
  int q = 0;
  for(int i = l;i < r;i++) q += a[i] xor m[i];
  return q;
}

vb s, f;

int ask(int l, int r) {
  printf("? %d %d\n", ++l, ++r);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  if(x == -1) exit(0);
  return x;
}
void ans() {
  printf("! ");
  for(int i = 0;i < N;i++) printf("%d", f[i] == true);
  printf("\n");
}

void solve(int S = 0) {
  for(int i = S, n, d, c, j;i < N;i++) {
    for(;;) {
      n = ask(j = (N&1) xor (i&1), i);
      if((i&1) xor (abs(T-n)&1)) break;
      flip(s, j, N);
      T = n;
    }
    d = n - T;
    c = count(f, s, 0, i);
    
    assert((i - (c<<1)) + 1 == d or (i - (c<<1)) - 1 == d);
    if(i - (c<<1) + 1 == d) f[i] = s[i];
    else f[i] = not s[i];
    
    flip(s, 0, i + 1);
    T = n;
  }
  ans();
}

void solve1() {
  int n;
  for(;;) {
    n = ask(1, N-1);
    if(not(abs(n-T)&1)) break;
    flip(s, 0, N);
    T = n;
  }
  
  int d = n - T;
  assert(N - (T<<1) + 1 == d or N - (T<<1) - 1 == d);
  if(N - (T<<1) + 1 == d) f[0] = not s[0];
  else f[0] = s[0];
  
  flip(s, 1, N);
  T = n;
  solve(1);
}

int main() {
  scanf("%d%d", &N, &T);
  
  if(N == 1) printf("! %d\n", T);
  else if(N&1) solve1();
  else solve();
  
  return 0;
}