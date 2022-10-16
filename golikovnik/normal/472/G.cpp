//  Copyright 2021 Nikita Golikov

//  pragmas
#if 1
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC target("popcnt")
#endif

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

  int const N = int(2e5) + 5;
  using bitset_t = bitset<N>;
  string s, t;
  cin >> s >> t;
  // int n = 200000;
  // int m = 200000;
  // for (int i = 0; i < n; ++i) {
  //   s.push_back('0' + (rand() & 1));
  // }
  // for (int i = 0; i < m; ++i) {
  //   t.push_back('0' + (rand() & 1));
  // }
  bitset_t bs, bt;
  int n = int(s.size());
  int m = int(t.size());
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      bs.set(i);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (t[i] == '1') {
      bt.set(i);
    }
  }
  int q;// = 400000;
  cin >> q;
  while (q--) {
    int l, r, len;
    cin >> l >> r >> len;
    // len = rnd(1, min(n, m));
    // l = rnd(0, n - len);
    // r = rnd(0, m - len);
    cout << (((bs >> l) ^ (bt >> r)) << (N - len)).count() << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}