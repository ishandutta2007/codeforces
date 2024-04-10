// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

const int inf = int(1e9) + 1;
struct SegTreeBeats {
  struct node {
    int mx = 0, mn = 0;
    long long sum = 0;
    int tag = inf;
    void set(int x) {
      sum = mx = mn = x;  
    }

    bool out(int md) {
      return (md > mx);
    }

    bool modify(int l, int r, int v) {
      if (mx != mn) {
        return false;
      }

      tag = v;
      sum -= 1LL * (r - l + 1) * (mx - v);
      mx = mn = v;
      return true;
    }

    node operator+(node x) {
      node res;
      res.sum = x.sum + sum;
      res.mx = max(x.mx, mx);
      res.mn = min(x.mn, mn);
      return res;
    }
  };

  int n;
  vector<node> tree;
  node emp;
  SegTreeBeats(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }

  #define def int mid = (l + r) >> 1, rv = v + ((mid - l + 1) << 1)
  void push(int v, int l, int r) {
    def;
    if (tree[v].tag != emp.tag) {
      tree[v + 1].modify(l, mid, tree[v].tag);
      tree[rv].modify(mid + 1, r, tree[v].tag);
      tree[v].tag = emp.tag;
    }
  }


  void modify(int v, int l, int r, int ll, int rr, int md) {
    if (l >= ll && r <= rr && tree[v].modify(l, r, tree[v].mx % md)) {
      return;
    }
    def;
    push(v, l, r);
    if (ll <= mid && !tree[v + 1].out(md)) {
      modify(v + 1, l, mid, ll, rr, md);
    }
    if (rr > mid && !tree[rv].out(md)) {
      modify(rv, mid + 1, r, ll, rr, md);
    }
    tree[v] = tree[v + 1] + tree[rv];
  }

  node get(int v, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) {
      return tree[v];
    }   
    def;
    push(v, l, r);
    if (mid >= ll) {
      if (rr > mid) {
        return get(v + 1, l, mid, ll, rr) + get(rv, mid + 1, r, ll, rr); 
      } else {
        return get(v + 1, l, mid, ll, rr);
      }
    } else {
      return get(rv, mid + 1, r, ll, rr);
    }
  }

  void point_modify(int v, int l, int r, int p, int x) {
    if (l == r) {
      tree[v].set(x);
      return;
    }
    def;
    push(v, l, r);
    if (p <= mid) {
      point_modify(v + 1, l, mid, p, x);
    } else {
      point_modify(rv, mid + 1, r, p, x);
    }
    tree[v] = tree[v + 1] + tree[rv];
  }

  node get(int l, int r) {
    assert(l >= 0 && l <= r && r < n);
    return get(0, 0, n - 1, l, r);
  }

  void modify(int l, int r, int md) {
    assert(l >= 0 && l <= r && r < n && md < inf);
    modify(0, 0, n - 1, l, r, md);    
  }
  
  void point_modify(int p, int x) {
    assert(p >= 0 && p < n);
    point_modify(0, 0, n - 1, p, x);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  SegTreeBeats st(N);
  for (int i = 0; i < N; ++i) {
    st.point_modify(i, A[i]);
  }

  while (M--) {
    int T;
    cin >> T;
    if (T == 1) {
      int L, R;
      cin >> L >> R;
      --L, --R;
      cout << st.get(L, R).sum << '\n';
    } else if (T == 2) {
      int L, R, MD;
      cin >> L >> R >> MD;
      --L, --R;
      st.modify(L, R, MD);
    } else {
      int I, X;
      cin >> I >> X;
      --I;
      st.point_modify(I, X);
    }
  }
}