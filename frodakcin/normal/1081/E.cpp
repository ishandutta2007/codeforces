#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

void fail() {
  printf("No\n");
  exit(0);
}

typedef long long ll;
#define tll(X) static_cast<ll>(X)

const int MAXN = 2e5 + 100;
const int MAXV = 2e5 + 100;
const ll MAXX = 1e13;

typedef vector<int> vi;
#define pb push_back

vi d[MAXV];

void nx(int p, int c, int& a, int& b) {
  int e;
  for(int v : d[c]) {
    e = c/v;
    if((a = (e - v)>>1) > p) {
      b = (e + v)>>1;
      return;
    }
  }
  fail();
}

int N;
int f[MAXN];

int main() {
  for(int i = MAXV;i >= 1;i--)
    for(int j = i;tll(i) * j < MAXV;j+=2)
      d[i*j].pb(i);
  
  scanf("%d", &N);
  f[0] = 0;
  for(int i = 1, v;i <= N;i += 2) {
    scanf("%d", &v);
    nx(f[i-1], v, f[i], f[i+1]);
  }
  
  printf("Yes\n");
  for(int i = 1;i <= N;i++) printf("%lld ", tll(f[i]) * f[i] - tll(f[i-1]) * f[i-1]);
  printf("\n");
  
  return 0;
}