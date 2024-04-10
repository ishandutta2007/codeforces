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
      --A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
      --B[i];
    }

    vector<array<int, 2>> a;
    for (int i = 0; i < N; ++i) {
      if (i == 0 || A[i] != A[i - 1]) {
        a.push_back({A[i], 0});
      }
      a.back()[1] += 1;
    }
    int n = int(a.size());
    vector<int> next(n);
    vector<int> lst(N, -1);
    for (int i = n - 1; i >= 0; --i) {
      next[i] = lst[a[i][0]];
      lst[a[i][0]] = i;
    }

    debug(a, next);
    bool ok = true;
    int p = 0;
    for (int i = 0; i < N; ++i) {
      debug(i, B[i], a, ok);
      while (p < n && (a[p][0] != B[i] || a[p][1] == 0)) {
        debug(a[p]);
        if (a[p][1] > 0) {
          if (next[p] == -1) {
            ok = false;
          } else {
            a[next[p]][1] += a[p][1];
          }
        }
        ++p;
      }
      debug(i, p);
      if (p == n) {
        ok = false;
        break;
      }
      --a[p][1];
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}