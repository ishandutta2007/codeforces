#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

int fail() {
  printf("NO\n");
  return 0;
}

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MN = 1e5 + 1000;
const ll MS = 1e10 + 1000LL;

int N;
ll S;

ll c2(int x) {
  return tl(x) * (x + 1)/2;
}
ll cr(int x, int c) {
  return c2(x + c) - c2(x);
}

int q[MN];
ll c, t;
bool solve(int B) {
  c = 1LL, t = 1LL;
  for(int i = 2, j = 1;j < N;i++) {
    t *= B;
    if(t + j > N) c += (N - j) * i, j = N; else c += t*i, j += ti(t);
    if(c > S) return false;
  }
  return true;
}

void gen(int B) {
  q[0] = 0, q[1] = 1;
  c = 1LL;
  for(int i = 2, j = N-1;q[i-1] > 0 and j > 0;i++) {
    q[i] = 0;
    t = q[i-1]*B;
    for(int u = 0;u < t and (cr(i, j-1) + c + i >= S) and j > 0;u++) c += i, q[i]++, j--;
  }
  assert(c == S);
}
void ans(int B) {
  int X = 1;
  for(int i = 2, p;q[i] != 0;i++) {
    p = X;
    for(int j = 0, z = 0;j < q[i];j++, z++) {
      if(z >= B) z = 0, p--;
      printf("%d ", p);
      X++;
    }
  }
  printf("\n");
}

int main() {
  scanf("%d%lld", &N, &S);
  
  if(S < N*2 - 1 or S > c2(N)) return fail();
  
  printf("YES\n");
  
  int l = 0, h = N;
  while(l + 1 < h) {
    int m = l + (h-l)/2;
    if(solve(m)) h = m;
    else l = m;
  }
  
  gen(h);
  ans(h);
  
  return 0;
}