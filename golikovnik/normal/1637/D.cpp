//  Copyright 2021 Nikita Golikov

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

void solveTest() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  int const INFS = 100*100+10;
  ll const INF = ll(2e18);
  vector dp(n+1, vector<ll>(INFS, INF));
  dp[0][0] = 0;
  ll sumsq = 0;
  ll st = 0;
  for (int i = 0; i < n; ++i) {
    for (int s = 0; s < INFS; ++s) {
      if (dp[i][s] == INF) {
        continue;
      }
      for (int rot = 0; rot < 2; ++rot) {
        smin(dp[i+1][s+a[i]], dp[i][s] + (ll(b[i])*b[i]+ll(a[i])*a[i])*i+sumsq+2*s*a[i]+2*(st-s)*b[i]);
        swap(a[i], b[i]);
      }
    }
    sumsq += ll(a[i])*a[i];
    sumsq += ll(b[i])*b[i];
    st += a[i];
    st += b[i];
  }
  cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}