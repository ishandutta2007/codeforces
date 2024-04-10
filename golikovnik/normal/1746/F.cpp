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

template <class T>
struct fenwick {
  int n;
  vector<T> fenw;

  fenwick(int n_) : n(n_), fenw(n_) {}

  void upd(int at, T delta) {
    for (; at < n; at |= at + 1) fenw[at] += delta;
  }

  T pref(int r) {
    T res{};
    for (; r >= 0; r = (r & (r + 1)) - 1) res += fenw[r];
    return res;
  }

  T get(int l, int r) {
    if (l >= r) return 0;
    return pref(r - 1) - pref(l - 1);
  }

  //  max i: pref(i-1) <= sum
  int lower_bound(T sum) {
    int pw = 1 << __lg(n);
    int ans = 0;
    for (; pw > 0; pw /= 2) {
      if (ans + pw > n) {
        continue;
      }

      auto val = fenw[ans + pw - 1];
      if (sum >= val) {
        sum -= val;
        ans += pw;
      }
    }
    return ans;
  }
};

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

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    all.push_back(a[i]);
  }
  vector<tuple<int, int, int>> qs(q);
  for (auto& [l, r, k] : qs) {
    int t; cin >> t;
    if (t == 1) {
      cin >> l >> r;
      --l;
      k = -1;
      all.push_back(r);
    } else {
      cin >> l >> r >> k;
      --l;
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  auto getid = [&](int x) {
    return int(lower_bound(all.begin(), all.end(), x) - all.begin());
  };
  int qq = int(all.size());
  int const TIMES = 35;
  vector hh(TIMES, vector<ull>(qq));
  for (int i = 0; i < TIMES; ++i) {
    for (int j = 0; j < qq; ++j) {
      hh[i][j] = rng() % ull(1e12);
    }
  }
  vector fw(TIMES, fenwick<ull>(n));
  auto add = [&](int i, int d) {
    int v = getid(a[i]);
    for (int it = 0; it < TIMES; ++it) {
      fw[it].upd(i, hh[it][v] * d);
    }
  };
  for (int i = 0; i < n; ++i) {
    add(i, 1);
  }
  for (auto[l, r, k] : qs) {
    if (k < 0) {
      add(l, -1);
      a[l] = r;
      add(l, 1);
    } else {
      int ok = 1;
      for (int it = 0; it < TIMES && ok; ++it) {
        ok &= fw[it].get(l, r) % k == 0;
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}