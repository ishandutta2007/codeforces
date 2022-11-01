#include <iostream>
#include <vector>
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
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    int m;
    cin >> m;
    vector <int> b(m + 1);
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
      b[i] += b[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
        ans = max(ans, a[i] + b[j]);
    cout << ans << '\n';
  }
  return 0;
}