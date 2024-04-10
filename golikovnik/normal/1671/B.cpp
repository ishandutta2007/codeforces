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

bool solveTest() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector dp(n, vector<bool>(3));
  for (int i = 0; i < 3; ++i) dp[0][i] = true;
  for (int i = 1; i < n; ++i) {
    for (int d = 0; d < 3; ++d) {
      for (int d2 = 0; d2 < 3; ++d2) {
        int x = a[i - 1] + d2 - 1;
        int y = a[i] + d - 1;
        if (dp[i - 1][d2] && y == x + 1) {
          dp[i][d] = true;
        }
      }
    }
  }
  return *max_element(dp[n - 1].begin(), dp[n - 1].end());
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
    cout << (solveTest() ? "YES" : "NO") << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}