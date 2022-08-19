// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
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
  if (a == 1 || b == 1)
    return 1;
  a >>= shift;
  b >>= shift;
  b >>= __builtin_ctzll(b);
  while (a) {
    a >>= __builtin_ctzll(a);
    if (a < b)
      swap(a, b);
    a -= b;
  }
  return b << shift;
}
int n;
ll a[maxn], b[maxn][20];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  for (int i = 1; i < n; i++) {
    b[i][0] = abs(a[i] - a[i + 1]);
  }
  int ans = 0;
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i + (1 << j) <= n; i++)
      b[i][j] = gcd(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
  for (int i = 1; i < n; i++) {
    ll d = b[i][0];
    int len = 0;
    int x = i;
    for (int j = 18; j >= 0; j--)
      if (x + (1 << j) <= n) {
        ll dd = gcd(d, b[x][j]);
        if (dd != 1)
          len += (1 << j), x += (1 << j), d = dd;
      }
    if (d != 1)
      ans = max(ans, len);
  }
  printf("%d\n", ans + 1);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}