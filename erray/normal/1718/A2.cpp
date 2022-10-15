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
    }
    map<int, int> g;
    g[0] = 0;
    int mx = 0;
    int p = 0;
    for (int i = 0; i < N; ++i) {
      p ^= A[i];
      if (g.count(p) == 0) {
        g[p] = -1;
      }
      g[p] += 1;
      if (mx > g[p]) {
        g[p] = mx;
      } else {
        mx = g[p]; 
      }
    }
    cout << N - g[p] << '\n';
  }
}