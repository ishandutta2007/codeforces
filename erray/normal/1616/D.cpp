// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
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
    int X;
    cin >> X;
    for (auto& e : A) {
      e -= X;
    }

    vector<bool> use(N, true);
    for (int i = 0; i < N; ++i) {
      int sum = A[i];
      for (int j = i - 1; j >= max(0, i - 2) && use[j]; --j) {
        sum += A[j];
        use[i] = use[i] & (sum >= 0);
      }
    }
    cout << accumulate(use.begin(), use.end(), 0) << '\n';
  }
}