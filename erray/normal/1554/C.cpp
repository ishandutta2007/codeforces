// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    auto Can = [&](int x) {
      int res = 0;
      for (int i = 30; i >= 0; --i) {
        int bit = (n >> i) & 1;
        if (x >= ((bit ^ 1) << i)) {
          res += (1 << i);
          x -= ((bit ^ 1) << i);
        }
      }
      return (res <= m);
    };
    
    int low = 0, high = max(n, m) * 2 + 1;
    while (low < high) {
      int mid = (0LL + low + high) >> 1;
      if (Can(mid)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    cout << low << '\n';
  }
}