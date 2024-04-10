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

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    auto get = [&](char ch) {
      return count(s.begin(), s.end(), ch);
    };
    auto l = get('L');
    auto r = get('R');
    auto u = get('U');
    auto d = get('D');
    l = min(l, r);
    u = min(u, d);
    if (!l) {
      if (!u) {
        print(0);
        continue;
      }
      print(2);
      print("UD");
      continue;
    }
    if (!u) {
      print(2);
      print("LR");
      continue;
    }
    print(2 * (l + u));
    for (int i = 0; i < l; ++i) {
      cout << "L";
    }
    for (int i = 0; i < u; ++i) {
      cout << "D";
    }
    for (int i = 0; i < l; ++i) {
      cout << "R";
    }
    for (int i = 0; i < u; ++i) {
      cout << "U";
    }
    print();
  }
  return 0;
}