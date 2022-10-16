//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

#define BITSET_ITER(i, bt) for (auto i = bt._Find_first(); i != bt.size();\
i = bt._Find_next(i))

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::map;
using std::set;
using std::pair;
using std::tuple;
using std::unique_ptr;
using std::shared_ptr;
using std::unordered_map;
using std::unordered_set;
using std::multiset;
using std::sort;
using std::reverse;
using std::function;
using std::make_pair;
using std::make_tuple;
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;

#ifdef GOLIKOV
std::mt19937 rng(566);
#else
std::mt19937 rng(static_cast<unsigned>(std::chrono::high_resolution_clock::now()
.time_since_epoch().count()));
#endif

template <typename T>
T rnd(T l, T r) {
  if constexpr (std::is_integral_v<T>) {
    return std::uniform_int_distribution<T>(l, r)(rng);
  } else {
    return std::uniform_real_distribution<T>(l, r)(rng);
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
    cout << std::endl;
  } else {
    cout << '\n';
  }
}

template <bool flush = false, typename T, typename... Args>
void print(T const& x, Args const& ... args) {
  cout << x;
  if constexpr (sizeof...(args)) {
    cout << ' ';
  }
  print<flush>(args...);
}

int main() {
  if constexpr (golikov()) {
    std::freopen("in", "rt", stdin);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n, k, t;
  read(n, m, k, t);
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  sort(a.rbegin(), a.rend());
  struct trap {
    int l;
    int r;
    int d;
  };
  vector<trap> traps(k);
  for (auto&[l, r, d] : traps) {
    cin >> l >> r >> d;
  }
  sort(traps.begin(), traps.end(), [](auto const& x, auto const& y) {
    return x.d > y.d;
  });
  size_t constexpr N = 2e5 + 5;
  std::bitset<N> used;
  used.set();
  auto insert_trap = [&](size_t l, size_t r) {
    for (auto i = !l ? used._Find_first() : used._Find_next(l - 1);
              i <= r;
              i = used._Find_next(i)) {
      used.reset(i);
    }
  };
  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    auto new_d = a[i];
    while (ptr < k && traps[ptr].d > new_d) {
      insert_trap(traps[ptr].l, traps[ptr].r);
      ++ptr;
    }
    auto time = static_cast<int>(m + 1 + 2 * (N - used.count()));
    if (time > t) {
      print(i);
      return 0;
    }
  }
  print(n);
  return 0;
}