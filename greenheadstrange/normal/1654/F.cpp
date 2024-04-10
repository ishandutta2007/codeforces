// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn (1 << 18) + 10 /*rem*/
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

int n, r[20][maxn];
char s[maxn];

int main() {
  scanf("%d" ,&n);
  scanf("%s", s);
  for (int v = 0; v < (1 << n); v++)
    r[0][v] = s[v] - 'a';
  for (int d = 1; d <= n; d++) {
    vector<array<int,3>> rk;
    for (int v = 0 ; v < (1 << n); v += (1 << d)) {
      for (int j = 0; j < (1 << (d - 1)); j++) {
        rk.push_back({r[d - 1][v + j], r[d - 1][v + (1 << (d - 1)) + j], v + j});
        rk.push_back({r[d - 1][v + (1 << (d - 1)) + j], r[d - 1][v + j], v + (1 << (d - 1)) + j});
      }
    }
    sort(rk.begin(), rk.end());
    int v = 0;
    for (int i = 0; i < (int)rk.size(); i++) {
      if (i != 0 && mp(rk[i][0], rk[i][1]) != mp(rk[i - 1][0], rk[i - 1][1])) v++;
      r[d][rk[i][2]]= v;
    }
  }
  int pos = min_element(r[n], r[n] + (1 << n)) - r[n];
  for (int i = 0; i < (1 << n); i++)
    putchar(s[pos ^ i]);
  puts("");
}