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
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];
int dp[N][2];
int who[N];
int par[N];
int n;

void dfs(int u, int p) {
  par[u] = p;
  vector <pair <int, int>> have;
  int sum = 0;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sum += dp[v][1];
      have.push_back({dp[v][0] - dp[v][1], v});
    }
  }
  dp[u][0] = sum;
  sort(have.begin(), have.end());
  if (have.size() > 0) {
    dp[u][1] = 1 + sum + have.back().first;
    who[u] = have.back().second;
  }
}

vector <pair <int, int>> mt;

void go(int u, int tp, int p) {
  if (tp == 1) {
    assert(who[u] != -1);
    mt.push_back({u, who[u]});
    for (auto v : g[u]) {
      if (v != p) {
        if (v == who[u]) {
          go(v, 0, u);
        } else {
          if (dp[v][0] >= dp[v][1]) {
            go(v, 0, u);
          } else {
            go(v, 1, u);
          }
        }
      }
    }
  } else {
    for (auto v : g[u]) {
      if (v != p) {
        if (dp[v][0] >= dp[v][1]) {
          go(v, 0, u);
        } else {
          go(v, 1, u);
        }
      }
    }
  }   
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; ++i) who[i] = -1;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  int cnt = dp[0][1];
  int ans = 2 * cnt + (n - 2 * cnt) * 2; 
  cout << ans << '\n';
  vector <int> used(n);
  go(0, 1, -1);

  for (auto p : mt) {
    used[p.first] = used[p.second] = 1;
  }
  vector <vector <int>> gs(n);
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      gs[par[i]].push_back(i);
    }
  }
  for (auto p : mt) {
    assert(gs[p.first].empty() || gs[p.second].empty());
    if (!gs[p.first].empty()) {
      gs[p.first].push_back(p.second);
    } else {
      gs[p.second].push_back(p.first);
    }
  }
  vector <int> go(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!gs[i].empty()) {
      go[i] = gs[i][0];
      for (int j = 0; j + 1 < (int)gs[i].size(); ++j) {
        go[gs[i][j]] = gs[i][j + 1];
      }
      go[gs[i].back()] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << go[i] + 1 << ' ';
  }
  cout << '\n';
}