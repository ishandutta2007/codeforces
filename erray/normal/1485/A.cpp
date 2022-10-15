// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;       
    auto Log = [&](int x, int y) {
      if (y == 1) {
        return (int) 1e9;
      }
      
      int res = 0;
      while (x > 0) {
        x /= y;
        ++res;
      }

      return res;
    };
    
    int sq = sqrt(a);
    if (b > a) {
      cout << 1;
    } else if (b > sq) {
      cout << 2;
    } else {
      int ans = INT_MAX;
      for (int i = b; i < min(sq + 3, a + 2); ++i) {
        ans = min(ans, i - b + Log(a, i));
      }

      cout << ans;
    }

    cout << '\n';
  }
}