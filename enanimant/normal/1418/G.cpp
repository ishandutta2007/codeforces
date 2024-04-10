/*
 * author:  ADMathNoob
 * created: 07/19/21 17:31:42
 * problem: https://codeforces.com/contest/1418/problem/G
 */

/*
g++ 1418G.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1418G.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3


For each number, it has to appear 0 or 3 times. This statement has the form
(x1 or y1) and (x2 or y2) and ... and (x_n or y_n).

Manipulating this, we can reduce the problem to finding the area of the
complement of a union of rectangles.
*/

#include <bits/stdc++.h>

using namespace std;

// can't have namespaces, else to_string(int) is hidden, for example

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(const char c) {
  string s = "'";
  s += c;
  s += "'";
  return s;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_commas() {
}

template <typename Head, typename... Tail>
void debug_commas(Head H, Tail... T) {
  // comma before each element
  cerr << ", " << to_string(H);
  debug_commas(T...);
}

template <typename Head, typename... Tail>
void debug_better(Head H, Tail... T) {
  cerr << "[" << to_string(H);
  debug_commas(T...);
  cerr << "]" << endl;
}

// print an empty line
void debug_out() {
#ifdef _DEBUG
  cerr << endl;
#endif
}

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                    \
  cerr << "" << #__VA_ARGS__ << ": "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class SegTree {
 public:
  struct Node {
    // declare variables with default value
    int add = 0;
    int mn = 0;
    int cnt = 1;

    void apply(int l, int r, int v) {
      add += v;
      mn += v;
    }
  };

  Node unite(const Node& a, const Node& b) const {
    Node res;
    res.mn = min(a.mn, b.mn);
    res.cnt = 0;
    if (a.mn == res.mn) {
      res.cnt += a.cnt;
    }
    if (b.mn == res.mn) {
      res.cnt += b.cnt;
    }
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<Node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename T>
  void build(int x, int l, int r, const vector<T>& v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  Node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    Node res;
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else if (ll > y) {
      res = get(z, y + 1, r, ll, rr);
    } else {
      res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
    }
    pull(x, z);
    return res;
  }

  template <typename... T>
  void modify(int x, int l, int r, int ll, int rr, const T&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const Node&)>& f) {
    if (l == r) {
      return l;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const Node&)>& f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const Node&)>& f) {
    if (l == r) {
      return l;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const Node&)>& f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  SegTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename T>
  SegTree(const vector<T>& v) {
    n = (int) v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  Node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr < n);
    return get(0, 0, n - 1, ll, rr);
  }

  Node get(int p) {
    assert(0 <= p && p < n);
    return get(0, 0, n - 1, p, p);
  }

  // due to variadic templates, we cannot also have modify(int p, const T&... v)
  template <typename... T>
  void modify(int ll, int rr, const T&... v) {
    assert(0 <= ll && ll <= rr && rr < n);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  int find_first(int ll, int rr, const function<bool(const Node&)>& f) {
    assert(0 <= ll && ll <= rr && rr < n);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const Node&)>& f) {
    assert(0 <= ll && ll <= rr && rr < n);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> where(n, vector<int>(1, -1));
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    --a;
    where[a].push_back(i);
  }
  for (int x = 0; x < n; x++) {
    where[x].push_back(n);
  }
  vector<vector<tuple<int, int, int>>> events(n + 1);
  // vector<vector<int>> covered(n, vector<int>(n));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < i; j++) {
  //     covered[i][j] = 1;
  //   }
  // }
  auto Add = [&](int x1, int x2, int y1, int y2) {
    assert(0 <= x1 && x1 < n && 0 <= x2 && x2 < n);
    assert(0 <= y1 && y1 < n && 0 <= y2 && y2 < n);
    debug(x1, x2, y1, y2);
    events[x1].emplace_back(y1, y2, +1);
    events[x2 + 1].emplace_back(y1, y2, -1);
    // for (int i = x1; i <= x2; i++) {
    //   for (int j = y1; j <= y2; j++) {
    //     covered[i][j] = 1;
    //   }
    // }
  };
  for (int x = 0; x < n; x++) {
    int cnt = (int) where[x].size();
    for (int z = 1; z < cnt - 1; z++) {
      int x1 = where[x][z - 1] + 1;
      int x2 = where[x][z];
      {
        int y1 = x2;
        int y2 = (z + 2 < cnt ? where[x][z + 2] - 1 : n - 1);
        Add(x1, x2, y1, y2);
      }
      if (z + 3 < cnt && where[x][z + 3] < n) {
        int y1 = where[x][z + 3];
        int y2 = n - 1;
        Add(x1, x2, y1, y2);
      }
    }
  }
  // debug(covered);
  SegTree st(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (const auto [L, R, add] : events[i]) {
      st.modify(L, R, add);
    }
    auto nd = st.get(i, n - 1);
    debug(nd.mn, nd.cnt);
    if (nd.mn == 0) {
      ans += nd.cnt;
    }
  }
  cout << ans << '\n';
  return 0;
}