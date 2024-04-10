// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 7005 /*rem*/
#define mod 1000000007
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

int x[maxn], y[maxn];
int n;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int cnt[10][10], d[maxn][maxn];
ll ans;
pi g[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
    cnt[x[i] % 4][y[i] % 4]++;
    g[i] = mp(x[i] % 4, y[i] % 4);
  }
  vector<pi> p{{0, 0}, {0, 2}, {2, 0}, {2, 2}};
  for (auto x : p)
    for (auto y : p)
      for (auto z : p)
        if (x <= y && y <= z) {
          int d1 = (x == y) ? 0 : 2, d2 = (y == z) ? 0 : 2,
              d3 = (x == z) ? 0 : 2;
          int c1 = cnt[x.fi][x.se], c2 = cnt[y.fi][y.se], c3 = cnt[z.fi][z.se];
          if ((d1 + d2 + d3) % 4 == 0) {
            if (x == y && y == z) {
              ans += (ll)c1 * (c1 - 1) * (c1 - 2) / 6;
            } else if (x == y) {
              ans += (ll)c1 * (c1 - 1) / 2 * c3;
            } else if (y == z) {
              ans += (ll)c1 * c3 * (c3 - 1) / 2;
            } else {
              ans += (ll)c1 * c2 * c3;
            }
          }
        }
  printf("%lld\n", ans);
  /*  for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        d[i][j] = abs(gcd(x[i] - x[j], y[i] - y[j]));
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        for (int k = j + 1; k <= n; k++) {
          assert(((d[i][j] + d[j][k] + d[i][k]) % 4 == 0) ==
                 (g[i] == g[j] || g[j] == g[k] || g[k] == g[i]));
          if ((d[i][j] + d[j][k] + d[i][k]) % 4 == 0) {
            ans2++;
          }
        }
    printf("%d\n", ans2);*/
}