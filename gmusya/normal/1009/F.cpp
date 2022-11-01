#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int d[1000000];
int ans[1000000];
vi g[1000000];
map <int, int> cnt[1000000];
set <pair <int, int>> res[1000000];

void dfs(int v, int p = -1) {
  cnt[v][d[v]]--;
  res[v].insert({cnt[v][d[v]], d[v]});
  for (int u : g[v])
    if (u != p) {
      d[u] = d[v] + 1;
      dfs(u, v);
      if (cnt[v].size() < cnt[u].size()) {
        swap(cnt[u], cnt[v]);
        swap(res[u], res[v]);
      }
      for (auto &now : cnt[u]) {
        int dep = now.first, val = now.second;
        if (cnt[v].find(dep) != cnt[v].end())
          res[v].erase({cnt[v][dep], dep});
        cnt[v][dep] += val;
        res[v].insert({cnt[v][dep], dep});
      }
      res[u] = set <pair <int, int>> ();
      cnt[u] = map <int, int> ();
    }
  ans[v] = res[v].begin()->second - d[v];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; i++)
    cout << ans[i] << '\n';
  return 0;
}