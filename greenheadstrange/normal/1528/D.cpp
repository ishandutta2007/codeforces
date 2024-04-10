// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 605 /*rem*/
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

int n, m, dt[maxn][maxn];
bool vis[maxn];
ll dis[maxn];
vector<pi> e[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    e[a].pb({b, c});
  }
  for (int i = 0; i < n; i++)
    for (int t = 0; t < n; t++) {
      dt[i][t] = 2000000000;
      for (auto p : e[i]) {
        if (p.fi <= t)
          dt[i][t] = min(dt[i][t], p.se + t - p.fi);
        else
          dt[i][t] = min(dt[i][t], p.se + t + n - p.fi);
      }
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      vis[j] = false, dis[j] = 1ll << 60;
    vis[i] = 0;
    dis[i] = 0;
    for (int j = 0; j < n; j++) {
      ll d = 1ll << 60, id = -1;
      for (int k = 0; k < n; k++)
        if (!vis[k] && dis[k] < d) {
          d = dis[k];
          id = k;
        }
      vis[id] = true;
      for (int k = 0; k < n; k++)
        if (!vis[k]) {
          int r = (k - dis[id]) % n;
          if (r < 0)
            r += n;
          dis[k] = min(dis[k], dis[id] + dt[id][r]);
        }
    }
    for (int k = 0; k < n; k++)
      printf("%lld ", dis[k]);
    printf("\n");
  }
}