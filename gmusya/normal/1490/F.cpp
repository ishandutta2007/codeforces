#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <int> b;
    {
      map <int, int> m;
      for (int i = 0; i < n; i++)
        m[a[i]]++;
      for (auto &now : m)
        b.push_back(now.second);
    }
    int m = b.size();
    sort(b.begin(), b.end());
    vector <int> pre(m);
    pre[0] = b[0];
    for (int i = 1; i < m; i++)
      pre[i] = pre[i - 1] + b[i];
    int ans = n;
    for (int i = 0; i < m; i++) {
      int ost = n - (i ? pre[i - 1] : 0);
      int todel = (n - ost) + ost - (m - i) * b[i];
      ans = min(ans, todel);
    }
    cout << ans << '\n';
  }
  return 0;
}