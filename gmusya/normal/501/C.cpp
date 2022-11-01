#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> deg(n), x(n);
  for (int v = 0; v < n; v++)
    cin >> deg[v] >> x[v];
  vector <pair <int, int>> ans;
  queue <int> q;
  for (int v = 0; v < n; v++)
    if (deg[v] == 1)
      q.push(v);
  while (!q.empty()) {
    int v = q.front();
    int u = x[v];
    q.pop();
    if (deg[v] < 1) continue;
    ans.push_back({u, v});
    deg[v]--, deg[u]--;
    x[u] ^= v, x[v] ^= u;
    if (deg[u] == 1)
      q.push(u);
  }
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << '\n';
  return 0;
}