#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> deg(n);
  bool flag = true;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    if (u == n)
      swap(u, v);
    if (v != n || u == n)
      flag = false;
    u--, v--;
    deg[u]++;
  }
  if (!flag) {
    cout << "NO\n";
    return 0;
  }
  vector <int> unused;
  for (int v = 0; v + 1 < n; v++)
    if (!deg[v])
      unused.push_back(v);
  reverse(unused.begin(), unused.end());
  vector <pair <int, int>> e;
  for (int i = 0; i < n; i++) {
    if (!deg[i])
      continue;
    deg[i]--;
    if (deg[i] && (unused.size() < deg[i] || unused[unused.size() - deg[i]] > i)) {
      cout << "NO\n";
      return 0;
    }
    int last = n - 1;
    while (deg[i]--) {
      e.push_back({unused.back(), last});
      last = unused.back();
      unused.pop_back();
    }
    e.push_back({i, last});
  }
  cout << "YES\n";
  for (auto [u, v] : e)
    cout << u + 1 << ' ' << v + 1 << '\n';
  return 0;
}