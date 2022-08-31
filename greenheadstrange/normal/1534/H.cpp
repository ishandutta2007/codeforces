// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
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

int n, dp1[maxn], dp2[maxn], root[maxn], pre[maxn], suf[maxn], ans, qry[maxn];
vi adj[maxn], son[maxn];

void dfs1(int u, int f) {
  son[u].clear();
  vector<int> ord;
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    dfs1(v, u);
    son[u].pb(v);
    ord.pb(max(dp1[v], 1));
  }
  sort(son[u].begin(), son[u].end(),
       [&](int x, int y) { return dp1[x] > dp1[y]; });
  sort(ord.begin(), ord.end());
  reverse(ord.begin(), ord.end());
  dp1[u] = 0;
  for (int i = 0; i < ord.size(); i++)
    dp1[u] = max(dp1[u], ord[i] + i);
  if (son[u].empty())
    qry[u] = u;
  else
    qry[u] = qry[son[u][0]];
}

void dfs2(int u, int f) {
  vector<array<int, 2>> ord;
  if (f != 0) {
    ord.pb({max(dp2[u], 1), f});
  }
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    ord.pb({max(dp1[v], 1), v});
  }
  sort(ord.begin(), ord.end());
  reverse(ord.begin(), ord.end());
  pre[0] = 0;
  int m = ord.size();
  for (int i = 0; i < m; i++)
    pre[i + 1] = max(pre[i], ord[i][0] + i);
  suf[m] = 0;
  for (int i = m - 1; i >= 0; i--)
    suf[i] = max(suf[i + 1], ord[i][0] + i);
  if (m >= 2) {
    ans = max(ans, suf[1] - 1 + ord[0][0]);
  } else if (m == 1) {
    ans = max(ans, pre[m]);
  }
  for (int i = 0; i < m; i++) {
    if (ord[i][1] == f)
      continue;
    int v = ord[i][1];
    dp2[v] = max(pre[i], suf[i + 1] - 1);
  }
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    dfs2(v, u);
  }
}

int cc = 0;
int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int y;
  scanf("%d", &y);
  return y;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs1(1, 0);
  dp2[1] = -1;
  dfs2(1, 0);
  printf("%d\n", ans);
  fflush(stdout);
  int f;
  scanf("%d", &f);
  dfs1(f, 0);
  vi ver;
  for (auto p : son[f]) {
    int x = query(qry[p]);
    if (x == f)
      continue;
    while (true) {
      bool c = false;
      for (int j = 1; j < son[x].size(); j++) {
        int v = son[x][j];
        int y = query(qry[v]);
        if (y != x) {
          c = true;
          x = y;
          break;
        }
      }
      if (!c)
        break;
    }
    ver.pb(x);
    if (ver.size() == 2)
      break;
  }
  while (ver.size() < 2)
    ver.pb(f);
  printf("! %d %d\n", ver[0], ver[1]);
  fflush(stdout);
}