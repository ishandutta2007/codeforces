#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 1000010, P = 1000000007;

int y[N], ifac[N], pre[N], suf[N];

int mpow(int x, int k);

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k + 1; ++i)
    y[i] = (y[i - 1] + mpow(i, k)) % P;
  ifac[1] = 1;
  for (int i = 2; i <= k + 1; ++i)
    ifac[i] = -(P / i) * (ll)ifac[P % i] % P + P;
  ifac[0] = 1;
  for (int i = 1; i <= k + 1; ++i)
    ifac[i] = ifac[i] * (ll)ifac[i - 1] % P;
  pre[0] = suf[k + 1] = 1;
  for (int i = 1; i <= k + 1; ++i)
    pre[i] = pre[i - 1] * (ll)(P + n - (i - 1)) % P;
  for (int i = k; i >= 0; --i)
    suf[i] = suf[i + 1] * (ll)(P + n - (i + 1)) % P;
  int ans = 0;
  for (int i = 0; i <= k + 1; ++i) {
    int cur = y[i] * (ll)pre[i] % P * suf[i] % P * ifac[i] % P * ifac[k + 1 - i] % P;
    if ((k ^ i) & 1)
      ans = (ans + cur) % P;
    else
      ans = (ans + P - cur) % P;
  }
  printf("%d\n", ans);
  return 0;
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
		if (k & 1)
   	 	ret = ret * (ll)x % P;
    if (k >>= 1)
      x = x * (ll)x % P;
  }
  return ret;
}