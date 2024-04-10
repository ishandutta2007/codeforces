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
    long long N;
    cin >> N;
    vector<long long> fact({1});
    while (fact.back() <= N) {
      fact.push_back(fact.back() * int(fact.size()));
    }
    fact.pop_back();

    int size = int(fact.size());
    int ans = 100;
    for (int i = 0; i	 < (1 << size); ++i) {
      long long sum = 0;
      for (int j = 0; j < size; ++j) {
        if ((i >> j) & 1) {
          sum += fact[j];
        }
      }
      ans = min(ans, __builtin_popcount(i) + __builtin_popcountll(N - sum));
    }
    cout << ans << '\n';
  }
}