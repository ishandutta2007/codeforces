/*
 * author:  ADMathNoob
 * created: 04/19/22 10:35:05
 * problem: https://codeforces.com/contest/1667/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

const int INF = 1e9;

class SegTree {
 public:
  struct Node {
    // declare variables with initial value (for leaves)
    int mx = -INF;

    void apply(int p, int v) {
      mx = max(mx, v);
    }
  };

  static inline Node unite(const Node& a, const Node& b) {
    Node res;
    res.mx = max(a.mx, b.mx);
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

template <typename T>
void MakeUnique(vector<T>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

void Compress(vector<int>& a, const vector<int>& v) {
  const int n = static_cast<int>(a.size());
  for (int i = 0; i < n; i++) {
    a[i] = static_cast<int>(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
  }
}

void Compress(vector<int>& a) {
  vector<int> v = a;
  MakeUnique(v);
  Compress(a, v);
}

template <typename T>
vector<int> Compressed(const vector<T>& a, const vector<T>& v) {
  const int n = static_cast<int>(a.size());
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = static_cast<int>(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pref[i + 1] = pref[i] + a[i];
    }
    vector<int> c = Compressed(pref);
    const int K = *max_element(c.begin(), c.end()) + 1;
    SegTree st_low(K);
    vector<int> eq(K, -INF);
    SegTree st_high(K);
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
      st_low.modify(c[i], dp[i] - i);
      eq[c[i]] = max(eq[c[i]], dp[i]);
      st_high.modify(c[i], dp[i] + i);
      int res = -INF;
      if (0 <= c[i + 1] - 1) {
        res = max(res, st_low.get(0, c[i + 1] - 1).mx + i + 1);
      }
      res = max(res, eq[c[i + 1]]);
      if (c[i + 1] + 1 <= K - 1) {
        res = max(res, st_high.get(c[i + 1] + 1, K - 1).mx - (i + 1));
      }
      dp[i + 1] = res;
    }
    cout << dp[n] << '\n';
  }
  return 0;
}