// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = int(s.size());
    int m = int(t.size());
    function<bool(int, int, bool)> Go = [&](int i, int j, bool did = false) {
      if (j == m) {
        return true;
      }
      if (i < 0 || i >= n || s[i] != t[j]) {
        return false;
      }
      return Go(i - 1, j + 1, true) || (did ? false : Go(i + 1, j + 1, did));
    };
    
    bool ans = false;
    for (int i = 0; i < n; ++i) {
      ans |= Go(i, 0, false);
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}