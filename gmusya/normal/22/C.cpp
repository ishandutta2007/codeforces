#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, v;
  cin >> n >> m >> v;
  if (m < n - 1) {
    cout << -1;
    return 0;
  }
  vector <pair <int, int>> ans;
  for (int i = 1; i <= n; i++) {
    if (i == v) continue;
    ans.push_back({i, v});
  }
  m -= n - 1;
  vector <int> comp;
  for (int i = 1; i <= n; i++) {
    if (i == v) continue;
    if (comp.size() + 2 < n)
      comp.push_back(i);
  }
  for (int i = 0; i < (int)comp.size(); i++)
    for (int j = i + 1; j < (int)comp.size() && m > 0; j++, m--)
      ans.push_back({comp[i], comp[j]});
  if (m > 0) {
    cout << -1;
    return 0;
  }
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << '\n';
  return 0;
}