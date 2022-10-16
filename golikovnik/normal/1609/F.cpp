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

// #define FAST_RANDOM

#ifndef FAST_RANDOM
#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}
#else
  using ui32 = uint32_t;
  ui32 SEED = 471241271;

  ui32 xorshift32() {
    SEED ^= SEED << 13u;
    SEED ^= SEED >> 17u;
    SEED ^= SEED << 5u;
    return SEED;
  }

  template <class T>
  T rnd_helper(T from, T to, false_type) {
    return from + (to - from) * (T(1) * xorshift32() / numeric_limits<ui32>::max());
  }

  template <class T>
  T rnd_helper(T from, T to, true_type) {
    return from + xorshift32() % (to - from + 1);
  }

  template <class T>
  T rnd(T from, T to) {
    return rnd_helper(from, to, is_integral<T>{});
  }
#endif

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = __builtin_popcountll(a[i].first);
  }

  ll ans = 0;
  vector<pair<ll, int>> lmin(n), lmax(n), rmin(n), rmax(n);
  vector<int> suff(n + 1);
  array<int, 60> cnt{};

  auto solve = [&](auto&& self, int l, int r) -> void {
    if (l + 1 == r) {
      ans += 1;
      return;
    }
    int m = (l + r) / 2;
    self(self, l, m);
    self(self, m, r);
    lmin[m - 1] = a[m - 1];
    for (int i = m - 2; i >= l; --i) {
      lmin[i] = min(a[i], lmin[i + 1]);
    }
    lmax[m - 1] = a[m - 1];
    for (int i = m - 2; i >= l; --i) {
      lmax[i] = max(a[i], lmax[i + 1]);
    }
    rmin[m] = a[m];
    for (int i = m + 1; i < r; ++i) {
      rmin[i] = min(a[i], rmin[i - 1]);
    }
    rmax[m] = a[m];
    for (int i = m + 1; i < r; ++i) {
      rmax[i] = max(a[i], rmax[i - 1]);
    }
    suff[r] = 0;
    for (int i = r - 1; i >= m; --i) {
      suff[i] = suff[i + 1] + (rmin[i].second == rmax[i].second);
    }
    cnt.fill(0);
    // for (int b = 0; b < 60; ++b) {
    //   prefmin[b][m] = prefmax[b][m] = 0;
    // }
    // for (int i = m; i < r; ++i) {
    //   for (int b = 0; b < 60; ++b) {
    //     prefmin[b][i + 1] = prefmin[b][i];
    //     prefmax[b][i + 1] = prefmax[b][i];
    //   }
    //   prefmin[rmin[i].second][i + 1]++;
    //   prefmax[rmax[i].second][i + 1]++;
    // }
    int pmin = m;
    int pmax = m;
    for (int i = m - 1; i >= l; --i) {
      auto[mn, mnb] = lmin[i];
      auto[mx, mxb] = lmax[i];
      while (pmin < r && rmin[pmin].first >= mn) {
        if (pmax <= pmin) {
          cnt[rmax[pmin].second]++;
        } else {
          cnt[rmin[pmin].second]--;
        }
        ++pmin;
      }
      while (pmax < r && rmax[pmax].first <= mx) {
        if (pmin <= pmax) {
          cnt[rmin[pmax].second]++;
        } else {
          cnt[rmax[pmax].second]--;
        }
        ++pmax;
      }
      if (mnb == mxb) {
        ans += min(pmin, pmax) - m;
      }
      if (pmin < pmax) {
        ans += cnt[mxb];
      } else {
        ans += cnt[mnb];
      }
      ans += suff[max(pmin, pmax)];
    }
  };
  solve(solve, 0, n);
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}