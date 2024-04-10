// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if (k1 > k2) {
      swap(k1, k2);
    }
    
    int rk1 = n - k2;
    int rk2 = n - k1;
    cout << ((k1 + (k2 - k1) / 2) >= w && (rk1 + (rk2 - rk1) / 2) >= b ? "YES" : "NO") << '\n'; 
  }
}