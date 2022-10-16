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
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll X; cin >> X;
  for (auto& x : a) x -= X;

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  ll const INF = -100;
  vector dp(2, vector<ll>(2, INF));
  dp[0][0] = 0;
  dp[0][1] = 1;
  dp[1][0] = 1;
  if (a[0] + a[1] >= 0) {
    dp[1][1] = 2;
  }

  for (int i = 2; i < n; ++i) {
    vector ndp(2, vector<ll>(2, INF));
    for (int wpp : {0, 1}) {
      for (int wp : {0, 1}) {
        ll v = dp[wpp][wp];
        if (v == INF) {
          continue;
        }

        smax(ndp[wp][0], v);
        if (a[i] >= 0) {
          if (wp && a[i] + a[i - 1] < 0) {
            continue;
          }
          if (wp && wpp && a[i] + a[i - 1] + a[i - 2] < 0) {
            continue;
          }
          smax(ndp[wp][1], v + 1);
        }
        if (wp && a[i - 1] < 0) {
          continue;
        }
        if (wp && a[i] + a[i - 1] < 0) {
          continue;
        }
        if (wp && wpp && a[i] + a[i - 1] + a[i - 2] < 0) {
          continue;
        }
        smax(ndp[wp][1], v + 1);
      }
    }
    dp = ndp;
  }

  cout << max({dp[0][0], dp[0][1], dp[1][0], dp[1][1]}) << '\n';
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