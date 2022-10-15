// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n > 64) {
    return cout << 1, 0;
  }
  int ans = n;
  for (int i = 0; i < n - 1; ++i) {
    int cur = 0;
    for (int j = i; j >= 0; --j) {
      cur ^= a[j];
      int cur2 = 0;
      for (int q = i + 1; q < n; ++q) {
        cur2 ^= a[q];
        if (cur2 < cur) {
          ans = min(ans, q - i - 1 + i - j);
        }
      }
    }
  }  


  cout << (ans == n ? -1 : ans) << '\n';

}