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

  int n;
  cin >> n;
  vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  };
  auto unite = [&](int v, int u) {
    v = find(v);
    u = find(u);
    if (u == v) {
      return false;
    }
    p[u] = v;
    return true;
  };
  vector<vector<int>> have(26);
  for (int i = 0; i < n; ++i) {
    vector<bool> chars(26);
    string s;
    cin >> s;
    for (char ch : s) {
      chars[ch - 'a'] = true;
    }
    for (int ch = 0; ch < 26; ++ch) {
      if (chars[ch]) {
        have[ch].push_back(i);
      }
    }
  }
  int ans = n;
  for (int i = 0; i < 26; ++i) {
    int k = (int) have[i].size();
    for (int j = 0; j + 1 < k; ++j) {
      ans -= unite(have[i][j], have[i][j + 1]);
    }
  }
  print(ans);
  return 0;
}