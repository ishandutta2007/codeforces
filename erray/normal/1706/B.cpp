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
      --A[i];
    }
    vector<vector<int>> p(N);
    for (int i = 0; i < N; ++i) {
      p[A[i]].push_back(i % 2);
    }
    for (int i = 0; i < N; ++i) {
      array<int, 2> c = {};
      for (auto e : p[i]) {
        c[e] = max(c[e], c[e ^ 1] + 1);
      }
      cout << max(c[0], c[1]) << " \n"[i == N - 1];
    }
  }
}