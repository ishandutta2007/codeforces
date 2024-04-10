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
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  sort(P.begin(), P.end());
  vector<long long> pref(N + 1);
  for (int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] + P[i];
  }

  while (Q--) {
    int X, Y;
    cin >> X >> Y;
    cout << pref[N - X + Y] - pref[N - X] << '\n';
  }
}