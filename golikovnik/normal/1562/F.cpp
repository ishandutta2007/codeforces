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

ll ask(int i, int j) {
  assert(i != j);
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  ll t; cin >> t; return t;
}

void solve(int) {
  int n; cin >> n;

  if (n == 3) {
    auto a01 = ask(0, 1);
    auto a02 = ask(0, 2);
    auto a12 = ask(1, 2);
    auto g = gcd(a01, gcd(a02, a12));
    vector answers{gcd(a01, a02), gcd(a01, a12), gcd(a02, a12)};
    (*max_element(answers.begin(), answers.end())) /= g;
    cout << "! ";
    for (auto x : answers) cout << x << ' ';
    cout << endl;
    return;
  }

  if (n < 100) {
    vector qs(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        qs[i][j] = ask(i, j);
      }
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
      ll me = 0;
      for (int j = 0; j < n; ++j) {
        me = gcd(me, qs[max(i, j)][min(i, j)]);
      }
      cout << me << ' ';
    }
    cout << endl;
    return;
  }

  vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
  shuffle(ord.begin(), ord.end(), rng);
  int pr = 0;
  int who = 0;
  for (int i = 0; i + 1 < n && i < 9980; i += 2) {
    auto x = ask(ord[i], ord[i + 1]);
    int mp = -1;
    for (int p = 2; ll(p) * p <= x; ++p) {
      if (x % p == 0) {
        mp = p;
        while (x % p == 0) x /= p;
      }
    }
    if (x > 1) mp = x;
    if (smax(pr, mp)) who = i;
  }

  auto out = [&](int id) {
    id = ord[id];
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
      if (i == id) {
        ans[i] = pr;
      } else {
        auto result = ask(i, id);
        assert(result % pr == 0);
        result /= pr;
        assert(result % pr != 0);
        ans[i] = result;
      }
    }
    cout << "! ";
    for (auto x : ans) cout << x << ' ';
    cout << endl;
  };

  for (int i = 0; i < n; ++i) {
    if (i != ord[who] && i != ord[who + 1]) {
      auto x = ask(i, ord[who]);
      auto y = ask(i, ord[who + 1]);
      if (x % pr == 0) {
        assert(y % pr != 0);
        out(who);
        return;
      }
      if (y % pr == 0) {
        assert(x % pr != 0);
        out(who + 1);
        return;
      }
    }
  }

  assert(false);
}

int main() {
#ifdef GOLIKOV
  // assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif

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