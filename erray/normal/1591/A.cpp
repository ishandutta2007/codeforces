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
    int N;
    cin >> N;
    int ans = 1;
    int bef = -1;
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      ans += (x == 1);
      ans += (x == 1 && bef == 1) * 4;
      ok &= (x != 0 || bef != 0);
      bef = x;
    }  
    cout << (ok ? ans : -1) << '\n';
  }
}