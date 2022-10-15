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
    string S;
    int K;
    vector<bool> s(26);
    cin >> N >> S >> K;
    for (int i = 0; i < K; ++i) {
      char c;
      cin >> c;
      s[c - 'a'] = true;
    }

    int p = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (s[S[i] - 'a']) {
        ans = max(ans, i - p);
        p = i;
      }
    }
    cout << ans << '\n';
  }
}