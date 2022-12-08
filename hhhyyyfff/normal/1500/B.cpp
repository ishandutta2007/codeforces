#include <bits/stdc++.h>

using namespace std;

int n, m, x, ind, a[1000001];
long long k, l, r, mid, lcm, t1, t2, g[1000001];

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

long long ex_gcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ex_gcd(b, a % b, x, y);
  long long temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}

bool liEu(long long a, long long b, long long c, long long& x, long long& y) {
  long long d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  long long k = c / d;
  x *= k;
  y *= k;
  return 1;
}

long long check(long long ans) {
  long long cnt = 0;
  for (int i = 0; i < ind; ++i)
    if (ans >= g[i])
      cnt += (ans - g[i]) / lcm + 1;
  return ans - cnt;
}

int main() {
  scanf("%d%d%lld", &n, &m, &k);
  lcm = n / gcd(n, m) * m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    a[x] = i;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &x);
    if (a[x])
      if (liEu(n, -m, i - a[x], t1, t2))
        g[ind++] = ((t1 * n + a[x]) % lcm + lcm - 1) % lcm + 1;
  }
  r = max(n, m) * k;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid) >= k)
      r = mid; else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}