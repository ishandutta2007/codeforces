#include <iostream>
#include <cstdio>

#include <cmath>

using namespace std;

typedef long double ld;
#define tld(X) static_cast<ld>(X)

const int MAXN = 1e3 + 100;

int N, L;
#define sqrt sqrtl

int r[MAXN][2];
ld d[MAXN];
int p[MAXN];

bool solve(ld v) {
  for(int i = 0;i <= N;i++) p[i] = -1;
  for(int i = 0;i < N;i++) {
    ld t = sqrt(abs(tld(r[i][0] - L))) - (r[i][1] * v);
    p[i] = -1, d[i] = t;
    for(int j = 0;j < i;j++) {
      t = d[j] + (sqrt(abs(tld(r[i][0] - r[j][0] - L)))) - (r[i][1] * v);
      if(t < d[i]) d[i] = t, p[i] = j;
    }
  }
  return d[N-1] > tld(0);
}

void ans(int v) {
  if(p[v] != -1) ans(p[v]);
  printf("%d ", v + 1);
}

int main() {
  scanf("%d%d", &N, &L);
  
  for(int i = 0;i < N;i++) scanf("%d%d", r[i] + 0, r[i] + 1);
  
  ld l = -0.1, h = 1e15;
  for(int i = 0;i < 200;i++) {
    ld m = (l + h)/2;
    if(solve(m)) l = m;
    else h = m;
  }
  
  solve(h);
  ans(N - 1);
  printf("\n");
  
  return 0;
}