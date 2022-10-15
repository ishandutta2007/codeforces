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
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<array<int, 2>> pref(N);
  pref[0] = {};
  for (int i = 0; i < N - 1; ++i) {
    pref[i + 1] = pref[i];
    if (S[i] == S[i + 1]) {
      pref[i + 1][S[i] - '0'] += 1;
    }
  }

  while (Q--) {
    int L, R;
    cin >> L >> R;
    --L, --R;
    cout << max(pref[R][0] - pref[L][0], pref[R][1] - pref[L][1]) + 1 << '\n';
  }
}