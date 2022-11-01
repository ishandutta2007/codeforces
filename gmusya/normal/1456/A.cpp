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
    int n, p, k;
    cin >> n >> p >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = (1 - (c - '0'));
    }
    int x, y;
    cin >> x >> y;
    int ans = 2e9;
    for (int i = n - k - 1; i >= 0; i--)
      a[i] += a[i + k];
    for (int i = p - 1; i < n; i++)
      ans = min(ans, x * a[i] + y * (i - p + 1));
    cout << ans << '\n';
  }
  return 0;
}