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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    array<int, 101> ct = {};
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      ct[abs(X)] += 1;
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
      ans += min(ct[i], 2 - !i);
    }
    cout << ans << '\n';
  }
}