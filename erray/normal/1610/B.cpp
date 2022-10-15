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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    int p = 0;
    while (p < N && A[p] == A[N - p - 1]) {
      ++p;
    }

    if (p == N) {
      cout << "YES\n";
      continue;
    }

    bool ok = false;
    for (auto x : {A[p], A[N - p - 1]}) {
      int l = 0, r = N - 1;
      while (l < r) {
        if (A[l] == A[r]) {
          ++l, --r;  
        } else if (A[l] == x) {
          ++l;
        } else if (A[r] == x) {
          --r;
        } else {
          break;
        }
      }
      ok |= (l >= r);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}