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
    vector<int> ord(N - 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return A[x + 1] - A[x] < A[y + 1] - A[y];
    });
    vector<int> ans(N);
    for (int i = 0; i < N - 1; ++i) {
      ans[N - 1 - i] = ord[i] + 1;
    }
    for (int i = 0; i < N; ++i) {
      cout << ans[i] + 1 << " \n"[i == N - 1];
    }
  }
}