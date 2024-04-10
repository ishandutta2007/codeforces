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
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> xs(n);
  for (auto& x : xs) cin >> x;
  xs.insert(xs.begin(), 0);
  ll ans = LLONG_MAX;
  vector<ll> suff(n + 2);
  for (int i = n; i >= 0; --i) {
    suff[i] = suff[i + 1] + xs[i];
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    smin(ans, res + (suff[i + 1] - xs[i] * (n - i)) * b);
    res += (xs[i + 1] - xs[i]) * (a + b);
  }
  cout << ans << '\n';

}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t; while (t--) solveTest();

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}