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
    vector<int> add(N + 1);
    vector<int> nat(N + 1);
    for (int i = 0; i < N; ++i) {
      if (A[i] <= N) {
        nat[A[i]] += 1;
      }
      add[min(N, (A[i] - 1) / 2)] += 1;
    }

    int ans = 0;
    bool ok = true;
    int use = 0;
    for (int i = N; i > 0; --i) {
      use += add[i];
      if (nat[i]) {
        add[(i - 1) / 2] -= 1;
      } else {
        ans += 1;
        ok &= (use > 0);
        use -= 1;
      }
    }
    cout << (ok ? ans : -1) << '\n';
  }
}