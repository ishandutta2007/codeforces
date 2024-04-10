#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 100;
typedef double ld;
#define tld(X) static_cast<ld>(X)

int N, S;

int d[MAXN];

int main() {
  scanf("%d%d", &N, &S);
  
  for(int i = 0;i <= N;i++) d[i] = 0;
  for(int i = 0, u;i < (N - 1)<<1;i++) scanf("%d", &u), d[u]++;
  
  int L = 0;
  for(int i = 1;i <= N;i++) L += d[i] == 1;
  
  printf("%.9g\n", tld(S) * tld(2)/tld(L));
  
  return 0;
}