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

int n;
int s[maxn];
ll ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  for (int i = 1; i < n; i += 2) {
    ll p = 0, q = 0;
    for (int j = i; j < n; j += 2) {
      ll L = max(s[i - 1] + q, -1ll), R = max(s[j] - (p - q), -1ll);
      ans += min(L, R) + (i != j);
      p -= s[j];
      q = min(q, p);
      p += s[j + 1];
    }
  }
  printf("%lld\n", ans);
}