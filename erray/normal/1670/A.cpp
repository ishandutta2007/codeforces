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
    int neg = 0;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      neg += (A[i] < 0);
      A[i] = abs(A[i]);
    }
    for (int i = 0; i < neg; ++i) {
      A[i] = -A[i];
    }
    cout << (is_sorted(A.begin(), A.end()) ? "YES" : "NO") << '\n';
  }
}