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
 
using namespace std;
 
typedef long long ll;
 
const int N = 5e5 + 7;
 
vector <int> g[N];
int ans[N];
int down[N], up[N];
int par[N];
 
void dfs(int u, int p) {
  par[u] = p;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      down[u] = max(down[u], down[v] + 1);
    }
  }
}
 
void jhfs(int u, int p) {
  int mx1 = -1e9, mx2 = -1e9;
  for (auto v : g[u]) {
    if (v == p) continue;
    int len = down[v];
    if (len > mx1) swap(mx1, len);
    if (len > mx2) swap(mx2, len);
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    up[v] = up[u] + 1;
    if (down[v] == mx1) up[v] = max(up[v], mx2 + 2);
    else up[v] = max(up[v], mx1 + 2);
    jhfs(v, u);
  }
}
 
pair <int, int> best;
 
void dfsD(int u, int d, int p) {
  best = max(best, {d, u});
  for (auto v : g[u]) {
      if (v != p) {
          dfsD(v, d + 1, u);
      }
  }
}
 
int getDiam() {
  best = {-1, 0};
  dfsD(0, 0, -1);
  int u = best.second;
  best = {-1, 0};
  dfsD(u, 0, -1);
  return best.first;
}
 
vector <int> go[N];
 
void zhfs(int u, int p) {
  for (auto v : g[u]) {
    if (v != p) {
      go[u].push_back(down[v] + 1);
    }
  }
  sort(go[u].begin(), go[u].end());
  for (auto v : g[u]) {
    if (v != p) {
      zhfs(v, u);
    }
  }
}
 
int get(int u, int x) {
  int v = par[u];
  int cnt = 0;
  if (up[v] >= x) ++cnt;
  cnt += go[u].end() - lower_bound(go[u].begin(), go[u].end(), x);
  cnt += go[v].end() - lower_bound(go[v].begin(), go[v].end(), x);
  if (down[u] + 1 >= x) --cnt;
  return cnt;
}
  
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  jhfs(0, -1);
  zhfs(0, -1);
  for (int i = 1; i <= n; ++i) ans[i] = 1;
  for (int i = 0; i < n; ++i) ans[1] = max(ans[1], 1 + (int)g[i].size());
  int l = getDiam();
  for (int i = 1; i <= l; ++i) ans[i] = max(ans[i], 2);
  for (int i = 0; i < n; ++i) {
    vector <int> have;
    for (int j : g[i]) {
      if (j != par[i]) {
        have.push_back(down[j] + 1);
      }
    }
    sort(have.rbegin(), have.rend());
    if (i > 0 && have.size() > 1) {
      for (int x = have[1]; x >= 1; --x) {
        if (2 * x <= n) ans[2 * x] = max(ans[2 * x], get(i, x));
      }
    }
    have.push_back(up[i]);
    sort(have.rbegin(), have.rend()); 
    for (int j = 1; j < (int)have.size(); ++j) {
      if (have[j] == 0) continue;
      int x = 2 * have[j];
      ans[x] = max(ans[x], j + 1);
      x = 2 * have[j] - 1;
      ans[x] = max(ans[x], j + 1);
      x = 2 * (have[j] < have[j - 1] ? have[j] : have[j] - 1) + 1;
      ans[x] = max(ans[x], j + 1);
    }
  }
  for (int k = n; k >= 3; --k) {
    ans[k - 2] = max(ans[k - 2], ans[k]);
  }
  for (int k = 1; k <= n; ++k) {
    cout << ans[k] << ' ';
  }
}