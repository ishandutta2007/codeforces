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

  int n; cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  int pos = int(max_element(a.begin(), a.end()) - a.begin());
  
  ll mval = a[pos];
  if (mval == 0) {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return 0;
  }

  if (*min_element(a.begin(), a.end()) == mval) {
    cout << "NO\n";
    return 0;
  }

  auto pr = [&](int x) {
    return (x - 1 + n) % n;
  };
  auto nx = [&](int x) {
    return (x + 1) % n;
  };

  for (int i = 0; i < n; ++i) {
    if (a[i] == mval && a[pr(i)] != mval) {
      pos = i;
      break;
    }
  }

  vector<ll> ans(n);
  ans[pos] = mval;
  ans[pr(pos)] = 2 * mval + a[pr(pos)];
  for (int i = pr(pr(pos)); i != pos; i = pr(i)) {
    ans[i] = ans[nx(i)] + a[i];
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    assert(ans[i] % ans[(i + 1) % n] == a[i]);
  }
  for (auto x : ans) cout << x << ' ';
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}