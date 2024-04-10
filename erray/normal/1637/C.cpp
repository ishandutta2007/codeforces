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

    int odd = 0;
    long long sum = 0;
    for (int i = 1; i < N - 1; ++i) {
      odd += (A[i] % 2);
      sum += A[i];  
    }
    int now_odd = 0;
    bool mid = false;
    bool one = false;
    for (int i = 1; i < N - 1; ++i) {
      int l = now_odd;
      int r = odd - now_odd - (A[i] % 2);
      now_odd += (A[i] % 2);
      if (A[i] > 1 && (l > 0 || r > 0)) {
        one = true;
        mid |= (l > 0 && r > 0);
      }
    }

    debug(odd, one, mid);
    if (!one && odd) {
      cout << -1 << '\n';
    } else {
      if (!mid) {
        odd += 1;
        sum -= 1;
      }
      cout << (odd + 1) / 2 + sum / 2 << '\n';
    }
  }
}