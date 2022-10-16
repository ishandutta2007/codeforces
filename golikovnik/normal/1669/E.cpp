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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
  static auto const C = (ull) 7e18 + 23;
  static_assert(C % 2);

  ull const RANDOM = chrono::steady_clock::now().time_since_epoch().count();
  ull operator()(ull x) const {
    return __builtin_bswap64((x ^ RANDOM) * C);
  }

  template <class A, class B>
  ull operator()(pair<A, B> const& p) const {
    return (*this)(p.first) * 31 + (*this)(p.second);
  }

  ull operator()(string const& s) const {
    ull ans = 0;
    for (char ch : s) {
      ans *= 33;
      ans += ch - 'a' + 1;
    }
    return ans;
  }
};

template <class T> using hash_set = gp_hash_table<T, null_type, chash>;
template <class K, class V> using hash_map = gp_hash_table<K, V, chash>;

void solveTest() {
  int n; cin >> n;
  hash_map<string, int> cnt;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (s[0] != ch) {
        auto t = s; t[0] = ch; ans += cnt[t];
      }
      if (s[1] != ch) {
        auto t = s; t[1] = ch; ans += cnt[t];
      }
    }
    cnt[s]++;
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