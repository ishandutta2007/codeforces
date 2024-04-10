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
//    std::freopen("in", "rt", stdin);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  read(n, m);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    int prev;
    cin >> prev;
    --prev;
    for (int j = 0; j < k - 1; ++j) {
      int x;
      cin >> x;
      --x;
      adj[prev].push_back(x);
      adj[x].push_back(prev);
      prev = x;
    }
  }
  vector<vector<int>> graph(n, vector<int>(n, -1));
  for (int s = 0; s < n; ++s) {
    queue<int> q({s});
    graph[s][s] = 0;
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (int u : adj[v]) {
        if (graph[s][u] < 0) {
          graph[s][u] = graph[s][v] + 1;
          q.push(u);
        }
      }
    }
  }
  int first = -1;
  int f_first = -1;
  for (int i = 0; i < n; ++i) {
    int mx = 0;
    for (auto nei : graph[i]) {
      int sz = 0;
      for (int x = 0; x < n; ++x) {
        if (graph[nei][x] < graph[x][i]) {
          ++sz;
        }
      }
      mx = std::max(mx, sz);
    }
    if (first < 0 || mx < f_first) {
      f_first = mx;
      first = i;
    }
  }
  for (int qi = 0; qi < n; ++qi) {
    vector<int> to_consider(n);
    std::iota(to_consider.begin(), to_consider.end(), 0);
    bool first_it = true;
    while (true) {
      int cur = -1;
      if (first_it) {
        cur = first;
      } else {
        int f_cur = -1;
        for (int i : to_consider) {
          int mx = 0;
          for (auto nei : adj[i]) {
            int sz = 0;
            for (int x : to_consider) {
              if (graph[nei][x] < graph[x][i]) {
                ++sz;
              }
            }
            mx = std::max(mx, sz);
          }
          if (cur < 0 || mx < f_cur) {
            f_cur = mx;
            cur = i;
          }
        }
      }
      first_it = false;
      print<true>(cur + 1);
      string response;
      cin >> response;
      if (response == "FOUND") {
        break;
      }
      int who;
      cin >> who;
      --who;
      vector<int> new_consider;
      for (int x : to_consider) {
        auto d1 = graph[x][who];
        auto d2 = graph[x][cur];
        if (d1 < d2) {
          new_consider.push_back(x);
        }
      }
      to_consider.swap(new_consider);
    }
  }
  return 0;
}