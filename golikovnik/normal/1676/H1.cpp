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

void solveTest() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  fenwick<int> f(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i] - 1;
    ans += f.get(x, n);
    f.upd(x, 1);
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
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}