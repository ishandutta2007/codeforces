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

int n, q, f[maxn];
char s[maxn], val[10];

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  int ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    f[i] = (s[i] == 'a') && (s[i + 1] == 'b') && (s[i + 2] == 'c');
    ans += f[i];
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d%s", &x, val);
    for (int j = x; j >= 1 && j >= x - 2; j--) ans -= f[j];
    s[x] = val[0];
    for (int j = x; j >= 1 && j >= x - 2; j--) {
      f[j] = (s[j] == 'a') && (s[j + 1] == 'b') && (s[j + 2] == 'c');
      ans += f[j];
    }
    printf("%d\n", ans);
  }
}