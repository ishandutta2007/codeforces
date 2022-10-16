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

struct DSU {
  int n;
  vector<int> dsu;

  DSU(int n_) : n(n_), dsu(n, -1) {}

  int find(int v) {
    return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (-dsu[u] > -dsu[v]) swap(u, v);
    dsu[v] += dsu[u];
    dsu[u] = v;
    return true;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  int size(int v) {
    return -dsu[find(v)];
  }
};

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

struct chash {
  static auto const C = (ui64) 7e18 + 23;
  static_assert(C % 2);

  ui64 const RANDOM = chrono::steady_clock::now().time_since_epoch().count();
  ui64 operator()(ui64 x) const {
    return __builtin_bswap64((x ^ RANDOM) * C);
  }

  template <class A, class B>
  ui64 operator()(pair<A, B> p) const {
    return (*this)(p.first) * 31 + (*this)(p.second);
  }
};

template <class T> using hash_set = gp_hash_table<T, null_type, chash>;
template <class K, class V> using hash_map = gp_hash_table<K, V, chash>;

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  int const MAX = int(1e6 + 5);
  vector<int> a(n);
  vector<int> id(MAX, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    id[a[i]] = i;
  }
  DSU dsu(MAX);
  vector<int> primeDiv(MAX, -1);
  for (int v = 2; v < MAX; ++v) {
    if (primeDiv[v] < 0) {
      for (int v2 = v; v2 < MAX; v2 += v) {
        primeDiv[v2] = v;
        if (id[v2] >= 0) {
          dsu.unite(v, v2);
        }
      }
    }
  }
  hash_set<pair<int, int>> st;
  vector<int> ps;
  for (int x : a) {
    ps.clear();
    ps.push_back(dsu.find(x));
    auto cur = x + 1;
    while (cur > 1) {
      auto p = primeDiv[cur];
      while (cur % p == 0) cur /= p;
      auto root = dsu.find(p);
      for (auto who : ps) {
        st.insert(minmax(who, root));
      }
      ps.push_back(root);
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    int x = dsu.find(a[u]), y = dsu.find(a[v]);
    if (x == y) {
      cout << 0;
    } else {
      cout << 2 - (st.find(minmax(x, y)) != st.end());
    }
    cout << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}