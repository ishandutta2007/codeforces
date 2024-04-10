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
    long long A, B, X;
    cin >> A >> B >> X;
    if (A < B) {
      swap(A, B);
    }

    bool ok = false;
    while (B > 0) {
      //debug(A, B);
      ok |= X <= A && (X % B) == (A % B); 
      A %= B;
      swap(A, B);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}