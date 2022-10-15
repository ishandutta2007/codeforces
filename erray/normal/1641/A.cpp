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
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    map<int, int> ct;
    for (auto e : A) {
      if (e % X == 0 && ct[e / X]) {
        --ct[e / X];
      } else {
        ct[e] += 1;
      }
    }
    int ans = 0;
    for (auto[c, x] : ct) {
      ans += x;
    }
    cout << ans << '\n';
  }
}