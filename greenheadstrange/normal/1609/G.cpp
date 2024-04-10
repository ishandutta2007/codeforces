// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 998244353
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

int n, m, q;
ll a[maxn], b[maxn];

ll da[maxn], db[maxn];

ll c[maxn];
void modify(int x, ll v) {
  for (; x <= m; x += x & -x) c[x] += v;
}
int query(ll v) {
  int p = 0;
  for (int d = 18; d >= 0; d--)
    if (p + (1 << d) <= m && v >= c[p + (1 << d)]) p += (1 << d), v -= c[p];
  return p;
}

struct fenwick {
  ll c[maxn];

  void modify(int x, ll v) {
    for (; x <= m; x += x & -x) c[x] += v;
  }
  ll query(int x) {
    ll v = 0;
    for (; x; x -= x & -x) v += c[x];
    return v;
  }
} c1, c2;

ll sb = 0;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    da[i - 1] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &b[i]);
    sb += b[i];
    db[i - 1] = b[i] - b[i - 1];
  }
  da[n] = 1ll << 59;
  db[m] = 1ll << 60;
  db[0] = 0;
  for (int i = 1; i <= m; i++) {
    modify(i, db[i] - db[i - 1]);
  }
  for (int t = 0; t < q; t++) {
    int ty, k, d;
    scanf("%d%d%d", &ty, &k, &d);
    if (ty == 1) {
      k = n - k + 1;
      for (int i = k; i <= n; i++) {
        a[i] += d * (i - k + 1);
        da[i - 1] += d;
      }
    } else {
      sb += (ll)k * (k + 1) / 2 * d;
      k = m - k + 1;
      modify(max(1, k - 1), d);
      c1.modify(k, d);
      c2.modify(k, (ll)k * d);
    }
    int q = 1;
    ll ans = sb;
    for (int i = 1; i <= n; i++) {
      int qq = query(da[i]) + 1;
      ans += (qq - q + 1) * a[i];
      q = qq;
      if (i != n) {
        ans += (q + 1) * c1.query(q) - c2.query(q) + b[q];
      }
    }
    printf("%lld\n", ans);
  }
}