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

int const N = 8008;
int const M = 4004;
ll dp[N][M];

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;

  ll const INF = -1e18;

  int nvs = 0;
  dp[nvs][0] = 0;
  nvs++;

  auto solve = [&](auto&& self, int l, int r) -> int {
    if (l == r) {
      return 0;
    }
    int id = nvs++;

    int m = int(min_element(a.begin() + l, a.begin() + r) - a.begin());
    int L = self(self, l, m);
    int R = self(self, m + 1, r);
    int sl = m - l;
    int sr = r - m - 1;

    for (int x = 0; x <= r - l; ++x) {
      dp[id][x] = INF;
    }

    for (int tl = 0; tl <= sl; ++tl) {
      for (int tr = 0; tr <= sr; ++tr) {
        for (int tme : {0, 1}) {
          smax(dp[id][tl + tr + tme], dp[L][tl] + dp[R][tr] + tme * (s * a[m]) - a[m] * (2 * ll(tl) * tr + tme + 2 * ll(tl) * tme + 2 * ll(tr) * tme));
        }
      }
    }

    return id;
  };
  cout << dp[solve(solve, 0, n)][s] << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}