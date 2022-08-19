// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
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

int n;
int a[maxn][maxn], g[maxn][maxn];
int chs[maxn], cnt[maxn], par[10005];
vi idx[maxn];

int getPar(int x) {
  if (par[x] == x)
    return x;
  else {
    par[x] = getPar(par[x]);
    return par[x];
  }
}
void merge(int u, int v) {
  u = getPar(u);
  v = getPar(v);
  par[u] = v;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < 2 * n; i++)
    for (int j = 0; j < 2 * n; j++) {
      g[i][j] = 0;
      if (i == j)
        continue;
      for (int k = 0; k < n; k++)
        g[i][j] |= a[i][k] == a[j][k];
    }
  for (int i = 0; i < 2 * n; i++)
    chs[i] = 0;
  while (true) {
    bool del = false;
    for (int j = 0; j < n; j++) {
      for (int i = 1; i <= n; i++)
        cnt[i] = 0;
      for (int i = 0; i < 2 * n; i++)
        if (chs[i] == 0) {
          cnt[a[i][j]]++;
        }
      auto force_choose = [&](int x) {
        chs[x] = 1;
        for (int i = 0; i < 2 * n; i++)
          if (g[i][x] == 1) {
            assert(chs[i] != 1);
            chs[i] = -1;
          }
      };
      for (int i = 1; i <= n; i++)
        if (cnt[i] == 1) {
          for (int k = 0; k < 2 * n; k++)
            if (chs[k] == 0 && a[k][j] == i) {
              force_choose(k);
              del = 1;
              goto found;
            }
        }
    }
  found:
    if (!del)
      break;
  }
  for (int i = 0; i < 4 * n; i++)
    par[i] = i;
  for (int j = 0; j < n; j++) {
    for (int i = 1; i <= n; i++)
      idx[i].clear();
    for (int i = 0; i < 2 * n; i++)
      if (chs[i] == 0) {
        idx[a[i][j]].pb(i);
      }
    for (int i = 1; i <= n; i++) {
      assert(idx[i].size() == 0 || idx[i].size() == 2);
      if (idx[i].size() == 2) {
        int u = idx[i][0], v = idx[i][1];
        merge(2 * u, 2 * v + 1);
        merge(2 * v, 2 * u + 1);
      }
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    assert(getPar(2 * i) != getPar(2 * i + 1));
  }
  int ans = 1;
  for (int i = 0; i < 2 * n; i++)
    if (chs[i] == 0) {
      int f1 = getPar(2 * i), f2 = getPar(2 * i + 1);
      ans = ans * 2 % mod;
      for (int j = 0; j < 2 * n; j++) {
        if (getPar(2 * j) == f1)
          chs[j] = 1;
        if (getPar(2 * j) == f2)
          chs[j] = -1;
      }
    }
  printf("%d\n", ans);
  for (int i = 0; i < 2 * n; i++)
    if (chs[i] == 1)
      printf("%d ", i + 1);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}