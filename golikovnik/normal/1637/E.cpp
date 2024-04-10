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
};

template <class T> using hash_set = gp_hash_table<T, null_type, chash>;
template <class K, class V> using hash_map = gp_hash_table<K, V, chash>;

void solveTest() {
  int n, m;
  cin >> n >> m;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; ++cnt[x];
  }
  hash_set<pair<int, int>> banned;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y; banned.insert(make_pair(x, y));
  }
  vector<vector<int>> byCnt(n+1);
  for (auto it : cnt) {
    byCnt[it.second].push_back(it.first);
  }
  vector<int> goodcnts;
  for (int i = 1; i <= n; ++i) {
    if (!byCnt[i].empty()) {
      goodcnts.push_back(i);
    }
  }
  ll ans = 0;

  auto Solve = [&](int i, int j) {
    int ci = goodcnts[i];
    int cj = goodcnts[j];
    auto& vi = byCnt[ci];
    auto& vj = byCnt[cj];
    int si = int(vi.size());
    int sj = int(vj.size());

    auto f = [&](int x, int y) {
      return (ll(x) + ll(y)) * (ci + cj);
    };

    vector<int> ptr(si);
    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < si; ++i) {
      ptr[i] = sj - 1;
      pq.emplace(f(vi[i], vj[sj - 1]), i);
    }
    while (!pq.empty()) {
      auto[val, i] = pq.top(); pq.pop();
      int x = vi[i];
      int y = vj[ptr[i]];
      if (x != y && banned.find(minmax(x, y)) == banned.end()) {
        smax(ans, val);
        return;
      }
      if (ptr[i] > 0) {
        pq.emplace(f(vi[i], vj[--ptr[i]]), i);
      }
    }
  };

  int sz = int(goodcnts.size());
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j <= i; ++j) {
      Solve(i, j);
    }
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