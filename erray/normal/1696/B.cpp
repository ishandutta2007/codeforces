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
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += (A[i] > 0 && (i == 0 || A[i - 1] == 0));
    }
    cout << min(ans, 2) << '\n';
  }
}