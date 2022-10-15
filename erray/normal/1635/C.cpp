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

    if (is_sorted(A.begin(), A.end())) {
      cout << 0 << '\n';
    } else if (A[N - 1] < A[N - 2] || A[N - 1] < 0) {
      cout << -1 << '\n';
    } else {
      cout << N - 2 << '\n';
      for (int i = 0; i < N - 2; ++i) {
        cout << i + 1 << ' ' << N - 1 << ' ' << N << '\n';
      }
    }
  }
}