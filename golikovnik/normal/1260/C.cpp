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

  int t;
  cin >> t;
  auto solve = [](i64 a, i64 b, i64 k) {
    auto g = std::gcd(a, b);
    a /= g;
    b /= g;
    if (a < b) {
      std::swap(a, b);
    }
    if (a == 1) {
      return true;
    }
    auto len = a - 1;
    auto can_fit = (len + b - 1) / b;
    return can_fit < k;
  };
//  auto stupid = [](i64 a, i64 b, i64 k) {
//    vector<int> need_a, need_b, can;
//    for (int i = 1; i <= 16; ++i) {
//      if (i % a == 0 && i % b == 0) {
//        can.push_back(i);
//      } else if (i % a == 0) {
//        need_a.push_back(i);
//      } else if (i % b == 0) {
//        need_b.push_back(i);
//      }
//    }
//    int can_choose = (int) can.size();
//    int min = 1e9 + 7;
//    for (int m = 0; m < (1 << can_choose); ++m) {
//      vector<int> va = need_a;
//      vector<int> vb = need_b;
//      for (int i = 0; i < can_choose; ++i) {
//        if (m & (1 << i)) {
//          va.push_back(can[i]);
//        } else {
//          vb.push_back(can[i]);
//        }
//      }
//      vector<int> all = va;
//      set<int> a_set(va.begin(), va.end());
//      set<int> b_set(vb.begin(), vb.end());
//      all.insert(all.end(), vb.begin(), vb.end());
//      sort(all.begin(), all.end());
//      int max = 0;
//      int cur = 1;
//      for (int i = 1; i < (int) all.size(); ++i) {
//        auto prev_color = a_set.count(all[i - 1]);
//        auto this_color = a_set.count(all[i]);
//        if (prev_color == this_color) {
//          cur++;
//        } else {
//          max = std::max(max, cur);
//          cur = 1;
//        }
//      }
//      max = std::max(max, cur);
//      assert(max != 1e9 + 7);
//      min = std::min(min, max);
//    }
//    return min < k;
//  };
//  for (int r = 1; r <= 6; ++r) {
//    for (int b = 1; b <= 6; ++b) {
//      for (int k = 2; k <= 6; ++k) {
//        cerr << solve(r, b, k) << ' ' << stupid(r, b, k) << '\n';
//        assert(solve(r, b, k) == stupid(r, b, k));
//        cerr << "passed\n";
//      }
//    }
//  }
  while (t--) {
    i64 a, b, k;
    cin >> a >> b >> k;
    print(solve(a, b, k) ? "OBEY" : "REBEL");
  }
  return 0;
}