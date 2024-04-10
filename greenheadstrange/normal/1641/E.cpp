// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>

#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector < int >
  #define pb push_back
#define mp make_pair
#define pi pair < int, int >
  #define fi first
#define se second

template < typename T >
  bool chkmax(T & x, T y) {
    return x < y ? x = y, true : false;
  }
template < typename T >
  bool chkmin(T & x, T y) {
    return x > y ? x = y, true : false;
  }

using namespace std;
mt19937 mrand(random_device {}());

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int n, m;
int a[maxn], pos[maxn], fs[maxn], gs[maxn], pre[maxn], suf[maxn], spre[maxn], ssuf[maxn];
ll pw[maxn];
int ans = 0;
int f1[260][260], f2[260][260];
int main() {
  scanf("%d%d", & n, & m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", & a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int p;
    scanf("%d", & p);
    pos[p] = 1;
  }
  for (int s1 = 0; s1 < 256; s1++)
    for (int s2 = 0; s2 < 256; s2++) {
      f1[s1][s2] = 0, f2[s1][s2] = 0;
      for (int c = 0; c < 8; c++) {
        f2[s1][s2] += 1;
        if (s1 & (1 << c)) f1[s1][s2]++, f2[s1][s2] *= 2;
        if (s2 & (1 << c)) f1[s1][s2]++, f2[s1][s2] *= 2;
      }
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 8; j++) fs[i] |= (pos[i + j] << j);
    for (int j = 0; j < 8; j++)
      if (i - j >= 1) gs[i] |= (pos[i - j] << j);
  }
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + pos[i];
    spre[i] = (spre[i - 1] + pw[pre[i]]) % mod;
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + pos[i];
    ssuf[i] = (ssuf[i + 1] + pw[suf[i]]) % mod;
  }
  int T = n + 10;
  for (int i = 1; i <= n; i++) {
    ll w = 0;
    int p1, p2, cc = 0;
    for (p1 = i + 1, p2 = i - 1; p1 <= n && p2 >= 1; p1 += 8, p2 -= 8, cc += 8) {
      w = ((w << f1[fs[p1]][gs[p2]]) + f2[fs[p1]][gs[p2]]) % mod;
    }
    if (p2 >= 1) {
      w = (w * pw[pre[p2]] + spre[p2]) % mod;
      cc += p2;
    }
    if (p1 <= n) {
      w = (w * pw[suf[p1]] + ssuf[p1]) % mod;
      cc += (n + 1 - p1);
    }
    w = (w + T - cc);
    ans = (ans + w * a[i]) % mod;
  }
  ll s = 0;
  for (int i = 1; i <= n; i++) s = (s + a[i]) % mod;
  ans = (ans - T * s) % mod;
  if (ans < 0) ans += mod;
  ans = ans * ksm(ksm(2, m) - 1, mod - 2) % mod;
  printf("%d\n", ans);
}