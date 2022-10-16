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

  auto st = clock();

  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  vector<int> w(n);
  vector<int> vals;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      vals.push_back(a[i][j]);
    }
    cin >> w[i];
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  auto getid = [&](int x) {
    return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
  };
  for (auto& r : a) for (auto& c : r) c = getid(c);
  int nv = int(vals.size());
  int const K = 13;
  int ans = INT_MAX;

  int const INF = int(1.1e9);

  vector<int> vv(nv);
  vector<int> mnsub(1 << K);
  while ((clock() - st) < 0.3 * CLOCKS_PER_SEC) {
    for (auto& x : vv) x = rnd(0, K - 1);
    fill(mnsub.begin(), mnsub.end(), INF);
    for (int i = 0; i < n; ++i) {
      int x = 0;
      for (int j = 0; j < m; ++j) {
        x |= 1 << vv[a[i][j]];
      }
      smin(mnsub[x], w[i]);
    }
    for (int b = 0; b < K; ++b) {
      for (int i = 0; i < (1 << K); ++i) {
        if (i >> b & 1) {
          smin(mnsub[i], mnsub[i ^ (1 << b)]);
        }
      }
    }
    for (int i = 0; i < (1 << K); ++i) {
      int x = mnsub[i];
      int y = mnsub[((1 << K) - 1) ^ i];
      if (x != INF && y != INF) smin(ans, x+y);
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}