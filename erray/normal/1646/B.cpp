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
    sort(A.rbegin(), A.rend());
    int l = 0, r = N - 2;
    long long sum_l = 0;
    long long sum_r = A[N - 1];
    bool ok = false;
    while (l < r) {
      sum_l += A[l];
      sum_r += A[r];
      ++l, --r;
      ok |= (sum_l > sum_r);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                     
}