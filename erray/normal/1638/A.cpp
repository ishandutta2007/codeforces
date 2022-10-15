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
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
    }
    int p = 0;
    while (p < N && P[p] == p + 1) {
      ++p;
    }
    if (p != N) {
      int k = p;
      while (P[k] != p + 1) {
        ++k;
      }
      reverse(P.begin() + p, P.begin() + k + 1);
    }
    for (auto e : P) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}