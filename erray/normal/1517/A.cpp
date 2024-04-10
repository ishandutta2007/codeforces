// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (n % 2050 != 0) {
      cout << -1 << '\n';
    } else {
      long long res = n / 2050;
      int ans = 0;
      while (res > 0) {
        ans += res % 10;
        res /= 10;
      }
      cout << ans << '\n';
    }
  }
}