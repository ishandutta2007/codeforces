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
    vector<long long> pref(N + 1);
    for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i] + A[i];
    }

    if (K <= N) {
      long long ans = 0;
      for (int i = K; i <= N; ++i) {
        ans = max(ans, pref[i] - pref[i - K]);
      }
      cout << ans + 1LL * K * (K - 1) / 2 << '\n';
    } else {
      cout << pref[N] + 1LL * N * (K - 1) - 1LL * N * (N - 1) / 2 << '\n';
    }
  }
}