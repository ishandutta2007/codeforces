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
      --A[i];
    }
    
    vector<int> dp(N + 2, -N);
    dp[0] = 0;
    vector<int> ct(N + 1);
    for (int i = 0; i <= N; ++i) {
      fill(ct.begin(), ct.end(), 0);
      int mx = 0;
      if ((i == N || i == 0 || A[i - 1] == A[i])) {
        dp[i + 1] = dp[i] + 1;
      }
      for (int j = i - 1; j >= 0; --j) {
        mx = max(mx, ++ct[A[j]]);
        if (mx * 2 <= (i - j) && (i - j) % 2 == 0 && (j == 0 || i == N || A[j - 1] == A[i])) {
          dp[i + 1] = max(dp[i + 1], dp[j] + 1);
        }
      }  
    }
    
    cout << dp[N + 1] - 1 << '\n';
  }
}