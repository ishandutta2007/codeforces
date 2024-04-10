#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    vector <pair <int, int>> c(n + m);
    for (int i = 0; i < n; i++)
      c[i] = {a[i], 0};
    for (int i = 0; i < m; i++)
      c[i + n] = {b[i], 1};
    sort(c.begin(), c.end());
    int value = -1;
    for (int i = 0; i + 1 < n + m; i++)
      if (c[i].first == c[i + 1].first && c[i].second != c[i + 1].second)
        value = c[i].first;
    if (value == -1) cout << "NO\n";
    else cout << "YES\n" << 1 << ' ' << value << '\n';
  }
  return 0;
}