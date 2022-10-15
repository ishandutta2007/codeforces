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
    int l = 1;
    while (l < N && A[l] != A[l - 1]) {
      ++l;
    }
    int r = N - 2;
    while (r >= 0 && A[r + 1] != A[r]) {
      --r;
    }
    if (l == r) {
      cout << 1 << '\n';
    } else {
      cout << max(0, r - l) << '\n';
    }
  }
}