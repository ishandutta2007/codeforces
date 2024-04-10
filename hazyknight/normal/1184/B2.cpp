#include <cstdio>
#include <cstring>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 1010, INF = 1e9 + 10;

int n, m, s, b, h, k;

int g[N][N], match[N];
int sx[N], a[N], f[N], bx[N], d[N];
bool g2[N][N], vis[N];

bool dfs(int u) {
  vis[u] = true;
  for (int v = 1; v <= b; ++v)
    if (g2[u][v] && (!match[v] || (!vis[match[v]] && dfs(match[v])))) {
      match[v] = u;
      return true;
    }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      g[i][j] = i == j ? 0 : INF;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u != v)
      g[u][v] = g[v][u] = 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
  scanf("%d%d%d%d", &s, &b, &k, &h);
  for (int i = 1; i <= s; ++i)
    scanf("%d%d%d", &sx[i], &a[i], &f[i]);
  for (int i = 1; i <= b; ++i)
    scanf("%d%d", &bx[i], &d[i]);
  for (int i = 1; i <= s; ++i)
    for (int j = 1; j <= b; ++j) {
      g2[i][j] = (a[i] >= d[j]) && (f[i] >= g[sx[i]][bx[j]]);
    }
  int maxmatch = 0;
  for (int i = 1; i <= s; ++i) {
    memset(vis, 0, sizeof(vis));
    maxmatch += dfs(i);
  }
  ll ans = maxmatch * (ll)k;
  for (int i = 0; i < maxmatch; ++i)
    ans = min(ans, (s - i) * (ll)h + i * (ll)k);
  printf("%lld\n", ans);
  return 0;
}