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
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      sum += A[i];
    }
    sort(A.rbegin(), A.rend());
    long long ans = sum - K;
    sum -= K;
    for (int i = 0; i < N - 1; ++i){
      sum -= A[i] - A[N - 1];     
      debug(sum);
      ans = min(ans, max(0LL, (sum + (i + 1)) / (i + 2)) + (i + 1));
    }
    cout << max(0LL, ans) << '\n';
  }
}