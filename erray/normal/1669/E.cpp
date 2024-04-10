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
    map<string, int> ct;
    array<array<int, 26>, 2> f = {};
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      string S;
      cin >> S;
      ans += f[0][S[0] - 'a'] + f[1][S[1] - 'a'] - ct[S] * 2;
      ct[S] += 1;
      f[0][S[0] - 'a'] += 1;
      f[1][S[1] - 'a'] += 1;
    }
    cout << ans << '\n';
  }
}