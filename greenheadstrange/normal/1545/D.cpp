// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 1010
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

int n, m, a[maxn][maxn];
ll s[maxn], s2[maxn], det;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      s[i] += a[i][j];
      s2[i] += (ll)a[i][j] * a[i][j];
    }
  }
  auto check = [&](int a, int b) {
    if ((s[b] - s[a]) % (b - a) != 0)
      return -1;
    ll d = (s[b] - s[a]) / (b - a), c = s[b] - d * b;
    vi invalid;
    for (int i = 0; i < m; i++)
      if (s[i] != c + d * i)
        invalid.pb(i);
    if (invalid.size() != 1) {
      return -1;
    }
    int x = invalid[0];
    det = c + d * x - s[x];
    return invalid[0];
  };
  int moment = -1;
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++) {
      int d = check(i, j);
      if (d != -1) {
        moment = d;
        goto found;
      }
    }
found:;
  assert(moment != -1);
  vector<pair<int, ll>> poly;
  for (int i = 0; i < m; i++)
    if (i != moment && poly.size() < 3) {
      poly.push_back({i, s2[i]});
    }
  assert(poly.size() == 3);
  ll val = 0;
  for (int i = 0; i < 3; i++) {
    ll s = poly[i].se;
    for (int j = 0; j < 3; j++)
      if (j != i) {
        s = s * (moment - poly[j].fi);
      }
    for (int j = 0; j < 3; j++)
      if (j != i) {
        s = s / (poly[i].fi - poly[j].fi);
      }
    val += s;
  }
  ll v = s2[moment];
  for (int i = 0; i < n; i++) {
    ll x = a[moment][i], y = x + det;
    ll w = v - x * x + y * y;
    if (w == val) {
      printf("%d %lld\n", moment, y);
      return 0;
    }
  }
  assert(0);
}