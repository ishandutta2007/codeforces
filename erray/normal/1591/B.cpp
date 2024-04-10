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

    int mx = 0;
    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (mx < A[i]) {
        mx = A[i];
        ++ans;
      }
    }
    cout << ans - 1 << '\n';
  }            
}