#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <vector <int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <int> roots;
  for (int v = 0; v < n; v++)
    if (g[v].size() > 2)
      roots.push_back(v);
  if (roots.size() > 1) {
    cout << "No\n";
    return 0;
  }
  int root;
  if (roots.empty())
    root = 0;
  else
    root = roots[0];
  vector <pair <int, int>> ans;
  for (int v = 0; v < n; v++)
    if (v != root && g[v].size() == 1)
      ans.push_back({root + 1, v + 1});
  cout << "Yes\n";
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << '\n';
  return 0;
}