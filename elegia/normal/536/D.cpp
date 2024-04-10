#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 2010;

int n, s, t;
int val[N];
int g[N][N];
int vs[N], vt[N];
ll ds[N], dt[N];
ll x[N][N], y[N][N];
bool vx[N][N], vy[N][N];
pair<int, ll> tx[N][N], ty[N][N];

void work(int s, ll dist[], int vertex[]) {
  static bool vis[N];
  fill(vis + 1, vis + n + 1, false);
  fill(dist + 1, dist + n + 1, -1LL);
  dist[s] = 0;
  for (int rep = 1; rep <= n; ++rep) {
    int u = 1;
    for (int i = 2; i <= n; ++i)
      if (!vis[i] && dist[i] != -1 && (vis[u] || dist[u] == -1 || dist[u] > dist[i]))
        u = i;
    vertex[rep] = u;
    vis[u] = true;
    for (int v = 1; v <= n; ++v)
      if (g[u][v] != -1 && (dist[v] == -1 || dist[v] > dist[u] + g[u][v]))
        dist[v] = dist[u] + g[u][v];
  }
}

typedef pair<int, ll> Arr[N][N];

void work2(ll dist[], int vertex[], int vertex2[], Arr trans) {
  static bool vis[N];
  fill(vis + 1, vis + n + 1, false);
  for (int i = 0; i <= n; ++i) {
    if (i) vis[vertex2[i]] = true;
    int p = 0;
    ll sum = 0;
    int cnt = 0;
    for (int j = 0; j <= n; ++j) {
      if (j && !vis[vertex[j]]) {
        sum -= val[vertex[j]];
        --cnt;
      }
      if (!cnt) {
        ++p;
        while (p <= n && vis[vertex[p]]) ++p;
        ++cnt; sum += val[vertex[p]];
        while (p < n && dist[vertex[p + 1]] == dist[vertex[p]])
          if (!vis[vertex[++p]]) {
            ++cnt; sum += val[vertex[p]];
          }
      }
      trans[i][j] = make_pair(p, sum);
    }
  }
}

ll dfsx(int i, int j);
ll dfsy(int i, int j);

ll dfsx(int i, int j) {
  if (vx[i][j]) return x[i][j];
  vx[i][j] = true;
  if (tx[i][j].first > n) return x[i][j] = 0;
  return x[i][j] = tx[i][j].second + max(dfsx(tx[i][j].first, j), -dfsy(tx[i][j].first, j));
}

ll dfsy(int i, int j) {
  if (vy[i][j]) return y[i][j];
  vy[i][j] = true;
  if (ty[i][j].first > n) return y[i][j] = 0;
  return y[i][j] = ty[i][j].second + max(-dfsx(i, ty[i][j].first), dfsy(i, ty[i][j].first));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; ++i)
    cin >> val[i];
  for (int i = 1; i <= n; ++i)
    fill(g[i] + 1, g[i] + n + 1, -1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (g[u][v] == -1 || g[u][v] > w)
      g[u][v] = g[v][u] = w;
  }
  work(s, ds, vs);
  work(t, dt, vt);
  work2(ds, vs, vt, tx);
  work2(dt, vt, vs, ty);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < i; ++j)
      swap(tx[i][j], tx[j][i]);
  ll ans = dfsx(0, 0);
  cout << (ans > 0 ? "Break a heart" : ans < 0 ? "Cry" : "Flowers");

  return 0;
}