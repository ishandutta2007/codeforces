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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int ans = N;
    for (int i = 0; i < N; ++i) {
      int need = accumulate(A.begin(), A.begin() + i + 1, 0);
      long long sum = 0;
      int res = 0;
      int p = -1;
      for (int j = 0; j < N; ++j) {
        sum += A[j];
        if (sum == need) {
          sum = 0;
          res = max(res, j - p);
          p = j;
        }
      }
      if (sum == 0) {
        ans = min(ans, res);
      }
    }
    cout << ans << '\n';
  }
}