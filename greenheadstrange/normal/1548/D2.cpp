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

int cnt[10][10];
vector<pi> p[3][3];
ll ans;

ll solve(vector<pi> p) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      cnt[i][j] = 0;
  int m = p.size();
  ll ans = 0;
  for (int i = 0; i < m; i++)
    cnt[p[i].fi / 2 % 2][p[i].se / 2 % 2]++;
  vector<pi> pp{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  for (auto x : pp)
    for (auto y : pp)
      for (auto z : pp)
        if (x <= y && y <= z) {
          int c1 = cnt[x.fi][x.se], c2 = cnt[y.fi][y.se], c3 = cnt[z.fi][z.se];
          if (x == y || y == z) {
            if (x == y && y == z) {
              ans += (ll)c1 * (c1 - 1) * (c1 - 2) / 6;
            } else if (x == y) {
              ans += (ll)c1 * (c1 - 1) / 2 * c3;
            } else if (y == z) {
              ans += (ll)c1 * c3 * (c3 - 1) / 2;
            }
          }
        }
  return ans;
}

ll solve2(vector<pi> p, vector<pi> q) {
  int n = p.size(), m = q.size();
  ll ans = 0;

  auto check = [&](int x1, int y1, int x2, int y2, int x3, int y3) {
    x2 -= x1;
    y2 -= y1;
    x3 -= x1;
    y3 -= y1;
    int s = x2 * y3 - x3 * y2;
    assert(s % 2 == 0);
    if (s % 2 != 0)
      return 0;
    s /= 2;
    s = abs(s);
    int b = abs(gcd(x2, y2)) + abs(gcd(x3, y3)) + abs(gcd(x2 - x3, y2 - y3));
    if ((s - b / 2) % 2 == 0)
      return 1;
    return 0;
  };

  for (int i = 0; i < n; i++) {
    map<array<int, 3>, int> c;
    for (int j = 0; j < m; j++) {
      c[{(int)abs(gcd(q[j].fi - p[i].fi, q[j].se - p[i].se)) % 4,
         ((q[j].fi - p[i].fi) % 4 + 4) % 4,
         ((q[j].se - p[i].se) % 4 + 4) % 4}]++;
    }
    ll dd = 0;
    for (auto x : c)
      for (auto y : c) {
        if (x <= y) {
          auto X = x.fi, Y = y.fi;
          int s = (X[1] * Y[2] - X[2] * Y[1]) / 2 % 2;
          int b =
              (X[0] + Y[0] + (mp(X[1], X[2]) != mp(Y[1], Y[2]) ? 2 : 0)) % 4;
          if ((s - b / 2) % 2 == 0) {
            if (x == y) {
              ans += x.se * (x.se - 1) / 2;
            } else {
              ans += x.se * y.se;
            }
          }
        }
      }
  }

  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
    p[x[i] % 2][y[i] % 2].pb(mp(x[i], y[i]));
  }
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= 1; j++)
      ans += solve(p[i][j]);
  vector<pi> q{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  for (auto p1 : q)
    for (auto p2 : q)
      if (p1 != p2)
        ans += solve2(p[p1.fi][p1.se], p[p2.fi][p2.se]);
  printf("%lld\n", ans);
}