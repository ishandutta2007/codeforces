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
    bool one = false;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      one |= (A[i] == 1);
    }

    sort(A.begin(), A.end());
    bool diff = false;
    for (int i = 0; i < N - 1; ++i) {
      diff |= (A[i] == A[i + 1] - 1);
    }
    cout << (one && diff ? "NO" : "YES") << '\n';
  }
}