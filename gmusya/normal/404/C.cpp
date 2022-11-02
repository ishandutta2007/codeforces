#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <vector <int>> d(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d[x].push_back(i);
  }
  if (d[0].size() != 1) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i + 1 < n; i++)
    if (d[i].empty() && !d[i + 1].empty()) {
      cout << -1;
      return 0;
    }
  vector <pair <int, int>> e;
  for (int i = 0; i + 1 < n; i++) {
    vector <int> a = d[i], b = d[i + 1];
    while (!a.empty()) {
      int u = a.back();
      int _k = (i ? k - 1 : k);
      while (!b.empty() && _k--) {
        e.push_back({u, b.back()});
        b.pop_back();
      }
      a.pop_back();
    }
    if (!b.empty()) {
      cout << -1;
      return 0;
    }
  }
  cout << n - 1 << '\n';
  for (auto &now : e)
    cout << now.first + 1 << ' ' << now.second + 1 << '\n';
  return 0;
}