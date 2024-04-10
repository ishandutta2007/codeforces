// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string S, T;
    cin >> S >> T;
    sort(S.begin(), S.end());
    int N = int(S.size());
    if (T == "abc") {
      vector<int> val(256);
      iota(val.begin(), val.end(), 0);
      int c = 0;
      for (int i = 0; i < N && c < 3; ++i) {
        if (S[i] == T[c]) {
          ++c;
        }
      }
      if (c == 3) {
        swap(val['b'], val['c']);
      }
      sort(S.begin(), S.end(), [&](char x, char y) {
        return val[x] < val[y];
      });
    }
    cout << S << '\n';
  }
}