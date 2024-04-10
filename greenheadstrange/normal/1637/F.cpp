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

ll s[maxn];
int maxh[maxn], h[maxn];
int n, r;
vector<int> e[maxn];
void dfs(int u, int par) {
  s[u] = 0;
  for (auto v : e[u])
    if (v != par) {
      dfs(v, u);
      s[u] += s[v];
      maxh[u] = max(maxh[u], maxh[v]);
    }
  if (u != r) s[u] += max(h[u] - maxh[u], 0);
  maxh[u] = max(maxh[u], h[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  r = max_element(h + 1, h + n + 1) - h;
  dfs(r, 0);
  vector<int> z;
  z.push_back(0);
  for (auto v : e[r]) z.push_back(maxh[v]);
  sort(z.begin(), z.end());
  reverse(z.begin(), z.end());
  ll ans = s[r] + h[r] - z[0] + h[r] - z[1];
  ;
  printf("%lld\n", ans);
}