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

void solve(int) {
  map<int, int> cnt;
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; cnt[x]++;
    a[i] = x;
  }
  int maxcnt = 0;
  for (auto it : cnt) smax(maxcnt, it.second);
  if (maxcnt >= n / 2) {
    cout << -1 << '\n';
    return;
  }

  int ans = 0;

  auto Mod = [&](int x, int r) {
    x %= r;
    if (x < 0) x += r;
    return x;
  };

  auto upd = [&](int d, int rem) {
    int res = 0;
    for (int x : a) {
      res += Mod(x, d) == rem;
    }
    if (res >= n / 2) {
      smax(ans, d);
    }
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int who = abs(a[i] - a[j]);
      for (int p = 1; p * p <= who; ++p) {
        if (who % p == 0) {
          upd(p, Mod(a[i], p));
          if (p * p != who) {
            upd(who / p, Mod(a[i], who / p));
          }
        }
      }
    }
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

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}