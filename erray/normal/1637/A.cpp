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
    auto sa = A;
    sort(sa.begin(), sa.end());
    bool ok = false;
    for (int i = 0; i < N; ++i) {
      int pos = int(lower_bound(sa.begin(), sa.end(), A[i]) - sa.begin());
      ok |= (pos > i);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}