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
    array<set<int>, 2> s;
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      s[i % 2].insert(X % 2);
    }
    cout << (pair{int(s[0].size()), int(s[1].size())} == pair{1, 1} ? "YES" : "NO") << '\n';
  }
}