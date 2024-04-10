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
    int N, M, RB, CB, RD, CD;
    cin >> N >> M >> RB >> CB >> RD >> CD;
    auto C = [&](int mx, int c, int t) {
      return (t >= c ? t - c : (mx - c - 1) + (mx - t - 1));
    };

    --RB, --CB, --RD, --CD;
    cout << min(C(N, RB, RD), C(M, CB, CD)) << '\n';
  }
}