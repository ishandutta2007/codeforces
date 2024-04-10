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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
      if (A[i] >= M / 2) {
        A[i] = M - 1 - A[i];
      }
    }
    string ans(M, 'B');
    for (auto i : A) {
      ans[ans[i] != 'A' ? i : M - 1 - i] = 'A';
    }
    cout << ans << '\n';
  }
}