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
  int n;
  ll t;
  cin >> n >> t;
  vector<ll> g(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i] >> c[i];
  }
  vector<ll> d(n);
  ll sumd = 0;
  for (int i = 0; i < n - 1; ++i) {
    cin >> d[i];
    sumd += d[i];
  }
  ll shift = 0;

  map<ll, tuple<ll, ll, ll>> dp;
  dp[0] = make_tuple(t, 0, 0);

  auto getPoint = [&](ll x) -> ll {
    auto it = dp.upper_bound(x);
    assert(it != dp.begin());
    --it;
    auto[L, v] = *it;
    auto[to, f, s] = v;
    if (s == 0) {
      return 0;
    }
    return f - (x - L);
  };
  auto getLoc = [&](ll i) {
    return (i + t - shift) % t;
  };
  auto getVal = [&](ll i) {
    return getPoint(getLoc(i));
  };
  auto split = [&](ll x) {
    if (x == t) return;
    debug(x);
    auto it = dp.upper_bound(x);
    if (it != dp.begin()) {
      --it;
      if (it->first != x) {
        auto L = it->first;
        auto[to, f, s] = it->second;
        debug(L);
        debug(to);
        assert(to > x);
        dp.erase(it);
        dp[L] = make_tuple(x, f, s);
        dp[x] = make_tuple(to, f - s * (x - L), s);
      }
    }
  };
  auto Assign = [&](ll L, ll R, ll f) {
    split(L);
    split(R);
    while (true) {
      auto it = dp.lower_bound(L);
      if (it == dp.end() || it->first >= R) {
        break;
      }
      dp.erase(it);
    }
    dp[L] = make_tuple(R, f, 1);
  };

  for (int i = n - 1; i >= 0; --i) {
    ll from = (t - c[i]) % t;

    //  [from; to) assign dp[x] = dp'[x + d[i]]
    ll val = getVal((d[i] - c[i] + t) % t) + t - g[i];
    //  [to; from) assign val + fval, fval - 1, ...

    ll hefrom = (from + d[i]) % t;
    ll hepos = getLoc(hefrom);

    ll L = (hepos + g[i]) % t;
    ll len = t - g[i];
    //  assign val, val - 1, ... from L, length len

    ll toEnd = t - L;
    if (toEnd >= len) {
      Assign(L, L + len, val);
    } else {
      Assign(L, t, val);
      val -= toEnd;
      len -= toEnd;
      Assign(0, len, val);
    }

    ll nshift = (from + t - hepos) % t;

    shift = nshift;

    // for (auto it : dp) {
    //   cerr << it.first << ' ' << get<0>(it.second) << '\n';
    // }
    // cerr << '\n';
  }
  ll ans = ll(1e18);
  for (auto[k, v] : dp) {
    auto[to, f, s] = v;
    if (s == 0) {
      smin(ans, 0);
    } else {
      smin(ans, f - (to - 1 - k));
    }
  }
  cout << sumd + ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests = 1;
  for (int tt_ = 1; tt_ <= _tests; ++tt_) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}