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
inline constexpr auto type_min = numeric_limits<T>::lowest();

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
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p[x - 1] = y - 1;
  }
  struct node {
    int mn;
    int count;
    int lazy{};

    node operator+(node const& other) const {
      node ans{min(mn, other.mn), 0};
      for (auto& nd : {*this, other}) {
        if (ans.mn == nd.mn) ans.count += nd.count;
      }
      return ans;
    }
  };
  node const neutral{0, 1};
  int pw = 1;
  while (pw < n) pw *= 2;
  vector<node> rmq(2 * pw, neutral);
  for (int i = pw - 1; i > 0; --i) rmq[i] = rmq[2 * i] + rmq[2 * i + 1];
  auto pull = [&](int v) {
    rmq[v] = rmq[2 * v] + rmq[2 * v + 1];
  };
  auto apply = [&](int v, int val) {
    rmq[v].mn += val;
    rmq[v].lazy += val;
  };
  auto push = [&](int v) {
    apply(2 * v, rmq[v].lazy);
    apply(2 * v + 1, rmq[v].lazy);
    rmq[v].lazy = 0;
  };
  auto add = [&](int ql, int qr, int val) {
    rec_fun go = [&](auto&& self, int v, int l, int r) -> void {
      if (l >= qr || ql >= r) return;
      if (ql <= l && r <= qr) {
        apply(v, val);
        return;
      }
      push(v);
      int m = (l + r) / 2;
      self(2 * v, l, m);
      self(2 * v + 1, m, r);
      pull(v);
    };
    go(1, 0, pw);
  };
  auto get = [&](int ql, int qr) {
    rec_fun go = [&](auto&& self, int v, int l, int r) -> node {
      if (ql <= l && r <= qr) return rmq[v];
      push(v);
      int m = (l + r) / 2;
      if (qr <= m) {
        return self(2 * v, l, m);
      }
      if (ql >= m) {
        return self(2 * v + 1, m, r);
      }
      return self(2 * v, l, m) + self(2 * v + 1, m, r);
    };
    return go(1, 0, pw);
  };
  stack<pair<int, int>> mn, mx;
  i64 ans = 0;
  for (int r = 0; r < n; ++r) {
    auto val = p[r];
    add(r, r + 1, r);
    int cur = r;
    while (!mn.empty()) {
      auto[l, v] = mn.top();
      if (v < val) break;
      mn.pop();
      add(l, cur, v - val);
      cur = l;
    }
    mn.emplace(cur, val);
    cur = r;
    while (!mx.empty()) {
      auto[l, v] = mx.top();
      if (v > val) break;
      mx.pop();
      add(l, cur, val - v);
      cur = l;
    }
    mx.emplace(cur, val);
    ans += get(0, r + 1).count;
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}