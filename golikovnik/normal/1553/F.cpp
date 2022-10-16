//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

struct item {
  i64 s{};
  int c{};

  void operator+=(item other) {
    s += other.s;
    c += other.c;
  }

  item operator-(item other) {
    return {s - other.s, c - other.c};
  }
};

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
    return pref(r - 1) - pref(l - 1);
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int const MAX = int(3e5 + 10);
  int n;
  cin >> n;
  fenwick<item> f1(MAX), f2(MAX);
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    for (int mul = 0; mul < MAX; mul += x) {
      auto res = f1.get(mul, min(mul + x, MAX));
      ans += res.s - i64(mul) * res.c;
    }
    auto res = f2.pref(x);
    ans += i64(x) * res.c - res.s;
    for (int mul = 0; mul < MAX; mul += x) {
      f2.upd(mul, {mul, 1});
      f2.upd(min(mul + x, MAX), {-mul, -1});
    }
    f1.upd(x, {x, 1});
    cout << ans << ' ';
  }
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}