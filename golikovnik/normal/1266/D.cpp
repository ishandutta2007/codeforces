//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

#define BITSET_ITER(i, bt) for (auto i = bt._Find_first(); i != bt.size();\
i = bt._Find_next(i))

using namespace std;

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

  int n, m;
  cin >> n >> m;

  vector<i64> bal(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    i64 d;
    read(u, v, d);
    --u, --v;
    bal[u] += d;
    bal[v] -= d;
  }
  vector<int> neg, pos;
  for (int i = 0; i < n; ++i) {
    if (bal[i] < 0) {
      neg.push_back(i);
    } else if (bal[i] > 0) {
      pos.push_back(i);
    }
  }
  vector<map<int, i64>> es(n);
  for (int i : pos) {
    while (bal[i]) {
      int j = neg.back();
      auto cap = -bal[j];
      auto push = min(cap, bal[i]);
      es[i][j] += push;
      bal[i] -= push;
      bal[j] += push;
      if (!bal[j]) {
        neg.pop_back();
      }
    }
  }
  vector<tuple<int, int, i64>> ans;
  for (int i = 0; i < n; ++i) {
    for (auto[j, w] : es[i]) {
      ans.emplace_back(i + 1, j + 1, w);
    }
  }
  print(ans.size());
  for (auto[i, j, w] : ans) {
    print(i, j, w);
  }
  return 0;
}