// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    if (N % 2 == 1) {
      cout << -1 << '\n';
    } else {
      int ans = 0;
      for (int i = 1; i < 30; ++i) {
        if ((N >> i) & 1) {
          ans |= 1 << (i - 1);
        }
      }
      cout << ans << ' ' << 0 << ' ' << 0 << '\n';
    }
  }
}