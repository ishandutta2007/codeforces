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
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int x : a) {
      if (l <= 2 * x && 2 * x <= r) {
        ans--;
      }
      ans += upper_bound(a.begin(), a.end(), r - x) - lower_bound(a.begin(), a.end(), l - x);
    }
    cout << ans / 2 << '\n';
  }
  return 0;
}