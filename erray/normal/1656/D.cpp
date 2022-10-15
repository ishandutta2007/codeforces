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
    long long N;
    cin >> N;
    auto S = N;
    int p = 0;
    while (N % 2 == 0) {
      N /= 2;
      ++p;
    }
    debug(N);
    long long ans = min(2LL << p, (N == 1 ? LLONG_MAX : N));
    cout << (ans <= int(2e9) && ans * (ans + 1) / 2 <= S ? ans : -1LL) << '\n';
  }
}