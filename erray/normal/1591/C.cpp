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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    auto Solve = [&](vector<int> x) -> long long {
      if (x.empty()) {
        return 0;
      }
      vector<long long> sum(K);
      for (int i = 0; i < int(x.size()) - 1; ++i) {
        sum[i % K] += x[i] * 2;
      }
      return (*min_element(sum.begin(), sum.end())) + x.back() * 2;
    };
    
    array<vector<int>, 2> part;
    for (auto e : A) {
      part[e < 0].push_back(abs(e)); 
    }
    long long ans = 0;
    for (int i = 0; i < 2; ++i) {
      sort(part[i].begin(), part[i].end());
      ans += Solve(part[i]);
    }
    ans -= max(part[0].empty() ? 0 : part[0].back(), part[1].empty() ? 0 : part[1].back());
    cout << ans << '\n';
  }
}