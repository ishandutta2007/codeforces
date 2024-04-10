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
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int ans = N - 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        int diff = A[j] - A[i];
        int dist = j - i;
        int g = gcd(diff, dist);
        dist /= g;
        diff /= g;
        int res = 0;
        int cur = A[i] - (i / dist) * diff;
        for (int k = i % dist; k < N; k += dist) {
          res += (A[k] == cur);
          cur += diff;
        }
        ans = min(ans, N - res);
      }
    }
    cout << ans << '\n';
  }
}