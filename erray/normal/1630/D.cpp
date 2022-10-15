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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    int g = 0;
    for (int i = 0; i < M; ++i) {
      int X;
      cin >> X;
      g = gcd(g, X);
    }

    vector<vector<int>> all(g);
    for (int i = 0; i < N; ++i) {
      all[i % g].push_back(A[i]);
    }

    const long long inf = (long long) 1e16;
    array<long long, 2> ans = {};
    for (auto& e : all) {
      sort(e.begin(), e.end());
      array<long long, 2> best = {0, inf};
      long long sum = 0;
      for (int i = 0; i < int(e.size()); ++i) {
        sum += e[i];
        best[~i & 1] = min(best[~i & 1], sum);  
      }
      ans[0] += best[0];
      ans[1] += best[1];
    }
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += A[i];
    }
    cout << sum - 2 * min(ans[0], ans[1]) << '\n';
  }
}