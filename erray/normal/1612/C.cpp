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
    int K;
    long long X;
    cin >> K >> X;
    int low = 1, high = K * 2 - 1;
    auto G = [&](int x) {
      return 1LL * x * (x + 1) / 2;
    };

    while (low < high) {
      int mid = (0LL + low + high) >> 1;
      int first = min(mid, K);
      int second = max(0, mid - K);
      if (G(first) + G(K - 1) - G(K - 1 - second) < X) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    cout << low << '\n';
  }
}