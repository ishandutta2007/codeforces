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
    array<int, 3> A;
    cin >> A[0] >> A[1] >> A[2];
    int ans = 3;
    for (int i = 0; i < 3; ++i) {
      ans = min(ans, (((A[0] + A[1] + A[2] - 3 * A[i]) % 3) + 3) % 3);
    }
    cout << bool(ans) << '\n';
  }
}