// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    sum /= n;
    int ans = 0;
    for (auto e : a) {
      ans += e > sum;
    }
    cout << ans << '\n';
  }
}