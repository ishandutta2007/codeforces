#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 100;
const int MAXV = 1e7 + 100;

void ans(const int& f) {
  printf("%d\n", f);
  exit(0);
}

int N, K;

typedef long long ll;
#define tll(X) static_cast<ll>(X)

ll p[MAXV], f[MAXV];

int main() {
  for(int i = 0;i < MAXV;i++) p[i] = f[i] = 0LL;
  
  scanf("%d%d", &N, &K);
  for(int i = 0, a;i < N;i++) scanf("%d", &a), p[a]++, f[a]++;
  
  for(int i = MAXV - 2;i > 0;i--) {
    f[i] += f[i + 1];
    if(not(f[i] < tll(K))) ans(i);
    f[i>>1] += p[i];
    p[i>>1] += p[i];
    p[(i + 1)>>1] += p[i];
  }
  
  ans(-1);
  
  return 0;
}