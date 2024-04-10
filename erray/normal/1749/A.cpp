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
    for (int i = 0; i < M; ++i) {
      int foo0, foo1;
      cin >> foo0 >> foo1;
    }
    cout << (N != M ? "YES" : "NO") << '\n';
  }
}