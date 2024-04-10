#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll ans = 0;
  sort(a.begin(), a.end());
  for (int x : a) {
    int low = l - x, high = r - x;
    ans += upper_bound(a.begin(), a.end(), high) - lower_bound(a.begin(), a.end(), low);
    if (l <= x + x && x + x <= r) --ans;
  }
  cout << ans / 2 << '\n';
  }
}