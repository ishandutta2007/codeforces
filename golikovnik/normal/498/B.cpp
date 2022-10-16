//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  using ld = double;
  int n, T;
  cin >> n >> T;
  vector<ld> p(n);
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> t[i];
    p[i] /= 100;
  }

  vector<ld> dp(T + 1);
  vector<ld> ndp(T + 1);
  dp[0] = 1;
  ld ans = 0;
  for (int it = 0; it < n; ++it) {
    ld pskip = 1;
    for (int j = 0; j < t[it]; ++j) {
      pskip *= (1 - p[it]);
    }
    if (pskip < 1e-30) {
      pskip = 0;
    }
    for (int i = T; i >= 0; --i) {
      ndp[i] = 0;
      if (dp[i] < 1e-30) {
        dp[i] = 0;
      }
      if (i + t[it] <= T) {
        dp[i + t[it]] -= dp[i] * pskip;
        ndp[i + t[it]] += dp[i] * pskip;
      }
    }
    for (int i = 0; i < T; ++i) {
      if (dp[i] < 1e-30) {
        dp[i] = 0;
      }
      dp[i + 1] += dp[i] * (1 - p[it]);
      ndp[i + 1] += dp[i] * p[it];
    }

    for (int i = 0; i <= T; ++i) {
      ans += (dp[i] = ndp[i]);
    }
  }
  cout << setprecision(9) << fixed << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}