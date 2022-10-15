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

    vector<bool> a(N + 1, true);
    int p = 0;
    while (p < N && C[p] == 0) {
      a[p] = false;
      ++p;
    }
    for (int i = 0; i < N; ++i) {
      if (!a[i]) {
        a[i + C[i]] = false;
      } else {
        a[C[i]] = false;
      }
    }

    for (int i = 0; i < N; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}