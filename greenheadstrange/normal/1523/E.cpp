// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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

int n, k;
ll f[maxn], rf[maxn];
void solve() {
  scanf("%d%d", &n, &k);
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * i % mod;
    rf[i] = ksm(f[i], mod - 2);
  }
  auto C = [&](int x, int y) {
    if (y < 0 || y > x)
      return 0ll;
    return f[x] * rf[y] % mod * rf[x - y] % mod;
  };
  ll ans = 1;
  for (int i = 1; (i - 1) * (k - 1) <= n; i++)
    ans = (ans + C(n - (i - 1) * (k - 1), i) * ksm(C(n, i), mod - 2)) % mod;
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}