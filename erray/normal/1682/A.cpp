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
    cin >> N >> S;
    int p = N / 2;
    int ans = 0;
    while (p < N && S[p] == S[N / 2]) {
      ans += 1;
      ++p;
    }
    cout << ans * 2 - (N % 2 == 1) << '\n';
  }
}