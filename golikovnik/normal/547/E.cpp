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

struct suffix_tree {
  int const INF = (int) 1e9;
  struct node {
    int l, r, p, suff;
    map<int, int> nxt;
    int d{};

    int len() const {
      return r - l;
    }

    bool is_leaf() const {
      return nxt.empty();
    }

    int suff_start() const {
      return r - d;
    }

    node(int l_, int r_, int p_, int suff_ = -1) :
        l(l_), r(r_), p(p_), suff(suff_) {}
  };
  vector<node> tree;
  int cur{};
  vector<int> s;
  int pos{};

  void add_char(int ch) {
    auto create_leaf = [&](int p) {
      tree[p].nxt[ch] = (int) tree.size();
      tree.emplace_back((int) s.size(), INF, p);
      return (int) tree.size() - 1;
    };

    while (true) {
#define v tree[cur]
      //  vertex
      if (pos >= v.r) {
        if (v.nxt.count(ch)) {
          cur = v.nxt[ch];
          pos = v.l + 1;
          break;
        }
        tree[create_leaf(cur)].suff = cur;
        cur = v.suff;
        if (~cur) {
          pos = v.r;
        } else {
          cur = pos = 0;
          break;
        }
        continue;
      }
      //  edge
      if (s[pos] == ch) {
        ++pos;
        break;
      }
      //  split
      auto u_i = (int) tree.size();
#define u tree[u_i]
      tree.emplace_back(v.l, pos, v.p);
      v.p = u_i;
      v.l = pos;
      tree[u.p].nxt[s[u.l]] = u_i;
      u.nxt[s[pos]] = cur;
      create_leaf(u_i);

      cur = tree[u.p].suff;
      pos = u.l;
      if (!~cur) {
        cur = 0, ++pos;
      }

      while (pos < u.r) {
        cur = v.nxt[s[pos]];
        pos += v.r - v.l;
      }
      u.suff = pos == u.r ? cur : (int) tree.size();
      pos = v.r - (pos - u.r);
#undef u
#undef v
    }
    s.push_back(ch);
  }

  suffix_tree() {
    tree.emplace_back(0, 0, -1, -1);
  }

  explicit suffix_tree(vector<int> const& s_) : suffix_tree() {
    s.reserve(s_.size() + 1);
    for (int ch : s_) {
      add_char(ch);
    }
    add_char(0);
    for (auto& x : tree) {
      x.r = min(x.r, (int) s_.size());
    }
    tree[0].nxt.erase(0);
    tree.pop_back();

    rec_fun dfs = [&](auto&& self, int v) -> void {
      for (auto e : tree[v].nxt) {
        auto u = e.second;
        tree[u].d = tree[v].d + tree[u].len();
        self(u);
      }
    };
    dfs(0);
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<vector<int>> a(n);
  vector<int> start(n), end(n);
  int extra = 27;
  vector<int> total;
  map<int, int> starts;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    start[i] = (int) total.size();
    starts[start[i]] = i;
    for (char ch : s) {
      auto id = ch - 'a' + 1;
      a[i].push_back(id);
      total.push_back(id);
    }
    end[i] = (int) total.size();
    if (i + 1 != n) total.push_back(extra++);
  }
  auto tree = suffix_tree(total).tree;
  vector<int> loc(n, -1);
  {
    vector<pair<int, int>> st;
    rec_fun dfs = [&](auto&& self, int v) -> void {
      auto& vt = tree[v];
      st.emplace_back(vt.d, v);
      if (vt.is_leaf()) {
        auto pos = vt.suff_start();
        if (starts.count(pos)) {
          auto who = starts[pos];
          auto len_who = (int) a[who].size();
          auto it = lower_bound(st.begin(), st.end(), make_pair(len_who, 0));
          assert(it != st.end());
          loc[who] = it->second;
        }
      }
      for (auto e : vt.nxt) {
        self(e.second);
      }
      st.pop_back();
    };
    dfs(0);
  }

  int nvs = (int) tree.size();
  struct query {
    int l;
    int r;
    int i;
  };
  vector<vector<query>> qs(nvs);
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --r, --k;
    qs[loc[k]].push_back({start[l], end[r], i});
  }
  vector<i64> ans(q);
  rec_fun dfs = [&](auto&& self, int v) -> ordered_set<int> {
    auto& vt = tree[v];
    ordered_set<int> st;
    if (vt.is_leaf()) {
      st.insert(vt.suff_start());
    }
    for (auto e : vt.nxt) {
      auto son = self(e.second);
      if (son.size() > st.size()) son.swap(st);
      for (auto x : son) st.insert(x);
    }
    for (auto[l, r, i] : qs[v]) {
      ans[i] = st.order_of_key(r) - st.order_of_key(l);
    }
    return st;
  };
  dfs(0);
  for (auto x : ans) cout << x << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}