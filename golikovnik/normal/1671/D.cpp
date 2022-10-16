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

void solveTest() {
  int n, X;
  cin >> n >> X;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  auto calc = [&](ll L, ll R, ll x, ll y) {
    if (L > R) {
      return ll(0);
    }
    if (x == -1) {
      return R - L + min(llabs(y - L), llabs(y - R));
    }
    swap(L, x);
    swap(R, y);
    //  L, x, y, R
    //  L, y, x, R
    return llabs(y - x) + min(llabs(L - x) + llabs(y - R), llabs(L - y) + llabs(x - R)) - llabs(R - L);
  };

  int L = *min_element(a.begin(), a.end());
  int R = *max_element(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    ans += llabs(a[i + 1] - a[i]);
  }

  vector<ll> x(n + 1), y(n + 1);
  x[0] = calc(1, L - 1, -1, a[0]);
  y[0] = calc(R + 1, X, -1, a[0]);
  for (int i = 0; i < n - 1; ++i) {
    x[i + 1] = calc(1, L - 1, a[i], a[i + 1]);
    y[i + 1] = calc(R + 1, X, a[i], a[i + 1]);
  }
  x[n] = calc(1, L - 1, -1, a[n - 1]);
  y[n] = calc(R + 1, X, -1, a[n - 1]);

  // for (ll v : y) {
  //   cerr << v << '\n';
  // }

  ll const INF = ll(1e18);
  ll mn = INF;
  ll res = INF;
  for (int i = 0; i <= n; ++i) {
    smin(res, ans + mn + y[i]);
    smin(mn, x[i]);
  }
  mn = INF;
  for (int i = 0; i <= n; ++i) {
    smin(res, ans + mn + x[i]);
    smin(mn, y[i]);
  }

  smin(res, ans + calc(1, X, -1, a[0]));
  smin(res, ans + calc(1, X, -1, a[n - 1]));
  for (int i = 0; i + 1 < n; ++i) {
    smin(res, ans + calc(1, X, a[i], a[i + 1]));
  }

  cout << res << '\n';
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