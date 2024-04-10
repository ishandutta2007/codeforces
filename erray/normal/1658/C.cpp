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
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
      cin >> C[i];
    }
    bool ok = (count(C.begin(), C.end(), 1) == 1);
    int p = 0;
    while (p < N && C[p] != 1) {
      ++p;
    }
    for (int i = 0; i < N - 1; ++i) {
      int me = (p + i) % N;
      int next = (p + i + 1) % N;
      debug(p, me, next);
      ok &= (C[next] - C[me]) <= 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}