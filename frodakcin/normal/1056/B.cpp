#include <iostream>
#include <cstdio>

using namespace std;

const int MAXM = 1e3 + 100;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

int N, M;

int c[MAXM];

int main() {
  scanf("%d%d", &N, &M);
  
  int d = N/M;
  int m = N%M;
  for(int i = 0;i <= m;i++) c[(i*i)%M] += d + 1;
  for(int i = m + 1;i < M;i++) c[(i*i)%M] += d;
  
  c[0]--;
  ll ans = tll(c[0]) * tll(c[0]);
  
  for(int i = 1;i < M;i++) {
    ans += tll(c[i]) * tll(c[M - i]);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}