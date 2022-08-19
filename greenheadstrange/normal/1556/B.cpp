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

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void solve() {
  int n;
  scanf("%d", &n);
  vi pos1;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x %= 2;
    if (x == 0)
      c0++;
    else
      c1++, pos1.pb(c0);
  }
  ll ans = 1ll << 60;
  for (int o = 0; o <= 1; o++) {
    int d0 = 0, d1 = 0;
    vi pos2;
    for (int i = 0; i < n; i++) {
      if (i % 2 == o) {
        d0++;
      } else {
        d1++;
        pos2.pb(d0);
      }
    }
    if (d0 == c0 && d1 == c1) {
      ll ans2 = 0;
      for (int j = 0; j < d1; j++)
        ans2 += abs(pos1[j] - pos2[j]);
      ans = min(ans, ans2);
    }
  }
  if (ans >= (1ll << 60)) {
    puts("-1");
  } else {
    printf("%lld\n", ans);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}