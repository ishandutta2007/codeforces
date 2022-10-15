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
    for (int i = N - 2; i >= 0; i -= 2) {
      if (A[i] > A[i + 1]) {
        swap(A[i], A[i + 1]);
      }
    }
    cout << (is_sorted(A.begin(), A.end()) ? "YES" : "NO") << '\n';
  }
}