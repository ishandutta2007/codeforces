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
  int tt;
  cin >> tt;
  while (tt--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }


    int p = 0;
    while (p < N - 1 && A[p] < A[p + 1]) {
      ++p;
    }

    bool ok = N % 2 == 0 || p < N - 1;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}