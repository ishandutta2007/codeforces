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
      cout << "9\n";
      continue;
    }

    string ans = "98";
    for (int i = 0; i < n - 2; ++i) {
      int step = (8 + i + 1) % 10;
      ans += char('0' + step);
    }
    cout << ans << '\n';
  }
}