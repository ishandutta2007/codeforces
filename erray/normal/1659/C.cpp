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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
      cin >> X[i];
    }
    int c = 0;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += 1LL * (X[i] - c) * B;
      if (A <= 1LL * B * (N - i - 1)) {
        ans += 1LL * (X[i] - c) * A;
        c = X[i];
      }
    }
    cout << ans << '\n';
  }
}