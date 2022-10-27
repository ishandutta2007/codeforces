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
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }
    long long ans = accumulate(A.begin(), A.end(), 0LL) + accumulate(B.begin(), B.end(), 0LL) - *max_element(B.begin(), B.end());
    cout << ans << '\n';    
  }
}