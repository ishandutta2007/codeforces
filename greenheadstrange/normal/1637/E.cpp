// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
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

int n, m, a[maxn], val[maxn], hate[maxn];
vector<int> num[maxn], e[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  map<int, int> cnt, id;
  for (int i = 1; i <= n; i++) num[i].clear();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  int k = 0;
  for (auto p : cnt) {
    id[p.fi] = ++k;
    val[k] = p.fi;
    num[p.se].push_back(k);
  }
  for (int i = 1; i <= k; i++) {
    e[i].clear();
    e[i].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = id[u];
    v = id[v];
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<int> pocr;
  for (int i = 1; i <= n; i++)
    if (!num[i].empty()) {
      pocr.push_back(i);
      reverse(num[i].begin(), num[i].end());
    }
  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    int u = val[i], cntu = cnt[u];
    for (auto v : e[i]) hate[v] = 1;
    for (auto cntv : pocr) {
      for (auto v : num[cntv]) {
        if (hate[v]) continue;
        ans = max(ans, 1ll * (u + val[v]) * (cntu + cntv));
        break;
      }
    }
    for (auto v : e[i]) hate[v] = 0;
  }
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}