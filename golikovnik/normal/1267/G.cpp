//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int const N = 105;
int const S = (int) 1e4 + 5;

using real_t = double;

real_t dp[2][N][S];

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, X;
  cin >> n >> X;
  vector<int> a(n);
  int tot = 0;
  for (int& x : a) {
    cin >> x;
    tot += x;
  }

  int s = 0, t = 1;
  dp[s][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    memset(dp[t], 0, sizeof dp[t]);
    for (int k = 0; k <= i; ++k) {
      for (int sum = 0; sum < S; ++sum) {
        dp[t][k][sum] += dp[s][k][sum];
        if (sum + x < S) {
          dp[t][k + 1][sum + x] += dp[s][k][sum] * (k + 1) / (n - k);
        }
      }
    }
    swap(s, t);
  }

  real_t ans = 0;
  for (int k = 1; k <= n; ++k) {
    for (int sum = 0; sum < S; ++sum) {
      auto if_rand = (1 + (real_t) k / n) * X / 2 * n / k;
      auto if_buy = (real_t) sum / k;
      ans += dp[s][k][sum] * min(if_rand, if_buy);
    }
  }
  cout << setprecision(20) << fixed << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}