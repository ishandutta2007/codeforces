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
    vector<int> ct(3);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++ct[x % 3];
    }

    int ans = 0;
    n /= 3;
    for (int d = 0; d < 3; ++d) {
      for (int i = 0; i < 3; ++i) {
        if (ct[i] > n) {
          ans += ct[i] - n;
          ct[(i + 1) % 3] += ct[i] - n;
          ct[i] = n;
        }
      }
    }
    cout << ans << '\n';
  }
}