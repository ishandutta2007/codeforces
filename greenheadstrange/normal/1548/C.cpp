// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 3000005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

ll gcd(ll a, ll b) {
  int shift = __builtin_ctzll(a | b);
  if (shift)
    return 2;
  if (a == 1 || b == 1)
    return 1;
  b >>= __builtin_ctzll(b);
  while (a) {
    a >>= __builtin_ctzll(a);
    if (a < b)
      swap(a, b);
    a -= b;
  }
  return b << shift;
}

int n, q;
ll inv[maxn], f[maxn], g[maxn];
int main() {
  scanf("%d%d", &n, &q);
  inv[1] = 1;
  for (int i = 2; i <= 3 * n + 3; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  f[0] = 1;
  for (int i = 1; i <= 3 * n + 3; i++) {
    f[i] = f[i - 1] * (3 * n + 4 - i) % mod * inv[i] % mod;
  }
  f[0] = 0;
  for (int i = 3 * n; i >= 0; i--) {
    g[i] = f[i + 3];
    if (g[i] < 0)
      g[i] += mod;
    f[i + 2] = (f[i + 2] - g[i] * 3) % mod;
    f[i + 1] = (f[i + 1] - g[i] * 3) % mod;
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", g[x]);
  }
}