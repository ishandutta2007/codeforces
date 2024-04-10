// July 30, 2019
// https://codeforces.com/contest/1199/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int INF = 2e9;


class SegmentTree {
public:
  struct Node {
    int assign = INF;

    void apply(int l, int r, int v) {
      if (v >= 0) {
        assert(l == r);
        assign = v; // point assign
      } else {
        // payout
        v = ~v;
        int a = assign;
        if (a < 0) {
          a = ~a;
        }
        if (a == INF || a < v) {
          assign = (l == r ? v : ~v);
        }
      }
    }
  };

  Node unite(const Node &a, const Node &b) const {
    // returns the Node corresponding to merging the two given nodes
    Node res;
    // insert unite instructions here
    return res;
  }

  void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    // insert push instructions here (for lazy propagation)
    if (tree[x].assign != INF) {
      tree[x + 1].apply(l, y, tree[x].assign);
      tree[z].apply(y + 1, r, tree[x].assign);
      tree[x].assign = INF;
    }
  }

  void pull(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
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
    pull(x, l, r);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    // builds the tree recursively using the vector v
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, l, r);
  }

  Node get(int x, int l, int r, int ll, int rr) {
    // returns a Node corresponding to the range [ll, rr]
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
    pull(x, l, r);
    return res;
  }

  template <typename M>
  void modify(int x, int l, int r, int ll, int rr, const M v) {
    // updates the range [ll, rr] using parameter v
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v);
    }
    pull(x, l, r);
  }

  SegmentTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  SegmentTree(const vector<M> &v) {
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

  template <typename M>
  void modify(int ll, int rr, const M v) {
    assert(0 <= ll && ll <= rr && rr < n);
    modify(0, 0, n - 1, ll, rr, v);
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
  #endif


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SegmentTree st(a);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      st.modify(p, p, x);
    } else {
      int x;
      cin >> x;
      st.modify(0, n - 1, ~x);
    }
  }
  for (int i = 0; i < n; i++) {
    int a = st.get(i).assign;
    if (a < 0) {
      a = ~a;
    }
    cout << a << (i < n - 1 ? ' ' : '\n');
  }


  return 0;
}