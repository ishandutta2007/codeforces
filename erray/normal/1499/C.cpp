// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<long long> pref(2);
    vector<int> ct(2);
    vector<int> mn(2, INT_MAX);

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
      ++ct[i % 2];
      pref[i % 2] += a[i];
      mn[i % 2] = min(mn[i % 2], a[i]);
      long long cur = 0;
      for (int j = 0; j < 2; ++j) {
        cur += pref[j] + 1LL * mn[j] * (n - ct[j]);
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}