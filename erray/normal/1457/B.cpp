// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    int ans = INT_MAX;
    for (int j = 0; j < 100; ++j) {
      int res = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == j) {
          continue;
        }
        ++res;
        i += k - 1;
      }
      ans = min(ans, res);
    }
    cout << ans << '\n';
  }
}