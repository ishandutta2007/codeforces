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
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ans &= x;
    }
    cout << ans << '\n';
  }
}