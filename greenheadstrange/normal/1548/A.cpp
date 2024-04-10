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

int n, m, q;
set<int> e[maxn];
bool alive[maxn];
int main() {
  scanf("%d%d", &n, &m);
  int ans = n;
  auto add = [&](int u, int v) {
    ans -= alive[u] + alive[v];
    e[u].insert(v);
    e[v].insert(u);
    alive[u] = e[u].empty() ? 1 : (u > *e[u].rbegin());
    alive[v] = e[v].empty() ? 1 : (v > *e[v].rbegin());
    ans += alive[u] + alive[v];
  };
  auto del = [&](int u, int v) {
    ans -= alive[u] + alive[v];
    e[u].erase(v);
    e[v].erase(u);
    alive[u] = e[u].empty() ? 1 : (u > *e[u].rbegin());
    alive[v] = e[v].empty() ? 1 : (v > *e[v].rbegin());
    ans += alive[u] + alive[v];
  };
  for (int i = 1; i <= n; i++)
    alive[i] = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
    } else if (x == 2) {
      int u, v;
      scanf("%d%d", &u, &v);
      del(u, v);
    } else {
      printf("%d\n", ans);
    }
  }
}