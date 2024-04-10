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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(K);
    for (int i = 0; i < K; ++i) {
      cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    bool ok = false;
    for (auto x : {N, M}) {
      long long need = N ^ M ^ x;
      for (auto e : A) {
        int b = e / x;
        if (b > 1 && (need > 1 || A[0] / x > 2)) {
          need -= b;
        }
      }
      ok |= need <= 0;
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}