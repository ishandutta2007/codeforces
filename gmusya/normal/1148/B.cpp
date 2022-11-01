#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector <int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  if (k >= n) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++)
    a[i] += ta;
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    pos += (k - i);
    if (pos >= m) {
      cout << -1;
      return 0;
    }
    ans = max(ans, b[pos]);
  }
  cout << ans + tb;
  return 0;
}