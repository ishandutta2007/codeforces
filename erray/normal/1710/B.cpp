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
    int N, M;
    cin >> N >> M;
    vector<int> X(N), P(N);
    for (int i = 0; i < N; ++i) {
      cin >> X[i] >> P[i];
    }
    vector<pair<int, int>> upd;
    for (int i = 0; i < N; ++i) {
      upd.emplace_back(X[i] - P[i], 1);
      upd.emplace_back(X[i], -2);
      upd.emplace_back(X[i] + P[i], 1);
    }
    vector<pair<long long, int>> bad;
    {
      sort(upd.begin(), upd.end());
      debug(upd);
      int slope = 0;
      long long c = 0;
      int last = -1;
      bool first = true;
      for (auto[x, d] : upd) {
        if (!first) {
          c += 1LL * (x - last) * slope;        
        }
        if (c > M) {
          bad.emplace_back(c - M, x);
        }
        slope += d;
        last = x;
        first = false;
      }
      assert(slope == 0);
    }
    const long long inf = (long long) 1e18;
    long long L = -inf, R = inf;
    for (auto[need, x] : bad) {
      debug(need, x);
      L = max(L, x + need);
      R = min(R, x - need);
    }
    debug(L, R);
    for (int i = 0; i < N; ++i) {
      cout << (L - P[i] <= X[i] && X[i] <= R + P[i]);
    }
    cout << '\n';
  }
}