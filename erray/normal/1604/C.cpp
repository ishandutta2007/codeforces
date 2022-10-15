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

    long long g = 1;
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      g = lcm(i + 2, g);
      if (g > int(1e9)) {
        continue;
      }
      ok &= (A[i] % g != 0);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}