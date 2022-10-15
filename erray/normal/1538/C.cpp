// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int left = int(lower_bound(a.begin(), a.begin() + i, l - a[i]) - a.begin());
      int right = int(lower_bound(a.begin(), a.begin() + i, r - a[i] + 1) - a.begin());
      ans += max(0, right - left);
    }
    cout << ans << '\n';
  }
}