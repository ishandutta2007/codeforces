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
    vector<int> L(N), R(N), C(N);
    map<array<int, 2>, int> cost;
    for (int i = 0; i < N; ++i) {
      cin >> L[i] >> R[i] >> C[i];
    }
    array<int, 2> l = {int(1e9) + 1, -1};
    array<int, 2> r = l;
    for (int i = 0; i < N; ++i) {
      if (!cost.count({L[i], R[i]}) || cost[{L[i], R[i]}] > C[i]) {
        cost[{L[i], R[i]}] = C[i];
      }
      l = min(l, array{L[i], C[i]});            
      r = min(r, array{-R[i], C[i]});
      int ans = l[1] + r[1];
      auto x = array{l[0], -r[0]};
      if (cost.count(x)) {
        ans = min(ans, cost[x]);
      }
      cout << ans << '\n';
    }
  }
}