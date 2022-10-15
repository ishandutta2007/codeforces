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
    auto Ask = [&](int l, int r) {
      cout << "? " << ' ' << l + 1 << ' ' << r + 1 << endl;
      int res = 0;
      for (int i = 0; i < r - l + 1; ++i) {
        int X;
        cin >> X;
        --X;
        res += (l <= X && X <= r);
      }
      return res;
    };

    int l = 0;
    while (1 << (l + 1) < N) {
      ++l;
    } 

    int p = 0;
    for (int i = (1 << l); i > 0; i >>= 1) {
      if (p + i <= N && Ask(0, p + i - 1) % 2 == 0) {
        p += i;
      }
    }
    cout << "! " << p + 1 << endl;
  }
}