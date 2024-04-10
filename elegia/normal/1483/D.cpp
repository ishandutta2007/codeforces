/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
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

const int N = 610;

int e[N][N], g[N][N], f[N][N], h[N][N];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    fill(g[i] + 1, g[i] + n + 1, int(1e9) + 1);
    g[i][i] = 0;
  }
  while (m--) {
    int u, v; cin >> u >> v; cin >> e[u][v];
    g[u][v] = g[v][u] = e[u][v];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v; cin >> f[u][v];
    f[v][u] = f[u][v];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        h[i][k] = max(h[i][k], f[j][k] - g[i][j]);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (e[i][j]) {
        int mx = 0;
        for (int k = 1; k <= n; ++k) mx = max(mx, h[i][k] - g[k][j]);
        if (e[i][j] <= mx) {
          ++ans;
        }
      }
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}