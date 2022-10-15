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
    map<int, int> ct;
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      ct[X] += 1;
    }

    int ans = -1;
    for (auto[x, c] : ct) {
      if (c >= 3) {
        ans = x;
      }
    }
    cout << ans << '\n';
  }
}