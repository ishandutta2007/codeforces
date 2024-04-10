// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> pref(n, vector<int>(3000 + 1));
    for (int i = 0; i < n; ++i) {
      pref[i] = (pref[i - (i > 0)]);
      ++pref[i][a[i]];
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] == a[j]) continue;
        ans += 1LL * (pref.back()[a[i]] - pref[j - 1][a[i]]) * (pref[i][a[j]]);
      }
    }
    for (int i = 0; i <= 3000; ++i) {
      int val = pref.back()[i];
      ans += 1LL * val * (val - 1) * (val - 2) * (val - 3) / 24;
    }
    cout << ans << '\n';
  }
}