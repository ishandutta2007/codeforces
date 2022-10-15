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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    if (K == 1) {
      cout << (N - 1) / 2 << '\n';
    } else {
      int ans = 0;
      for (int i = 1; i < N - 1; ++i) {
        ans += A[i] > A[i + 1] + A[i - 1];
      }
      cout << ans << '\n';
    }
  }
}