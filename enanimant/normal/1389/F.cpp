/*
 * author:  ADMathNoob
 * created: 01/01/22 11:26:29
 * problem: https://codeforces.com/contest/1389/problem/F
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
    int add = 0;
    int mx = 0;

    void apply(int l, int r, int v) {
      add += v;
      mx += v;
    }
  
    inline void push_onto(int l, int r, Node& a, Node& b) {
      int y = (l + r) >> 1;
      if (add != 0) {
        a.apply(l, y, add);
        b.apply(y + 1, r, add);
        add = 0;
      }
    }
  };

 private:
  static inline Node unite(const Node& a, const Node& b) {
    Node res;
    res.mx = max(a.mx, b.mx);
    return res;
  }
  
  const int n;
  vector<Node> tree;
  
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    tree[x].push_onto(l, r, tree[x + 1], tree[z]);
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

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
  
 public:
  SegTree(int _n) : n(_n), tree(2 * n - 1) {
    assert(n > 0);
    build(0, 0, n - 1);
  }

  template <typename T>
  SegTree(const vector<T>& v) : n(v.size()), tree(2 * n - 1) {
    assert(n > 0);
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

template <typename T>
void MakeUnique(vector<T>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

void Compress(vector<int>& a, const vector<int>& v) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
}

void Compress(vector<int>& a) {
  vector<int> v = a;
  MakeUnique(v);
  Compress(a, v);
}

template <typename T>
vector<int> Compressed(const vector<T>& a, const vector<T>& v) {
  int n = (int) a.size();
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = (int) (lower_bound(v.begin(), v.end(), a[i]) - v.begin());
  }
  return res;
}

template <typename T>
vector<int> Compressed(vector<T>& a) {
  vector<T> v = a;
  MakeUnique(v);
  return Compressed(a, v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> L(n), R(n), t(n);
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i] >> t[i];
    --t[i];
    xs.push_back(L[i]);
    xs.push_back(R[i]);
  }
  MakeUnique(xs);
  const int X = xs.size();
  Compress(L, xs);
  Compress(R, xs);
  vector<vector<vector<int>>> byR(X, vector<vector<int>>(2));
  for (int i = 0; i < n; i++) {
    byR[R[i]][t[i]].push_back(i);
  }
  vector<SegTree> st(2, SegTree(X + 1));
  for (int r = 0; r < X; r++) {
    for (int c : {0, 1}) {
      sort(byR[r][c].begin(), byR[r][c].end(), [&](int i, int j) {
        return L[i] > L[j];
      });
      int best = 0;
      int cnt = 0;
      for (int i : byR[r][c]) {
        cnt += 1;
        best = max(best, st[c ^ 1].get(0, L[i]).mx + cnt);
      }
      st[c].modify(r + 1, r + 1, best);
    }
    for (int c : {0, 1}) {
      for (int i : byR[r][c]) {
        st[c ^ 1].modify(0, L[i], +1);
      }
    }
  }
  int ans = max(st[0].get(0, X).mx, st[1].get(0, X).mx);
  cout << ans << '\n';
  return 0;
}