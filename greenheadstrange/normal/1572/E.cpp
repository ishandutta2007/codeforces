// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 205 /*rem*/
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

pair<int, ll> dp[maxn][maxn];
ll x[maxn], y[maxn], S;
int nxt[maxn], n, k;

int check(ll s) {
  S = s;
  int d = 0;
  for (int dis = 1; dis < n; dis++) {
    for (int r = 0; r < n; r++) {
      int l = (r + dis) % n;
      if (dis == 1) {
        dp[l][r] = mp(0, 0);
        continue;
      }
      dp[l][r] = mp(-1, -1);
      for (int k = nxt[r]; k != l; k = nxt[k]) {
        ll s = (x[r] - x[l]) * (y[k] - y[l]) - (x[k] - x[l]) * (y[r] - y[l]);
        auto s1 = dp[l][k], s2 = dp[k][r];
        int p1 = s1.fi + s2.fi;
        ll p2 = s1.se + s2.se + s;
        if (p2 >= S)
          p2 = 0, p1++;
        dp[l][r] = max(dp[l][r], mp(p1, p2));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    d = max(d, dp[i][nxt[i]].fi);
  }
  return d;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%lld%lld", x + i, y + i), nxt[i] = (i + 1) % n;
  ll l = 0, r = (1ll << 60);
  // printf("%d\n", check(1000));
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (check(mid) >= k + 1)
      l = mid;
    else
      r = mid;
  }
  printf("%lld\n", l);
}