// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 10005 /*rem*/
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

int n, m;
char s[maxn],t[maxn];
void solve() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    t[i] = s[i];
    t[n] = 0;
    if (s[i] == '1') {
      continue;
    }
    int L = -(1 << 30), R = (1 << 30);
    for (int j = 0; j < n; j++)
      if (s[j] == '1') {
        if (j < i)
          L = max(L, j);
        else
          R = min(R, j);
      }
    if (L >= 0 && R < n) {
      if (i - L == R - i)
        continue;
      if (min(i - L, R - i) <= m)
        t[i] = '1';
    } else if (L >= 0 || R <= n) {
      if (min(i - L, R - i) <= m)
        t[i] = '1';
    }
  }
  puts(t);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}