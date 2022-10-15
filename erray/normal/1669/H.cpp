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
    int N, K;
    cin >> N >> K;
    array<int, 31> c = {};
    fill(c.begin(), c.end(), N);
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      for (int j = 0; j <= 30; ++j, X >>= 1) {
        if (X % 2) {
          --c[j];
        }
      }
    }
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
      if (c[i] <= K) {
        K -= c[i];
        ans |= (1 << i);
      }
    }
    cout << ans << '\n';
  }
}