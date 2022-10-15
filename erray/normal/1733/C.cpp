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
    vector<pair<int, int>> ans;
    auto Add = [&](int l, int r) {
      ans.emplace_back(l, r);
      if ((A[l] + A[r]) % 2 == 0) {
        swap(l, r);
      }
      A[r] = A[l];
    };
    if (N > 1) {
      Add(0, N - 1);
    }          
    debug(A);
    for (int i = 1; i < N - 1; ++i) {
      if ((A[i] + A[0]) % 2 == 1) {
        Add(0, i);
      } else {
        Add(i, N - 1);
      }
    }
    cout << N - 1 << '\n';
    for (auto[l, r] : ans) {
      cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }
}