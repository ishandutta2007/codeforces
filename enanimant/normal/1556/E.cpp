/*
 * author:  ADMathNoob
 * created: 08/29/21 10:35:25
 * problem: https://codeforces.com/contest/1556/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

class SegTree {
 public:
  struct Node {
    // declare variables with initial value (for leaves)
    long long maxL, maxR, mx;
    long long minL, minR, mn;
    long long sum;

    void apply(int p, int v) {
      maxL = maxR = mx = max(v, 0);
      minL = minR = mn = min(v, 0);
      sum = v;
    }
  };

  static inline Node unite(const Node& a, const Node& b) {
    Node res;
    res.maxL = max(a.maxL, a.sum + b.maxL);
    res.maxR = max(b.maxR, b.sum + a.maxR);
    res.mx = max({a.mx, b.mx, a.maxR + b.maxL});
    res.minL = min(a.minL, a.sum + b.minL);
    res.minR = min(b.minR, b.sum + a.minR);
    res.mn = min({a.mn, b.mn, a.minR + b.minL});
    res.sum = a.sum + b.sum;
    return res;
  }
  
 private:
  // note: with this "multiple perfect binary trees" implementation that
  // only uses 2*n nodes, st.tree[1] does not always contain the answer
  // to a query on the whole tree.
  // see https://codeforces.com/blog/entry/18051
  const int n;
  vector<Node> tree;

  inline void pull(int x) {
    tree[x] = unite(tree[2 * x], tree[2 * x + 1]);
  }

 public:  
  inline Node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr < n);
    int x = ll + n;
    int y = rr + n;
    Node L, R;
    bool usedL = false;
    bool usedR = false;
    while (x <= y) {
      if (x % 2 == 1) {
        L = (usedL ? unite(L, tree[x]) : tree[x]);
        usedL = true;
        ++x;
      }
      if (y % 2 == 0) {
        R = (usedR ? unite(tree[y], R) : tree[y]);
        usedR = true;
        --y;
      }
      x >>= 1;
      y >>= 1;
    }
    if (!usedL) {
      return R;
    }
    if (!usedR) {
      return L;
    }
    return unite(L, R);
  }
  
  inline Node get(int p) {
    return tree[p + n];
  }
  
  template <typename ...T>
  inline void modify(int p, const T&... v) {
    assert(0 <= p && p < n);
    int x = p + n;
    tree[x].apply(p, v...);
    for (x >>= 1; x >= 1; x >>= 1) {
      pull(x);
    }
  }
  
  SegTree(int _n) : n(_n), tree(2 * n) {
    assert(n > 0);
    for (int x = n - 1; x >= 1; x--) {
      pull(x);
    }
  }
  
  template <typename T>
  SegTree(const vector<T>& v) : n(v.size()), tree(2 * n) {
    assert(n > 0);
    for (int i = 0; i < n; i++) {
      tree[i + n].apply(i, v[i]);
    }
    for (int x = n - 1; x >= 1; x--) {
      pull(x);
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] -= x;
  }
  SegTree st(a);
  while (tt--) {
    int L, R;
    cin >> L >> R;
    --L; --R;
    auto nd = st.get(L, R);
    if (nd.sum != 0 || nd.maxL > 0 || nd.minR < 0) {
      cout << -1 << '\n';
      continue;
    }
    cout << max(nd.mx, -nd.mn) << '\n';
  }
  return 0;
}