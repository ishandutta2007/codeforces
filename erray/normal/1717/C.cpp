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
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      int n = (i + 1) % N;
      if (A[i] > B[i] || (B[i] - 1 > B[n] && A[i] < B[i])) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}