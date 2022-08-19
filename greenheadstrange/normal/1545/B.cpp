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
char s[maxn];
ll fac[maxn], rfac[maxn];
void solve() {
  scanf("%d", &n);
  scanf("%s", s);
  int seg = 0;
  int c0 = 0, c1 = 0, seg1 = 0;
  bool cons1 = 0;
  for (int i = 0; i < n - 1; i++)
    if (s[i] == '1' && s[i + 1] == '1')
      cons1 = 1;
  if (!cons1) {
    puts("1");
    return;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      c0++;
      if (seg % 2 == 1)
        seg1++;
      seg = 0;
    } else if (s[i] == '1') {
      c1++;
      seg += 1;
    }
  }
  if (seg % 2 == 1)
    seg1++;
  int extra0 = c0 - (seg1 - 1);
  int extra1 = (c1 - seg1) / 2;
  auto cc = [&](int a, int b) {
    return fac[a + b - 1] * rfac[b] % mod * rfac[a - 1] % mod;
  };
  printf("%lld\n", cc(c0 + 1, extra1));
}

int main() {
  int T;
  scanf("%d", &T);
  fac[0] = 1;
  rfac[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fac[i] = fac[i - 1] * i % mod;
    rfac[i] = ksm(fac[i], mod - 2);
  }
  for (int i = 0; i < T; i++) {
    solve();
  }
}