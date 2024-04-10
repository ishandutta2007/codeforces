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
    int N, K;
    cin >> N >> K;
    if (K == N - 1) {
      if (N == 4) {
        cout << -1 << '\n';
      } else {
        cout << N - 3 << ' ' << N - 1 << '\n';
        cout << 0 << ' ' << ((N - 1) ^ 3) << '\n';
        cout << 2 << ' ' << 3 << '\n';
        set<int> st = {0, 2, 3};
        for (int i = 0; i < N - 1; ++i) {
          int o = (N - 1) ^ i;
          if (st.count(i) || st.count(o)) {
            continue;
          }
          if (i < o) {
            cout << i << ' ' << o << '\n';
          }
        }
      }
    } else {
      cout << K << ' ' << N - 1 << '\n';
      for (int i = 1; i < N - 1; ++i) {
        int o = (N - 1) ^ i;
        if (o < i) {
          continue;
        }
        if (i == K || o == K) {
          cout << 0 << ' ' << (i == K ? o : i) << '\n';
        } else if (i < o) {
          cout << i << ' ' << o << '\n'; 
        }
      }
    }
  }
}