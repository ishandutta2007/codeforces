// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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

int n, d[maxn];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  sort(d, d + n);
  ll ans = d[n - 1];
  for (int i = 0; i < n; i++)
    ans -= (ll)(2 * i - n + 1) * d[i];
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}