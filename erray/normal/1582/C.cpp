// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = n + 1;
    for (int c = 0; c < 26; ++c) {
      int l = 0;
      int r = n - 1;
      int res = 0;
      while (l <= r) {
        if (s[l] == s[r]) {
          ++l, --r;
        } else if (s[l] == 'a' + c) {
          ++l, ++res;
        } else if (s[r] == 'a' + c) {
          --r, ++res;
        } else {
          break;
        }
      }
      
      if (l > r) {
        ans = min(ans, res);  
      }
    }
    cout << (ans == n + 1 ? -1 : ans) << '\n';
  }
}