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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      int mx = a[i], mn = a[i + 1];
      if (mx < mn) {
        swap(mx, mn);
      }

      while (mn * 2 < mx) {
        ++ans;
        mn *= 2;
      }
    }

    cout << ans << '\n';
  }
}