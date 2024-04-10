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

  int n;
  cin >> n;
  auto iseven = [](char ch) {
    return ch == '0' || ch == '2' || ch == '4' || ch == '6' || ch == '8';
  };
  auto check = [&iseven](string const& s) {
    int sum = 0;
    int n = (int) s.size();
    int nzeros = 0;
    int neven = 0;
    for (char ch : s) {
      sum += ch - '0';
      sum %= 3;
      nzeros += ch == '0';
      neven += iseven(ch);
    }
    if (sum || !nzeros) {
      return false;
    }
    if (nzeros == n || nzeros > 1) {
      return true;
    }
    return neven > 1;
  };
  while (n--) {
    string s;
    cin >> s;
    cout << (check(s) ? "red" : "cyan") << '\n';
  }
  return 0;
}