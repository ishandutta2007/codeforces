// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 105 /*rem*/
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

int n, a[maxn];
int g[maxn][maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    set<int> s;
    for (int j = i; j <= n; j++) {
      s.insert(a[i]);
      g[i][j+1] = 0;
      while (s.count(g[i][j+1])) g[i][j+1]++;
      g[i][j + 1] += 1;
    }
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i < k; i++)
      for (int j = k + 1; j <= n + 1; j++)
        g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n + 1; j++) ans += g[i][j];
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}