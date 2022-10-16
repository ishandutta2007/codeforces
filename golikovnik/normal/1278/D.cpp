//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define BITSET_ITER(i, bt) for (auto i = bt._Find_first(); i != bt.size();\
i = bt._Find_next(i))

using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

#ifdef GOLIKOV
mt19937 rng(566);
#else
mt19937 rng(static_cast<unsigned>(std::chrono::high_resolution_clock::now()
        .time_since_epoch()
        .count()));
#endif

template <typename T>
T rnd(T l, T r) {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution<T>(l, r)(rng);
  } else {
    return uniform_real_distribution<T>(l, r)(rng);
  }
}

template <typename T>
auto make_vector() {
  return T();
}

template <typename T, typename... Args>
auto make_vector(size_t n, Args... args) {
  return vector(n, make_vector<T>(args...));
}

template <typename... Args>
void read(Args& ... args) {
  (cin >> ... >> args);
}

constexpr bool golikov() {
#ifdef GOLIKOV
  return true;
#else
  return false;
#endif
}

template <bool flush = false>
void print() {
  if constexpr (golikov() || flush) {
    cout << endl;
  } else {
    cout << '\n';
  }
}

template <bool flush = false, typename T, typename... Args>
void print(T const& x, Args const& ... args) {
  cout << x;
  if constexpr (bool(sizeof...(args))) {
    cout << ' ';
  }
  print<flush>(args...);
}

template <typename T, typename F>
void foreach_rec(T& x, F&& f) {
  f(x);
}

template <typename T, typename F>
void foreach_rec(vector<T>& v, F&& f) {
  for (auto& vv : v) {
    foreach_rec(vv, forward<F>(f));
  }
}

using ui32 = uint32_t;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  if constexpr (golikov()) {
    freopen("in", "rt", stdin);
  } else {
//    string const TASK = "schedule";
//    freopen((TASK + ".in").c_str(), "rt", stdin);
//    freopen((TASK + ".out").c_str(), "wt", stdout);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(12) << fixed;

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> ind(2 * n, -1);
  for (int i = 0; i < n; ++i) {
    read(a[i].first, a[i].second);
    --a[i].first, --a[i].second;
    ind[a[i].second] = i;
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  };
  auto unite = [&](int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
      return false;
    }
    p[u] = v;
    return true;
  };

  vector<pair<int, int>> events;
  for (int i = 0; i < n; ++i) {
    events.emplace_back(a[i].first, ~i);
    events.emplace_back(a[i].second, i);
  }

  sort(events.begin(), events.end());
  set<int> ends;
  int nedges = 0;

  bool ok = true;
  for (auto[x, t] : events) {
    if (t < 0) {
      auto i = ~t;
      auto r = a[i].second;
      for (auto to_r : ends) {
        if (to_r > r) {
          break;
        }
        auto his_i = ind[to_r];
        if (!unite(i, his_i)) {
          print("NO");
          return 0;
        }
        ++nedges;
        if (nedges == n) {
          print("NO");
          return 0;
        }
      }
      ends.insert(r);
    } else {
      ends.erase(x);
    }
  }
  ok &= (nedges == n - 1);
  print(ok ? "YES" : "NO");
  return 0;
}