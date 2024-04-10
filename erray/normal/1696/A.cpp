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
    int N, Z;
    cin >> N >> Z;
    vector<int> A(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      ans = max(ans, A[i] | Z);
    }
    cout << ans << '\n';
  }
}