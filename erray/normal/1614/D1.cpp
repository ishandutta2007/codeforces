// author: erray
#undef _GLIBCXX_DEBUG
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
  const int MAX = int(2E7);
  vector<bool> ip(MAX + 1, true);
  vector<int> ps;
  ps.reserve(1270607);
  for (int i = 2; i <= MAX; ++i) {
    if (ip[i]) {
      ps.push_back(i);
      for (int j = i + i; j <= MAX; j += i) {
        ip[j] = false;
      }           
    }
  }
  cerr << int(ps.size()) << '\n';
  debug(clock());

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> ct(MAX + 1);
  for (auto e : A) {
    ct[e] += 1;
  }
  for (auto p : ps) {
    for (int i = MAX / p; i > 0; --i) {
      ct[i] += ct[i * p];
    }
  }
  debug(clock());

  vector<long long> dp(MAX + 1);
  for (int i = MAX; i > 0; --i) {
    dp[i] = 1LL * ct[i] * i;
    for (auto p : ps) {
      int x = p * i;
      if (x > MAX) {
        break;
      }
      dp[i] = max(dp[i], dp[x] + 1LL * (ct[i] - ct[x]) * i);
    }
  }
  debug(clock());
  cout << dp[1] << '\n';
}