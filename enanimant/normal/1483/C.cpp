/*
 * author:  ADMathNoob
 * created: 03/21/21 09:12:46
 * problem: https://codeforces.com/contest/1483/problem/C
 */

/*
g++ 1483C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors && a
g++ 1483C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors -ggdb && gdb a
g++ 1483C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors && a


*/

#include "bits/stdc++.h"

using namespace std;

const long long INF = (long long) 1e18;

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
  // cerr << v << '\n';
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

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                      \
  cerr << "[" << #__VA_ARGS__ << "]: "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class SegTree {
 public:
  struct Node {
    long long mx = -INF;

    void apply(int l, int r, long long v) {
      mx = v;
    }
  };

  Node unite(const Node& a, const Node& b) const {
    Node res;
    res.mx = max(a.mx, b.mx);
    return res;
  }

  inline void push(int x, int l, int r) {
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

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int n;
  cin >> n;
  vector<long long> h(1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    h.push_back(x);
  }
  vector<long long> b(1, -INF);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  vector<long long> dp(n + 1, -INF);
  vector<long long> best(n + 1, 0);
  multiset<long long> s;
  dp[0] = 0;
  vector<int> stk(1, 0);
  SegTree st(n + 1);
  st.modify(0, 0, dp[0]);
  for (int i = 1; i <= n; i++) {
    while (h[i] < h[stk.back()]) {
      int j = stk.back();
      stk.pop_back();
      s.erase(s.find(best[j] + b[j]));
    }
    debug(stk.back(), i - 1);
    best[i] = st.get(stk.back(), i - 1).mx;

    stk.push_back(i);
    s.insert(best[i] + b[i]);
    debug(dp);
    debug(stk);
    debug(s);
    dp[i] = *prev(s.end());
    st.modify(i, i, dp[i]);
  }
  cout << dp[n] << '\n';

  return 0;
}