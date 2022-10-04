#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

const int N = 3007;

vector <int> g[N];

int timer = 0;
int tin[N], tout[N];
int sz[N];
int h[N];
int dist[N][N];
int prec[N][N];

void dfs(int u, int p = 0) {
  tin[u] = timer++;
  sz[u] = 1;
  h[u] = h[p] + 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
  tout[u] = timer++;
}

vector <int> pt; 

int n;

void zhfs(int u, int p = 0) {
  pt.push_back(u);
  for (int i = 0; i + 1 < (int)pt.size(); ++i) {
    prec[u][pt[i]] = sz[u] * (n - sz[pt[i + 1]]);
    prec[pt[i]][u] = sz[u] * (n - sz[pt[i + 1]]);
  }
  for (auto v : g[u]) {
    if (v != p) {
      zhfs(v, u);
    }
  }
  pt.pop_back();
}

void jhfs(int st, int u, int d, int p) {
  dist[st][u] = d;
  for (auto v : g[u]) {
    if (v != p) {
      jhfs(st, v, d + 1, u);
    }
  }
} 

bool on_path(int a, int b, int c) {
  return dist[a][b] == dist[a][c] + dist[c][b];
}

bool anc(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

ll dp[N][N];
vector <int> who[N][N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif  
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    jhfs(i, i, 0, -1);
  }
  zhfs(0, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!anc(i, j) && !anc(j, i)) {
        prec[i][j] = prec[j][i] = sz[i] * sz[j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      who[dist[i][j]][i].push_back(j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      dp[i][j] = prec[i][j]; 
    }
  }
  for (int l = 1; l < n - 1; ++l) {
    for (int i = 0; i < n; ++i) {
      for (int j : who[l][i]) {
        for (int ni : g[i]) {
          if (on_path(i, j, ni)) continue;
          dp[ni][j] = max(dp[ni][j], dp[i][j] + prec[ni][j]);
          dp[j][ni] = max(dp[j][ni], dp[i][j] + prec[ni][j]);
        }
        for (int nj : g[j]) {
          if (on_path(i, j, nj)) continue;
          dp[nj][i] = max(dp[nj][i], dp[i][j] + prec[nj][i]);
          dp[i][nj] = max(dp[i][nj], dp[i][j] + prec[nj][i]);
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}