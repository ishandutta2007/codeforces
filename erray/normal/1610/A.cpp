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
    int N, M;
    cin >> N >> M;
    if (N == 1 || M == 1) {
      cout << 1 - (N == 1 && M == 1);
    } else {
      cout << 2; 
    }
    cout << '\n';
  }
}