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

#define int int64_t

void solveTest() {
  int n; cin >> n;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> pos(26);
  for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'].push_back(i);
  }
  for (auto& vec : pos) {
    reverse(vec.begin(), vec.end());
  }

  int ans = LLONG_MAX;
  fenwick<int> fenw(n);
  for (int i = 0; i < n; ++i) {
    fenw.upd(i, 1);
  }

  auto get = [&](int i) {
    return fenw.pref(i - 1);
  };
  auto Set = [&](int i) {
    fenw.upd(i, -1);
  };

  int ops = 0;
  for (int i = 0; i < n; ++i) {
    int y = t[i] - 'a';
    for (int x = 0; x < y; ++x) {
      if (!pos[x].empty()) {
        smin(ans, ops + get(pos[x].back()));
      }
    }
    if (!pos[y].empty()) {
      int p = pos[y].back();
      ops += get(p);
      Set(p);
      pos[y].pop_back();
    } else {
      break;
    }
  }

  cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

int32_t main() {
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