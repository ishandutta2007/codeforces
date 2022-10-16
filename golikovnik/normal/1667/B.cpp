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

void solveTest() {
  int n; cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll const INF = ll(-1e7);
  vector<ll> dp(n + 1, INF);
  ll pref = 0;

  map<ll, ll> equal;
  map<ll, ll> less;
  map<ll, ll> greater;

  auto SetDP = [&](int at, ll val) {
    if (equal.count(pref)) {
      smax(equal[pref], val);
    } else {
      equal[pref] = val;
    }
    auto Go1 = [&] {
      auto it = less.upper_bound(pref);
      ll v = val - at;
      if (it != less.begin()) {
        --it;
        if (it->second >= v) {
          return;
        }
      }
      it = less.lower_bound(pref);
      while (it != less.end() && it->second <= v) {
        it = less.erase(it);
      }
      less[pref] = v;
    };
    auto Go2 = [&] {
            ll v = val + at;
      auto it = greater.lower_bound(pref);
      if (it != greater.end() && it->second >= v) {
        return;
      }
      while (true) {
        it = greater.upper_bound(pref);
        if (it == greater.begin()) break;
        --it;
        if (it->second <= v) {
          greater.erase(it);
        } else {
          break;
        }
      }
      greater[pref] = v;

    };
    Go1();
    Go2();
  };

  dp[0] = 0;
  SetDP(0, 0);

  for (int i = 0; i < n; ++i) {
    // if (i == 2) {
    //   cerr << "MAP\n";
    //   for (auto[k, v] : greater) {
    //     cerr << k << ' ' << v << '\n';
    //   }
    //   cerr << "END\n";
    // }

    pref += a[i];
    if (equal.count(pref)) {
      smax(dp[i + 1], equal[pref]);
    }
    {
      auto it = less.lower_bound(pref);
      if (it != less.begin()) {
        smax(dp[i + 1], prev(it)->second + i + 1);
      }
    }
    {
      auto it = greater.upper_bound(pref);
      if (it != greater.end()) {
        smax(dp[i + 1], it->second - i - 1);
      }
    }
    SetDP(i + 1, dp[i + 1]);
  }

  // for (int i = 0; i <= n; ++i) {
  //   cerr << i << ' ' << dp[i] << '\n';
  // }

  cout << dp[n] << '\n';
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