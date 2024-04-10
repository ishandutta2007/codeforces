//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

template <typename A, typename B, typename Cmp>
bool set_min(A &x, B const &y, Cmp &&cmp) {
  if (cmp(y, x)) {
    x = y;
    return true;
  }
  return false;
}

template <typename A, typename B>
bool set_min(A &x, B const &y) {
  return set_min(x, y, less<typename common_type<A, B>::type>{});
}

template <typename A, typename B>
bool set_max(A &x, B const &y) {
  return set_min(x, y, greater<typename common_type<A, B>::type>{});
}

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

template <typename K, typename V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag,
                         tree_order_statistics_node_update>;

//  https://codeforces.com/blog/entry/62393
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t
        FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return static_cast<size_t>(splitmix64(x + FIXED_RANDOM));
  }
};

#ifdef __cpp_deduction_guides
template <typename F>
struct rec_fun {
  F fun;

  rec_fun(F &&fun_) : fun(std::forward<F>(fun_)) {}

  template <typename... Args>
  decltype(auto) operator()(Args &&... args) const {
    return fun(*this, std::forward<Args>(args)...);
  }
};
#endif

#ifdef __cpp_inline_variables
template <typename T>
inline constexpr auto type_min = numeric_limits<T>::min();

template <typename T>
inline constexpr auto type_max = numeric_limits<T>::max();
#endif

//  fast alloc
#if 0
int const MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void* operator new(size_t n) {
  mpos += n;
  return (void*)(mem + mpos - n);
}
void operator delete (void*) noexcept {}
#endif

//  pragmas
#if 0
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#endif

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) {
    cin >> x >> y;
  }

  auto solve = [&](int k) {
    int const N = 1 << k;
    int const U = N - 1;
    vector<vector<pair<int, int>>> graph(N);
    int init;
    vector<int> dsu(N);
    iota(dsu.begin(), dsu.end(), 0);
    vector<int> r(N);
    rec_fun find = [&](auto&& self, int v) -> int {
      return dsu[v] == v ? v : dsu[v] = self(dsu[v]);
    };
    auto unite = [&](int u, int v) {
      u = find(u);
      v = find(v);
      if (u == v) return;
      if (r[u] == r[v]) ++r[u];
      if (r[u] > r[v]) swap(u, v);
      dsu[u] = v;
    };
    for (int i = 0; i < n; ++i) {
      auto x = a[i].first & U;
      auto y = a[i].second & U;
      init = x;
      graph[x].emplace_back(y, 2 * i + 1);
      graph[y].emplace_back(x, 2 * i);
      unite(x, y);
    }
    for (int i = 0; i < N; ++i) {
      if (graph[i].size() % 2) return;
      if (!graph[i].empty() && find(i) != find(init)) return;
    }
    cout << k << '\n';
    vector<int> ans;
    vector<bool> dead(n);
    vector<int> ptr(N);
    rec_fun euler = [&](auto&& self, int v) -> void {
      for (; ptr[v] != (int) graph[v].size(); ) {
        auto[u, id_u] = graph[v][ptr[v]++];
        auto id_e = id_u / 2;
        if (dead[id_e]) {
          continue;
        }
        dead[id_e] = true;
        self(u);
        cout << id_u + 1 << ' ' << (id_u ^ 1) + 1 << ' ';
      }
    };
    euler(init);
    exit(0);
  };

  for (int k = 20; ; --k) {
    solve(k);
  }
#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}