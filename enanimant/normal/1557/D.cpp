/*
 * author:  ADMathNoob
 * created: 08/09/21 10:35:22
 * problem: https://codeforces.com/contest/1557/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

class SegTree {
 public:
  struct Node {
    // declare variables with default value
    int mx = 0;
    int assign = -1;
    int last = -1;

    void apply(int l, int r, int v, int i) {
      assign = v;
      if (v > mx) {
        mx = v;
        last = i;
      }
    }
  };

  Node unite(const Node& a, const Node& b) const {
    Node res;
    res.mx = max(a.mx, b.mx);
    if (res.mx == a.mx) {
      res.last = a.last;
    } else {
      res.last = b.last;
    }
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].assign != -1) {
      tree[x + 1].apply(l, y, tree[x].assign, tree[x].last);
      tree[z].apply(y + 1, r, tree[x].assign, tree[x].last);
      tree[x].assign = -1;
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

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> row(n);
  vector<int> all;
  for (int i = 0; i < m; i++) {
    int r, from, to;
    cin >> r >> from >> to;
    --r;
    row[r].emplace_back(from, to);
    all.push_back(from);
    all.push_back(to + 1);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  const int X = (int) all.size() - 1;
  for (auto& v : row) {
    for (auto& [from, to] : v) {
      from = lower_bound(all.begin(), all.end(), from) - all.begin();
      to = lower_bound(all.begin(), all.end(), to + 1) - all.begin() - 1;
      assert(0 <= from && from <= to && to < X);
    }
  }
  SegTree st(X);
  vector<int> dp(n);
  vector<int> last(n);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    last[i] = -1;
    for (const auto [L, R] : row[i]) {
      auto nd = st.get(L, R);
      if (nd.mx + 1 > dp[i]) {
        dp[i] = nd.mx + 1;
        last[i] = nd.last;
      }
    }
    for (const auto [L, R] : row[i]) {
      st.modify(L, R, dp[i], i);
    }
  }
  int at = max_element(dp.begin(), dp.end()) - dp.begin();
  vector<bool> keep(n, false);
  while (at != -1) {
    keep[at] = true;
    at = last[at];
  }
  vector<int> ret;
  for (int i = 0; i < n; i++) {
    if (!keep[i]) {
      ret.push_back(i);
    }
  }
  cout << ret.size() << '\n';
  for (int i = 0; i < (int) ret.size(); i++) {
    if (i > 0) cout << ' ';
    cout << ret[i] + 1;
  }
  cout << '\n';
  return 0;
}