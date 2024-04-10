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

const int N = 2e5 + 7;

int par[N];
int h[N];
vector <int> g[N];
int sz[N];
int cnt[N];

void dfs(int u, int p) {
  par[u] = p;
  for (auto v : g[u]) {
    if (v != p) {
      ++sz[u];
      h[v] = h[u] + 1;
      dfs(v, u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  set <pair <int, int>> have;
  for (int i = 0; i < n; ++i) {
    if (sz[i] == 0) have.insert({h[i], i});
  }
  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    auto p = *have.rbegin();
    have.erase(--have.end());
    ans += p.first;
    int u = p.second;
    if (par[u] != -1) {
      have.erase({h[par[u]] - cnt[par[u]], par[u]});
      cnt[par[u]] += cnt[u] + 1;
      --sz[par[u]];
      if (sz[par[u]] == 0) have.insert({h[par[u]] - cnt[par[u]], par[u]});
    }
  }
  cout << ans << '\n';
}