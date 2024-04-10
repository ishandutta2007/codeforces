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
    map<int, int> ct;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      ct[A[i]] += 1;
    }

    int one = 0;
    int both = 0;
    for (auto[x, c] : ct) {
      if (c == 1) {
        one += 1;
      } else {
        both += 1;
      }
    }
    cout << both + (one + 1) / 2 << '\n';
  }
}