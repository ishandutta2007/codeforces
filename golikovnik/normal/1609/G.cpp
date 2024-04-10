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

  //  max i: pref(i) <= sum
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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector<ll> a(n), b(m);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  ll a0 = a[0];
  ll b0 = b[0];
  vector<ll> da(n - 1), db(m - 1);
  for (int i = 0; i < n - 1; ++i) {
    da[i] = a[i + 1] - a[i];
  }
  for (int i = 0; i < m - 1; ++i) {
    db[i] = b[i + 1] - b[i];
  }

  fenwick<ll> fenw(m - 1);
  fenwick<ll> fenw1(m - 1);
  fenwick<ll> fenw2(m - 1);

  auto upd = [&](int at, ll d) {
    fenw.upd(at, d);
    fenw1.upd(at, d * at);
    fenw2.upd(at, d * at * at);
  };

  upd(0, db[0]);
  for (int i = 1; i < m - 1; ++i) {
    upd(i, db[i] - db[i - 1]);
  }
  
  auto get = [&](ll X, int r) {
    ll ans = 0;
    ans += fenw.pref(r) * (r + 1) * (2 * X - r);
    ans += fenw1.pref(r) * (-2 * X - 1);
    ans += fenw2.pref(r);
    assert(ans % 2 == 0);
    return ans / 2;
  };

  auto Solve = [&] {
    ll ans = (a0 + b0) * (n + m - 1);
    int pj = 0;
    da.push_back(LLONG_MAX);
    for (int pi = 0; pi < n; ++pi) {
      int nj = fenw.lower_bound(da[pi]);
      int upto = min({m - 1, n + m - 2 - pi, nj});
      smax(upto, pj);

      int X = n + m - 2 - pi;
      ans += get(X, upto - 1) - get(X, pj - 1);
      pj = upto;
      if (pi + pj < n + m - 2) {
        ans += da[pi] * (n + m - 2 - pi - pj);
      }
    }
    da.pop_back();
    return ans;
  };

  while (q--) {
    int t, k, d;
    cin >> t >> k >> d;
    if (t == 1) {
      int from = n - k;
      if (from == 0) {
        a0 += d;
        from = 1;
      }
      for (int i = from - 1; i < n - 1; ++i) {
        da[i] += d;
      }
    } else {
      int from = m - k;
      if (from == 0) {
        b0 += d;
        from = 1;
      }
      upd(from - 1, d);      
    }

    cout << Solve() << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}