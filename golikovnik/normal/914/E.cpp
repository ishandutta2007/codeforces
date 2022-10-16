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

int const ALPHA = 20;
int cnt[1 << ALPHA];
int const N = (int) 2e5 + 10;
vector<int> graph[N];
bool alive[N];
int sz[N];
int a[N];
i64 ans[N];
vector<pair<int, int>> comp[N];
int val[N];
int level[N];
i64 pref[N];
vector<int> centroid_children[N];

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    a[i] = 1 << (s[i] - 'a');
  }

  fill_n(alive, n, true);
  rec_fun calc_size = [&](auto&& self, int v, int p = -1) -> int {
    sz[v] = 1;
    for (int u : graph[v]) {
      if (alive[u] && u != p) {
        sz[v] += self(u, v);
      }
    }
    return sz[v];
  };
  auto find_centroid = [&](int v, int p, int size) {
    while (true) {
      bool found = false;
      for (int u : graph[v]) {
        if (alive[u] && u != p && sz[u] * 2 > size) {
          found = true;
          p = v;
          v = u;
          break;
        }
      }
      if (!found) {
        return v;
      }
    }
  };
  rec_fun go = [&](auto&& self, int v, int lev = 0) -> int {
    calc_size(v);
    auto c = find_centroid(v, -1, sz[v]);
    alive[c] = false;
    level[c] = lev;
    rec_fun dfs = [&](auto&& self, int v, int p = -1) -> void {
      comp[c].emplace_back(v, p);
      for (auto u : graph[v]) {
        if (u != p && alive[u]) {
          self(u, v);
        }
      }
    };
    dfs(c);
    for (int u : graph[c]) {
      if (alive[u]) {
        centroid_children[c].push_back(self(u, lev + 1));
      }
    }
    return c;
  };
  go(0);
  for (int c = 0; c < n; ++c) {
    for (auto[v, p] : comp[c]) {
      val[v] = (p >= 0 ? val[p] : 0) ^ a[v];
      ++cnt[val[v]];
    }
    for (auto[v, p] : comp[c]) {
      pref[v] += cnt[val[v] ^ a[c]];
      for (int b = 0; b < ALPHA; ++b) {
        pref[v] += cnt[val[v] ^ a[c] ^ (1 << b)];
      }
    }
    for (auto[v, p] : comp[c]) {
      --cnt[val[v]];
    }
    for (auto ch : centroid_children[c]) {
      for (auto[v, p] : comp[ch]) {
        ++cnt[val[v]];
      }
      for (auto[v, p] : comp[ch]) {
        pref[v] -= cnt[val[v] ^ a[c]];
        for (int b = 0; b < ALPHA; ++b) {
          pref[v] -= cnt[val[v] ^ a[c] ^ (1 << b)];
        }
      }
      for (auto[v, p] : comp[ch]) {
        --cnt[val[v]];
      }
    }
    for (int i = (int) comp[c].size() - 1; i >= 0; --i) {
      auto[v, p] = comp[c][i];
      if (v != c) {
        pref[p] += pref[v];
        ans[v] += pref[v];
      } else {
        ans[v] += (pref[v] + 1) / 2;
      }
      pref[v] = 0;
    }
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}