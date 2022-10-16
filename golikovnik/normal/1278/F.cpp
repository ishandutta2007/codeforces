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

  ui32 const MOD = 998244353;
  auto add = [MOD](ui32& x, ui32 y) {
    x += y;
    if (x >= MOD) {
      x -= MOD;
    }
  };
  auto sub = [MOD](ui32& x, ui32 y) {
    return x = (x >= y ? x - y : x - y + MOD);
  };
  auto mul = [MOD](ui32& x, ui64 y) {
    return x = x * y % MOD;
  };
  auto prod = [&](ui32 x, ui32 y) {
    return mul(x, y);
  };
  auto pw = [&](ui32 x, ui32 d) {
    ui32 result = 1;
    while (d) {
      if (d & 1u) {
        mul(result, x);
      }
      mul(x, x);
      d >>= 1u;
    }
    return result;
  };
  auto inv = [&](ui32 x) {
    return pw(x, MOD - 2);
  };

  ui32 n, m, k;
  read(n, m, k);
  vector<ui32> fact(k + 1), rfact(k + 1);
  fact[0] = 1;
  for (ui32 i = 0; i < k; ++i) {
    fact[i + 1] = prod(fact[i], i + 1);
  }
  rfact.back() = inv(fact.back());
  for (int i = k - 1; i >= 0; --i) {
    rfact[i] = prod(rfact[i + 1], i + 1);
  }
  auto choose = [&prod, &fact, &rfact](ui32 n, ui32 k) -> ui32 {
    return prod(fact[n], prod(rfact[k], rfact[n - k]));
  };
  vector<ui32> uniq_pw(k + 1);
  for (ui32 i = 0; i <= k; ++i) {
    uniq_pw[i] = pw(i, k);
  }

  ui32 prob = inv(m);

  ui32 choose_uniq = n;
  ui32 prob_uniq = prob;
  ui32 answer = 0;

  auto inc = [&mul, &inv](ui32& x, ui32 n, ui32 k) {
    mul(x, inv(k + 1));
    mul(x, n - k);
  };
  auto get_f = [&prod, &choose, &add, &sub, &uniq_pw](ui32 uniq) {
    ui32 result = 0;
    bool add_g = true;
    for (int i = uniq; i >= 0; --i) {
      ui32 g = prod(choose(uniq, i), uniq_pw[i]);
      if (add_g) {
        add(result, g);
      } else {
        sub(result, g);
      }
      add_g ^= true;
    }
    return result;
  };
  for (ui32 uniq = 1; uniq <= min(n, k); ++uniq) {
    add(answer, prod(choose_uniq, prod(get_f(uniq), prob_uniq)));
    mul(prob_uniq, prob);
    inc(choose_uniq, n, uniq);
  }
  print(answer);
  return 0;
}