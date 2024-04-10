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
    array<int, 3> L;
    cin >> L[0] >> L[1] >> L[2];
    bool ok = false;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (i == j || j == k || i == k) {
            continue;
          }
          ok |= (L[i] != L[j] ? L[i] + L[j] == L[k] : L[k] % 2 == 0);
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}