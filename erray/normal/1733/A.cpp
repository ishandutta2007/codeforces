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
    vector<int> mx(K);
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      mx[i % K] = max(mx[i % K], X);
    }
    cout << accumulate(mx.begin(), mx.end(), 0LL) << '\n';
  }
}