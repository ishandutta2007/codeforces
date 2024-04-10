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
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    const long long INF = (long long) 1e17;
    vector<long long> ans(N + 1, -INF);
    ans[0] = 0;
    for (int i = 0; i < N; ++i) {
      long long sum = 0;
      for (int j = 0; i + j < N; ++j) {
        sum += A[i + j];
        ans[j + 1] = max(ans[j + 1], sum + 1LL * (j + 1) * X);
      }
    }
    debug(ans);
    for (int i = N - 1; i >= 0; --i) {
      ans[i] = max(ans[i], ans[i + 1] - X);
    }
    for (int i = 0; i < N; ++i) {
      ans[i + 1] = max(ans[i], ans[i + 1]);
    }
    for (int i = 0; i <= N; ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}