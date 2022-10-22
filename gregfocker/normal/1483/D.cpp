#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 600 + 7;
const int INF = (int) 1e18;
int n, m, d[N][N], val[N][N];
bool ok[N][N], ed[N][N];

struct T {
  int to;
  int l;
};

vector<T> v[N];
int junc[N][N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    ed[x][y] = ed[y][x] = 1;
    val[x][y] = val[y][x] = z;
    d[x][y] = min(d[x][y], z); swap(x, y);
    d[x][y] = min(d[x][y], z); swap(x, y);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, y, l;
    cin >> x >> y >> l;
    v[x].push_back({y, l});
    v[y].push_back({x, l});
  }
  for (int y = 1; y <= n; y++) {
    for (int a = 1; a <= n; a++) {
      junc[y][a] = -INF;
      for (auto &it : v[a]) {
        junc[y][a] = max(junc[y][a], it.l - d[it.to][y]);
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (!ed[x][y]) continue;
      for (int a = 1; a <= n; a++) {
        int add = val[x][y] + d[a][x], mx = -INF;
        if (add <= junc[y][a]) {
          ok[x][y] = 1;
          break;
        }
      }

    }
  }
  int ret = 0;
  for (int x = 1; x <= n; x++) for (int y = 1; y < x; y++) if (ed[x][y]) {
    if (ok[x][y] || ok[y][x]) {
   //   cout << " : " << x << " " << y << "\n";
      ret++;
    }
  }

  cout << ret << "\n";
}