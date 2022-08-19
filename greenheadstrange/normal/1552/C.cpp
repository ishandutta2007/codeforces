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

int n, k;
void solve() {
  scanf("%d%d", &n, &k);
  set<int> s;
  for (int i = 1; i <= 2 * n; i++)
    s.insert(i);
  vector<pi> seg;
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    s.erase(u);
    s.erase(v);
    if (u > v)
      swap(u, v);
    seg.pb({u, v});
  }
  vi t(s.begin(), s.end());
  for (int i = 0; i < n - k; i++)
    seg.pb({t[i], t[i + n - k]});
  int ans = 0;
  sort(seg.begin(), seg.end());
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans += seg[j].fi < seg[i].se && seg[i].se < seg[j].se;
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}