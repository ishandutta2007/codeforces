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
    int mx = 0;
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      mx = max(mx, ++ct[X]);
    }

    int ans = N - mx;
    while (mx < N) {
      ans += 1;
      mx *= 2;
    }
    cout << ans << '\n';
  }
}