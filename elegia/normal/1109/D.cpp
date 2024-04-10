#include <cstdio>
#include <cmath>
#include <cstring>

#include <algorithm>
#include <vector>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int P = 1000000007;
const int N = 1000010;

int fac[N * 2], ifac[N * 2];
int pw[N], npw[N];

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    k >>= 1;
    x = x * (ll)x % P;
  }
  return ret;
}

void prepare(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = fac[i - 1] * (ll)i % P;
  ifac[1] = 1;
  for (int i = 2; i <= n; ++i)
    ifac[i] = -(P / i) * (ll)ifac[P % i] % P + P;
  ifac[0] = 1;
  for (int i = 1; i <= n; ++i)
    ifac[i] = ifac[i - 1] * (ll)ifac[i] % P;
}

int binom(int n, int m) {
  return fac[n] * (ll)ifac[m] % P * ifac[n - m] % P;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  
  int n, m;
  scanf("%d%d", &n, &m);
  prepare(n + m);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i)
    pw[i] = pw[i - 1] * (ll)m % P;
  npw[0] = 1;
  for (int i = 1; i <= n; ++i)
    npw[i] = npw[i - 1] * (ll)n % P;
  int ans = 0;
  for (int k = 1; k <= min(n - 1, m); ++k) {
    int pth = binom(m - 1, k - 1) * (ll)binom(n - 2, k - 1) % P * fac[k - 1] % P * pw[n - 1 - k] % P * (k + 1) % P * npw[n - k - 1] % P;
    if ((ans += pth) >= P)
      ans -= P;
  }
  ans = ans * (ll)mpow(n, P - 2) % P;
  printf("%d\n", ans);
  
  return 0;
}