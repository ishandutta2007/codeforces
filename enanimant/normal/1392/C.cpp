// August 16, 2020
// 

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i > 0 && a[i - 1] > a[i]) {
        ans += a[i - 1] - a[i];
      }
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}