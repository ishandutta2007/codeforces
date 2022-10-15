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
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }

    if (n == 3) {
      cout << 2 << '\n';
      continue;
    }

    int ans = 0;
    while (n % 2) {
      ++n;
      ++ans;
    }
    ++ans;
    n /= 2;
    ans += (n > 1);
    cout << ans << '\n';
  }
}