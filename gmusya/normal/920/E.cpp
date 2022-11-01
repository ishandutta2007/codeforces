#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;
set <pii> e;
set <int> unused;

int cnt;

void dfs(int v) {
  cnt++;
  vector <int> c;
  for (int u : unused)
    if (e.find({u, v}) == e.end())
      c.push_back(u);
  for (int u : c)
    unused.erase(u);
  for (int u : c)
    dfs(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    unused.insert(i);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e.insert({u, v});
    e.insert({v, u});
  }
  vector <int> ans;
  for (int i = 0; i < n; i++) {
    if (unused.find(i) == unused.end())
      continue;
    cnt = 0;
    unused.erase(i);
    dfs(i);
    ans.push_back(cnt);
  }
  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}