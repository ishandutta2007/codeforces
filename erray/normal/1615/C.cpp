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
    string A, B;
    cin >> N >> A >> B;
    int c = count(A.begin(), A.end(), '1');
    int cb = count(B.begin(), B.end(), '1'); 
    debug(c, cb);
    if (cb != c && cb != (N - c + 1)) {
      cout << -1 << '\n';
      continue;
    }

    auto Odd_ans = [&] {
      if (cb != (N - c + 1)) {
        return N * 2;
      }
      int p = 0;
      while (p < N && (A[p] != '1' || B[p] != '1')) {
        ++p;
      }

      if (p == N) {
        p = 0;
        while (p < N && A[p] != '1') {
          ++p;
        }
      }

      for (int i = 0; i < N; ++i) {
        if (i != p) {
          A[i] = '1' - A[i] + '0';
        }
      }

      int ans = 0;
      for (int i = 0; i < N; ++i) {
        if (A[i] != B[i]) {
          ans += 1;
        }
      }
      return ans + 1;
    };

    auto Even_ans = [&] {
      if (cb != c) {
        return N * 2;
      }

      debug(A, B);
      int ans = 0;
      for (int i = 0; i < N; ++i) {
        if (A[i] != B[i]) {
          ans += 1;
        }
      } 
      return ans;
    };

    int ans = Even_ans();
    ans = min(ans, Odd_ans());
    cout << ans << '\n';
  }
}