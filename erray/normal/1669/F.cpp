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
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
      cin >> W[i];
    }

    vector<int> pref(N + 1);
    for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i] + W[i];
    }

    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
      int l = int(lower_bound(pref.begin(), pref.end(), pref[N] - pref[i]) - pref.begin());
      if (l <= i && pref[l] == pref[N] - pref[i]) {
        ans = max(ans, l + N - i); 
      }
    }
    cout << ans << '\n';
  }
}