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
    string S;
    cin >> N >> K >> S;
    bool extra = false;
    if (count(S.begin(), S.end(), '1') >= 1) {
      int p = N - 1;
      while (S[p] != '1') {
        --p;
      }
      if (N - 1 - p <= K) {
        K -= N - 1 - p;
        swap(S[p], S[N - 1]);
      } else {
        extra = true;
      }
    }
    if (count(S.begin(), S.end(), '1') + extra >= 2) {
      int p = 0;
      while (S[p] != '1') {
        ++p;
      }
      if (p <= K) {
        K -= p;
        swap(S[p], S[0]);
      }
    }
    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
      ans += 10 * (S[i] - '0') + (S[i + 1] - '0');
    }
    cout << ans << '\n';
  }
}