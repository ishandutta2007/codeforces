// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    vector<int> ct(n + 1);
    for (int i = 0; i < n; ++i) {
      if (s[i] != c) {
        ct[i + 1] += 1;
      }
    }
    if (accumulate(ct.begin(), ct.end(), 0) == 0) {
      cout << 0 << '\n';
    } else {
      int ans = -1;
      for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = i; j <= n; j += i) {
          ok &= (ct[j] == 0);
        }
        if (ok) {
          ans = i;
        }
      }
      if (ans == -1) {
        cout << 2 << ' ' << n << ' ' << n - 1 << '\n';
      } else {
        cout << 1 << ' ' << ans << '\n';
      }
    }
  }
}