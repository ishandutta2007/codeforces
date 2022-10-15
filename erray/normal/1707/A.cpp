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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int c = 0;
    string ans(N, '1');
    for (int i = N - 1; i >= 0; --i) {
      if (c == Q && A[i] > Q) {
        ans[i] = '0';
      } else if (A[i] > c) {
        c += 1;
      }
    }
    cout << ans << '\n';
  }
}