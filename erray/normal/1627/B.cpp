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
    vector<int> c(N + M + 1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        c[max(i, N - i - 1) + max(j, M - j - 1)] += 1;
      }
    }
    int p = 0;
    for (int i = 0; i < N * M; ++i) {
      while (c[p] == 0) {
        ++p;
      }
      cout << p << ' ';
      --c[p];
    }
    cout << '\n';
  }
}