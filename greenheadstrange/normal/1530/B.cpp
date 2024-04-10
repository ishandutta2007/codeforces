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

int n ,m;
bool g[30][30];
void solve() {
  scanf("%d%d", &n, &m);
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (i == 1 || i == n || j == 1 || j == m) {
        if (g[i - 1][j - 1] == 0 && g[i - 1][j] == 0 && g[i - 1][j + 1] == 0 &&
            g[i][j - 1] == 0) {
          g[i][j] = 1;
        }
      }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      printf("%d", g[i][j]);
    puts("");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}