// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    bool ok = false;
    for (int i = 0; i < n - 1; ++i) {
      ok |= (abs(a[i + 1] - a[i]) > 1);
    }

    int ans = 0;
    if (!ok) {
      if (count(a.begin(), a.end(), a[0]) == n) {
        ans = v + min(u, v);
      } else {
        ans = min(u, v);
      }
    }

    cout << ans << '\n';
  }
}