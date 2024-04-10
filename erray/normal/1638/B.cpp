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
    array<int, 2> p = {-1, -1};
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= p[A[i] % 2] <= A[i];
      p[A[i] % 2] = A[i];
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}