//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

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

  int n;
  read(n);
  vector<int> a(2 * n);
  for (auto& x : a) {
    read(x);
  }
  std::sort(a.begin(), a.end());
  auto total = std::accumulate(a.begin() + 2, a.end(), 0);
  auto const need = n - 1;
  int const MAX = 3e6;
  using bt = std::bitset<MAX>;
  vector<bt> dp(need + 1);
  auto prev = make_vector<int>(need + 1, MAX);
  dp[0][0] = true;
  for (int i = 2; i < 2 * n; ++i) {
    auto x = a[i];
    auto new_dp = dp;
    for (int take = 1; take <= need; ++take) {
      auto old_dp = new_dp[take];
      new_dp[take] |= (dp[take - 1] << x);
      auto xr = old_dp ^ new_dp[take];
      for (auto b = xr._Find_first(); b < xr.size(); b = xr._Find_next(b)) {
        prev[take][b] = i;
      }
    }
    dp.swap(new_dp);
  }
  int best = -1;
  int best_delta = INT_MAX;
  auto& last = dp[need];
  for (auto i = last._Find_first(); i != last.size(); i = last._Find_next(i)) {
    auto delta = std::abs<int>(total - 2 * i);
    if (delta < best_delta) {
      best_delta = delta;
      best = i;
    }
  }
  assert(best >= 0);
  vector<bool> used(2 * n);
  int cur = need;
  vector<int> first;
  while (cur) {
    auto who = prev[cur][best];
    assert(who >= 2);
    assert(!used[who]);
    used[who] = true;
    first.push_back(who);
    --cur;
    best -= a[who];
  }
  vector<int> second;
  for (int i = 2; i < 2 * n; ++i) {
    if (!used[i]) {
      second.push_back(i);
    }
  }
  std::sort(first.begin(), first.end(), [&](auto i, auto j) {
    return a[i] < a[j];
  });
  std::sort(second.begin(), second.end(), [&](auto i, auto j) {
    return a[i] > a[j];
  });
  cout << a[0] << ' ';
  for (auto i : first) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (auto i : second) {
    cout << a[i] << ' ';
  }
  cout << a[1] << '\n';
  return 0;
}