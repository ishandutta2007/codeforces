//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

//  pragmas
#if 1
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("unroll-loops")
#endif

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

  int n, m;
  // n = 100000;
  // m = 100000;
  cin >> n >> m;
  vector<int> down(n, -1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    // y = i + 1;
    // x = rnd(1, i + 1);
    cin >> x >> y;
    down[y - 1] = x - 1;
  }
  int q;
  // q = 100000;
  cin >> q;
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; ++i) {
    int x, y;
    // x = rnd(1, n);
    // y = rnd(x, n);
    cin >> x >> y;
    queries[y - 1].emplace_back(x - 1, i);
  }

  vector<int> ans(q, -1);
  vector<int> go(n, -1);
  for (int y = 0; y < n; ++y) {
    go[y] = y;
    if (down[y] >= 0) {
      int from = down[y];
      for (int x = 0; x <= from; ++x) {
        if (go[x] >= from) {
          go[x] = y;
        }
      }
    }
    for (auto[from, i] : queries[y]) {
      ans[i] = go[from];
    }
  }

  for (auto x : ans) {
    cout << x + 1 << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}