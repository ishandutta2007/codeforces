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
    vector<int> good(N + 1, false);
    good[0] = true;
    for (int i = 0; i <= N; ++i) {
      if (i > 0 && i - A[i - 1] - 1 >= 0) {
        good[i] |= good[i - A[i - 1] - 1];
      }
      if (i < N && i + A[i] + 1 <= N) {
        good[i + A[i] + 1] |= good[i];
      }
    }
    cout << (good[N] ? "Yes" : "No") << '\n';
  }
}