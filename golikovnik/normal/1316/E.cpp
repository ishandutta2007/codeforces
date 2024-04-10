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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<array<int, 7>> b(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j) {
      cin >> b[i][j];
    }
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] > a[j];
  });
  ll const INF = -10;
  vector dp(2, vector(p + 1, vector(1 << p, INF)));
  int s = 0;
  int t = 1;
  dp[s][0][0] = 0;
  for (int i = 0; i < n; ++i, swap(s, t)) {
    for (int c = 0; c <= p; ++c) {
      for (int m = 0; m < (1 << p); ++m) {
        dp[t][c][m] = INF;
      }
    }
    auto aval = a[order[i]];
    auto bval = b[order[i]];
    for (int c = 0; c <= p; ++c) {
      for (int m = 0; m < (1 << p); ++m) {
        ll val = dp[s][c][m];
        if (val == INF) {
          continue;
        }

        int nc = c + (i < k);
        for (int pos = 0; pos < p; ++pos) {
          if (m >> pos & 1) {
            continue;
          }
          smax(dp[t][nc][m | (1 << pos)],
            val + bval[pos]);
        }

        nc = c - (i >= k);
        if (nc >= 0) {
          smax(dp[t][nc][m], val + aval);
        }

        smax(dp[t][c][m], dp[s][c][m]);
      }
    }
  }
  cout << dp[s][0][(1 << p) - 1] << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}