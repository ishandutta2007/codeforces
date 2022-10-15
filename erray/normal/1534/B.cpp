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
    a.insert(a.begin(), 0);
    a.push_back(0);
    n += 2;

    long long ans = 0;
    for (int i = 1; i < n; ++i) {
      ans += abs(a[i] - a[i - 1]);
      if (i != n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]) {
        ans -= a[i] - max((i == 0 ? 0 : a[i - 1]), a[i + 1]);
      }
    }
    cout << ans << '\n';
  }
}