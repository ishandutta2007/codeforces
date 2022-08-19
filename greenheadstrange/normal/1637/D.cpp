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

template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int n, a[maxn], b[maxn];

void solve() {
  scanf("%d", &n);
  int tots = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans = ans + a[i] * a[i];
    tots += a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    ans = ans + b[i] * b[i];
    tots += b[i];
  }
  bitset<20001> s;
  s[0] = 1;
  for (int i = 1; i <= n; i++) s = (s << a[i]) | (s << b[i]);
  ans *= (n - 2);
  int ans2 = 1<<30;
  for (int i = 0; i <= 20000; i++)
    if (s[i]) ans2 = min(ans2, i * i + (tots - i) * (tots - i));
  printf("%lld\n", ans + ans2);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}