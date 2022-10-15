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
    int N, M;
    cin >> N >> M;
    vector<int> c(N);
    for (int i = 0; i < M; ++i) {
      int X;
      cin >> X;
      c[X - 1] += 1;
    }

    int low = 0, high = 2 * M + 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      long long a = 0;
      for (auto e : c) {
        if (e >= mid) {
          a -= e - mid;
        } else {
          a += (mid - e) / 2;
        }
      }
      if (a >= 0) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << low << '\n';
  }
}