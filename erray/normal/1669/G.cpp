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
    vector<string> A(N + 1);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    A[N] = string(M, 'o');
    for (int i = N - 1; i >= 0; --i) {
      for (int j = 0; j < M; ++j) {
        if (A[i][j] == '*') {
          int x = i;
          while (A[x + 1][j] == '.') {
            swap(A[x + 1][j], A[x][j]);
            ++x;
          }
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      cout << A[i] << '\n';
    }
  }
}