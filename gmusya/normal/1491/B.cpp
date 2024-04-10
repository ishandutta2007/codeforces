#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    bool flag = false;
    for (int i = 0; i + 1 < n; i++)
      if (abs(a[i] - a[i + 1]) > 1)
        flag = true;
    if (flag) {
      cout << 0 << '\n';
      continue;
    }
    flag = false;
    for (int i = 0; i + 1 < n; i++)
      if (a[i] != a[i + 1])
        flag = true;
    if (!flag)
      cout << v + min(u, v) << '\n';
    else
      cout << min(u, v) << '\n';
  }
  return 0;
}