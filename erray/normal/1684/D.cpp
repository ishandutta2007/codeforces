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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    for (int i = 0; i < N; ++i) {
      A[i] -= N - i - 1;
    }
    sort(A.rbegin(), A.rend());
    debug(A);
    for (int i = 0; i < K; ++i) {
      sum -= A[i];
    }
    cout << sum - (1LL * K * (K - 1) / 2) << '\n';
  }
}