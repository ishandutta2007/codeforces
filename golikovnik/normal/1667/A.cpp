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

  int n; cin >> n;
  vector<ll> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  ll ans = (ll) 1e18;
  for (int z = 0; z < n; ++z) {
    ll res = 0;
    {
    ll cur = 0;
    for (int i = z + 1; i < n; ++i) {
      auto go = cur / a[i] + 1;
      res += go;
      go *= a[i];
      cur = go;
    }
  }
      {
        ll cur = 0;
        for (int i = z - 1; i >= 0; --i) {
          auto go = cur / a[i] + 1;
          res += go;
          go *= a[i];
          cur = go;   
        }
      }
    smin(ans, res);
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}