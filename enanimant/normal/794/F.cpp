/*
 * author:  ADMathNoob
 * created: 04/02/21 16:43:51
 * problem: https://codeforces.com/contest/794/problem/F
 */

/*
g++ 794F.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 794F.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

const int D = 10;
const array<int, D> ID = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
long long power10[9];

class SegTree {
 public:
  struct Node {
    // declare variables with default value
    array<int, D> change = ID;
    array<long long, D> value;

    void apply(int l, int r, const array<int, D>& p, bool init = false) {
      if (init) {
        copy(p.begin(), p.end(), value.begin());
        return;
      }
      array<int, D> nchange;
      array<long long, D> nvalue;
      nvalue.fill(0);
      for (int i = 0; i < D; i++) {
        nchange[i] = p[change[i]];
        nvalue[p[i]] += value[i];
      }
      swap(change, nchange);
      swap(value, nvalue);
    }
  };

  Node unite(const Node& a, const Node& b) const {
    Node res;
    for (int i = 0; i < D; i++) {
      res.value[i] = a.value[i] + b.value[i];
    }
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    tree[x + 1].apply(l, y, tree[x].change);
    tree[z].apply(y + 1, r, tree[x].change);
    tree[x].change = ID;
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

  power10[0] = 1;
  for (int i = 1; i < 9; i++) {
    power10[i] = power10[i - 1] * 10;
  }

  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int m = (int) s.size();
    vector<int> d(m);
    array<int, D> by_digit;
    by_digit.fill(0);
    for (int j = 0; j < m; j++) {
      d[j] = s[m - 1 - j] - '0';
      by_digit[d[j]] += power10[j];
    }
    st.modify(i, i, by_digit, true);
  }
  while (tt--) {
    int op, ll, rr;
    cin >> op >> ll >> rr;
    --ll;
    --rr;
    if (op == 1) {
      int from, to;
      cin >> from >> to;
      array<int, D> p = ID;
      p[from] = to;
      st.modify(ll, rr, p);
    } else {
      auto nd = st.get(ll, rr);
      long long ans = 0;
      for (int d = 0; d < D; d++) {
        ans += nd.value[d] * d;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}