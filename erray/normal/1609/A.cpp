// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
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
    vector<int> A(N);
    int mx = 0;
    long long c = 1;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      while (X % 2 == 0) {
        X /= 2;
        c *= 2;
      }  
      mx = max(mx, X);
      ans += X;
    }
    cout << ans + (c - 1) * mx << '\n';
  }
}