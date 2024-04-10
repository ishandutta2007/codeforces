#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct tarjan_t {
  int n;
  vector<vector<int>> adj;
  vector<int> preorder, inv_preorder;
  stack<int> active;
  vector<bool> is_active;
  vector<int> cnt_of;
  vector<vector<int>> cnts;
  tarjan_t(int _n)
    : n(_n)
    , adj(n)
    , inv_preorder(n, -1)
    , is_active(n, false)
    , cnt_of(n, -1) {}
  int dfs(int v) {
    inv_preorder[v] = preorder.size();
    preorder.push_back(v);
    active.push(v);
    is_active[v] = true;
    int first = inv_preorder[v];
    for (int u : adj[v]) {
      if (inv_preorder[u] == -1)
        first = min(first, dfs(u));
      else if (is_active[u])
        first = min(first, inv_preorder[u]);
    }
    if (first == inv_preorder[v]) {
      int u;
      vector<int> cnt;
      do {
        u = active.top();
        active.pop();
        is_active[u] = false;
        cnt_of[u] = cnts.size();
        cnt.push_back(u);
      } while (u != v);
      cnts.push_back(move(cnt));
    }
    return first;
  }
  void solve() {
    for (int i = 0; i < n; ++i)
      if (inv_preorder[i] == -1)
        dfs(i);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> field(n);
  vector<vector<int>> id(n, vector<int>(m, -1));

  int g_n = 0;

  for (int y = 0; y < n; ++y) {
    cin >> field[y];
    for (int x = 0; x < m; ++x) {
      if (field[y][x] == '#') {
        id[y][x] = g_n;
        ++g_n;
      }
    }
  }

  tarjan_t tj(g_n);

  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x) {
      if (id[y][x] == -1) continue;

      for (int y2 = y; y2 == y || (y2 < n && id[y2][x] == -1); ++y2) {
        for (int dir = 0; dir < 4; ++dir) {
          int y3 = y2 + dy[dir];
          int x3 = x + dx[dir];

          if (0 <= y3 && y3 < n && 0 <= x3 && x3 < m && id[y3][x3] != -1) {
            if (id[y3][x3] != id[y][x]) {
              tj.adj[id[y][x]].push_back(id[y3][x3]);
            }
          }
        }
      }
    }

  tj.solve();

  vector<bool> need(tj.cnts.size(), true);
  for (int v = 0; v < tj.n; ++v)
    for (int u : tj.adj[v])
      if (tj.cnt_of[v] != tj.cnt_of[u])
        need[tj.cnt_of[u]] = false;

  int result = 0;
  for (int c = 0; c < (int)need.size(); ++c)
    if (need[c])
      result += 1;
  printf("%d\n", result);

  return 0;
}