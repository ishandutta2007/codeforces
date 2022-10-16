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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  a.insert(a.begin(), 0);

  using I = __int128;
  auto eval = [&](ll lambda, ll len, ll x) {
    I cost = I(lambda) * x;
    ++x;
    ll big = (len + x - 1) / x;
    ll small = len / x;
    auto res = cost + I(small) * small * (x - len % x) + I(big) * big * (len % x);
    return res;
  };
  auto solveOne = [&](ll lambda, ll len) {
    I const INF = I(1e36);
    pair<I, ll> res{INF, -1};
    using ld = long double;
    ll pt = lambda > 0 ? clamp<ld>((1 + sqrtl(1 + 4 * ld(len) * len / lambda)), 0, len - 1) / 2 : len - 1;
    for (ll d = -3; d <= 3; ++d) {
      ll x = clamp<ll>(pt + d, 0, len - 1);
      smin(res, make_pair(eval(lambda, len, x), x));
    }
    return res;
  };
  auto solve = [&](ll lambda) -> pair<I, ll> {
    I cost{};
    ll used{};
    for (int i = 0; i < n; ++i) {
      auto[c, u] = solveOne(lambda, a[i + 1] - a[i]);
      cost += c;
      used += u;
    }
    return make_pair(cost - I(used) * lambda, used);
  };

  ll m; cin >> m;
  ll left = 0;
  ll right = (ll) 2e18;
  while (left + 1 != right) {
    ll middle = (left + right) / 2;
    auto[cost, segs] = solve(middle);
    (cost <= m ? left : right) = middle;
  }
  auto[costL, segsL] = solve(left);
  auto[costR, segsR] = solve(right);
  m = clamp<ll>(m, costL, costR);

  if (costL == costR) {
    assert(segsL == segsR);
    cout << segsL << '\n';
  } else {
    cout << segsL - (ll) (I(segsL - segsR) * (m - costL) / (costR - costL)) << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}