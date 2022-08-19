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

int n, m, par[maxn], sz[maxn], extra;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
  function<int(int)> findpar = [&](int u) {
    if (par[u] == u)
      return u;
    else {
      par[u] = findpar(par[u]);
      return par[u];
    }
  };
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = findpar(u);
    v = findpar(v);
    if (u == v)
      extra++;
    else {
      par[u] = v;
      sz[v] += sz[u];
    }
    vi szs;
    for (int j = 1; j <= n; j++)
      if (findpar(j) == j) {
        szs.pb(sz[j]);
      }
    sort(szs.rbegin(), szs.rend());
    int ans = 0;
    for (int i = 0; i <= extra && i < szs.size(); i++) ans += szs[i];
    printf("%d\n", ans - 1);
  }
}