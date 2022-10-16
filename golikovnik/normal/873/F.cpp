//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

template <typename C = char, typename T = string>
struct suffix_tree {
  int const INF = (int) 1e9;
  struct node {
    int l, r, p, suff;
    map<C, int> nxt;
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
  T s;
  int pos{};

  void add_char(C ch) {
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

  explicit suffix_tree(T const& s_) : suffix_tree() {
    s.reserve(s_.size() + 1);
    for (auto ch : s_) {
      add_char(ch);
    }
    add_char(0);
    for (auto& x : tree) {
      x.r = min(x.r, (int) s_.size());
    }
    tree[0].nxt.erase(0);
    tree.pop_back();

    auto dfs = [&](auto&& dfs, int v) -> void {
      for (auto e : tree[v].nxt) {
        auto u = e.second;
        tree[u].d = tree[v].d + tree[u].len();
        dfs(dfs, u);
      }
    };
    dfs(dfs, 0);
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;
  auto ok = [&](int i) {
    return t[n - i - 1] == '0';
  };
  reverse(s.begin(), s.end());
  auto tree = suffix_tree(s).tree;
  i64 ans = 0;
  auto dfs = [&](auto&& dfs, int v) -> int {
    auto& nd = tree[v];
    int sz = 0;
    if (nd.is_leaf()) {
      sz += ok(nd.suff_start());
    }
    for (auto e : nd.nxt) {
      sz += dfs(dfs, e.second);
    }
    smax(ans, (i64) sz * nd.d);
    return sz;
  };
  dfs(dfs, 0);
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}