// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int ans = n * a;
    if (b >= 0) {
      ans += n * b;
    } else {
      array<int, 2> ct = {};
      for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
          ct[s[i] - '0']++;
        } 
      }
      ans += (min(ct[0], ct[1]) + 1) * b;
    }
    cout << ans << '\n';
  }
}