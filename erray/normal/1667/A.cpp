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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  long long ans = (long long) 1e18;
  for (int i = 0; i <= N; ++i) {
    long long res = 0;
    {
      long long c = 0;
      for (int j = i - 1; j >= 0; --j) {
        long long a = (c + 1 + A[j] - 1) / A[j];
        res += a;
        c = a * A[j];
      }
    }
    {
      long long c = 0;
      for (int j = i + 1; j < N; ++j) {
        long long a = (c + 1 + A[j] - 1) / A[j];
        res += a;
        c = a * A[j];
      }
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
}