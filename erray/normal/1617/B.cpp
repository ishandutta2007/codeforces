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
  vector<bool> ip(1010, true);
  for (int i = 2; i <= 1000; ++i) {
    if (ip[i]) {
      for (int j = i * 2; j <= 1000; j += i) {
         ip[j] = false;
      }
    }
  }

  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    N -= 1;
    int p = 2;
    while (!ip[p] || N % p == 0) {
      ++p;
    }
    cout << p << ' ' << N - p << ' ' << 1 << '\n';
  }
}