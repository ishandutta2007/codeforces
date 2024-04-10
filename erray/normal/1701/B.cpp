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
    cout << 2 << '\n';
    vector<bool> vis(N + 1);
    for (int i = 1; i <= N; ++i) {
      if (vis[i]) {
        continue;
      }
      for (int j = i; j <= N; j *= 2) {
        cout << j << ' ';
        vis[j] = true;
      }
    }
    cout << '\n';
  }
}