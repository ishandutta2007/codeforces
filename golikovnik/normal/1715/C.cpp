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

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  ll ans = ll(n) * (n + 1) / 2;
  auto f = [&](int i) -> ll {
    if (i >= 0 && i + 1 < n && a[i] != a[i + 1]) {
      return ll(i + 1) * (n - i - 1);
    }
    return 0;
  };
  for (int i = 0; i + 1 < n; ++i) {
    ans += f(i);    
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    --i;
    ans -= f(i - 1);
    ans -= f(i);
    a[i] = x;
    ans += f(i - 1);
    ans += f(i);
    cout << ans << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}