// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
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

int n, m;
int a[maxn], b[maxn], f[maxn];

int par(int x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = par(f[x]);
}
void solve() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    f[par(a[i])] = par(b[i]);
  }
  ll ans = 1;
  for (int i = 1; i <= n; i++)
    if (par(i) == i)
      ans = ans * 2 % mod;
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}