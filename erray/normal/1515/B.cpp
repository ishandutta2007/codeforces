// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    bool ok = false;
    for (int i = 2; i <= n; i <<= 1) {
      int me = n / i;
      if (n % i != 0) {
        break;
      }
      int sq = int(sqrt(me));
      ok |= sq * sq == me;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}