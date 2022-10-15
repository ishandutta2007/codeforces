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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    sort(A.begin(), A.end());

    bool ok = false;
    for (int i = 0; i < N; ++i) {
      ok |= binary_search(A.begin(), A.end(), A[i] - K);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}