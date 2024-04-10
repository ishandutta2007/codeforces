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

//  http://acm.math.spbu.ru/~sk1/algo/matchings/gabow5.cpp.html
struct Edmonds {
  int n, T;
  vector<vector<int>> graph;
  vector<int> pa, p, used, base;

  vector<int> toJoin;

  explicit Edmonds(int n) : n(n), T(0), graph(n), pa(n, -1), p(n), used(n), base(n) {}

  void add(int v, int u) {
    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  int getBase(int i) {
    return base[i] == i ? i : base[i] = getBase(base[i]);
  }

  void mark_path(int v, int x, int b, vector<int>& path) {
    for (; getBase(v) != b; v = p[x]) {
      p[v] = x;
      x = pa[v];
      toJoin.push_back(v);
      toJoin.push_back(x);
      if (!used[x]) {
        used[x] = ++T;
        path.push_back(x);
      }
    }
  }

  bool go(int v) {
    for (int x : graph[v]) {
      int b;
      int bv = getBase(v);
      int bx = getBase(x);
      if (bv == bx) {
        continue;
      } else if (used[x]) {
        vector<int> path;
        toJoin.clear();
        if (used[bx] < used[bv]) {
          mark_path(v, x, b = bx, path);
        } else {
          mark_path(x, v, b = bv, path);
        }
        for (int z : toJoin) {
          base[getBase(z)] = b;
        }
        for (int z : path) {
          if (go(z)) {
            return true;
          }
        }
      } else if (p[x] == -1) {
        p[x] = v;
        if (pa[x] == -1) {
          for (int y; x != -1; x = v) {
            y = p[x];
            v = pa[y];
            pa[x] = y;
            pa[y] = x;
          }
          return true;
        }
        if (!used[pa[x]]) {
          used[pa[x]] = ++T;
          if (go(pa[x])) {
            return true;
          }
        }
      }
    }
    return false;
  }

  void init_dfs() {
    for (int i = 0; i < n; ++i) {
      used[i] = 0;
      p[i] = -1;
      base[i] = i;
    }
  }

  bool dfs(int root) {
    used[root] = ++T;
    return go(root);
  }

  int match() {
    int ans = 0;
    for (int v = 0; v < n; ++v) {
      for (int x : graph[v]) {
        if (pa[v] == -1 && pa[x] == -1) {
          pa[v] = x;
          pa[x] = v;
          ans++;
          break;
        }
      }
    }
    init_dfs();
    for (int i = 0; i < n; ++i) {
      if (pa[i] == -1 && dfs(i)) {
        ans++;
        init_dfs();
      }
    }
    return ans;
    //  i -> pa[i]
  }
};

int main() {
  if constexpr (golikov()) {
    std::freopen("in", "rt", stdin);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    read(n, m);

    Edmonds graph(2 * n + m);
    for (int i = 0; i < n; ++i) {
      graph.add(i, i + n);
      for (int j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        if (ch == '1') {
          graph.add(i, n + n + j);
          graph.add(n + i, n + n + j);
        }
      }
    }
    print(graph.match() - n);
  }
  return 0;
}