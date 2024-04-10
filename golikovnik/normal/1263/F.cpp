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

  int nleaves;
  cin >> nleaves;
  vector<int> n(2);
  vector<vector<int>> p(2);
  vector<vector<int>> leaf(2, vector<int>(nleaves));
  vector<vector<int>> leaf_id(2);
  vector<vector<int>> max_leaf(2);
  vector<vector<int>> min_leaf(2);
  vector<vector<vector<int>>> graph(2);
  vector<vector<int>> sz(2);
  auto read_tree = [&](int i) {
    cin >> n[i];
    p[i].resize(n[i]);
    graph[i].resize(n[i]);
    for (int j = 1; j < n[i]; ++j) {
      int who;
      cin >> who;
      p[i][j] = who - 1;
      graph[i][who - 1].push_back(j);
    }
    leaf_id[i].resize(n[i], -1);
    for (int j = 0; j < nleaves; ++j) {
      int x;
      cin >> x;
      leaf[i][j] = x - 1;
      leaf_id[i][x - 1] = j;
    }
    sz[i].resize(n[i]);
    max_leaf[i].resize(n[i]);
    min_leaf[i].resize(n[i]);
    function<int(int)> dfs = [&](int v) {
      sz[i][v] = 1;
      max_leaf[i][v] = leaf_id[i][v];
      min_leaf[i][v] = leaf_id[i][v];
      if (leaf_id[i][v] < 0) {
        min_leaf[i][v] = INT_MAX;
      }
      for (int u : graph[i][v]) {
        sz[i][v] += dfs(u);
        max_leaf[i][v] = std::max(max_leaf[i][v], max_leaf[i][u]);
        min_leaf[i][v] = std::min(min_leaf[i][v], min_leaf[i][u]);
      }
      return sz[i][v];
    };
    dfs(0);
  };
  read_tree(0);
  read_tree(1);
  vector<int> dp(nleaves + 1);
  for (int i = 0; i < nleaves; ++i) {
    for (int who = 0; who < 2; ++who) {
      auto cur = leaf[who][i];
      while (max_leaf[who][cur] <= i) {
        auto min = min_leaf[who][cur];
        dp[i + 1] = std::max(dp[i + 1], dp[min] + sz[who][cur] - (!cur));
        if (!cur) {
          break;
        }
        cur = p[who][cur];
      }
    }
  }
  print(dp.back());
  return 0;
}