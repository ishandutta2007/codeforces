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
    int M;
    cin >> M;
    vector<int> P(M);
    for (int i = 0; i < M; ++i) {
      cin >> P[i];
    }
    int ans = 0;
    for (int s = M / 2; s > 0; s >>= 1) {
      for (int i = 0; i < M; i += s * 2) {
        if (P[i] > P[i + s]) {
          ans += 1;
          for (int j = 0; j < s; ++j) {
            swap(P[i + j], P[i + j + s]);
          } 
        }
      }  
    }
    cout << (is_sorted(P.begin(), P.end()) ? ans : -1) << '\n';
  }
}