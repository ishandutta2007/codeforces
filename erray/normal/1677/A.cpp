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
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      vector<int> pref(N + 1);
      for (int j = 0; j < i; ++j) {
        pref[P[j]] += 1;
      }
      for (int j = 0; j < N; ++j) {
        pref[j + 1] += pref[j];
      }

      int c = 0;
      for (int j = N - 1; j > i; --j) {
        ans += c * pref[P[j]];
        c += (P[j] < P[i]);
      }
    }
    cout << ans << '\n';
  }
}