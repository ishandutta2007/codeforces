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
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  struct edge {
    int to;
    int w;
  };
  vector<vector<edge>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  double ans = 1e30;
  int ans_i = -1;
  vector<bool> alive(n, true);
  vector<int> sz(n);
  rec_fun calc_size = [&](auto&& self, int v, int p = -1) -> void {
    sz[v] = 1;
    for (auto e : graph[v]) {
      if (e.to != p && alive[e.to]) {
        self(e.to, v);
        sz[v] += sz[e.to];
      }
    }
  };
  auto find_centroid = [&](int v, int size) {
    int p = -1;
    while (true) {
      bool found = false;
      for (auto e : graph[v]) {
        if (e.to != p && alive[e.to] && sz[e.to] > size / 2) {
          found = true;
          p = v;
          v = e.to;
          break;
        }
      }
      if (!found) return v;
    }
  };
  rec_fun calc_ans = [&](auto&& self, int v, int p = -1, double d = 0)
      -> double {
    double cur = a[v] * d * sqrt(d);
    for (auto e : graph[v]) {
      if (e.to != p) {
        cur += self(e.to, v, d + e.w);
      }
    }
    return cur;
  };
  rec_fun calc_grad = [&](auto&& self, int v, int p, double d)
      -> double {
    double cur = a[v] * sqrt(d);
    for (auto e : graph[v]) {
      if (e.to != p) {
        cur += self(e.to, v, d + e.w);
      }
    }
    return cur;
  };
  rec_fun go = [&](auto&& self, int v) -> void {
    calc_size(v);
    int c = find_centroid(v, sz[v]);
    alive[c] = false;
    if (set_min(ans, calc_ans(c))) {
      ans_i = c;
    }
    double mx_grad = -1e30;
    int who = -1;
    for (auto e : graph[c]) {
      if (alive[e.to] && set_max(mx_grad, calc_grad(e.to, c, e.w))) {
        who = e.to;
      }
    }
    if (who >= 0) {
      self(who);
    }
  };
  go(0);
  cout << setprecision(12) << ans_i + 1 << ' ' << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}