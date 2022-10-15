// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct SegTree {
  struct node {
    int l = 0, r = 0;
    long long m = 0;
    void modify(int dl, int dr) {
      l += dl;
      r += dr;
      m = l && r;
    }
    node operator+(const node& x) {
      node res;
      res.l = l + x.l;
      res.r = r + x.r;
      res.m = m + x.m + 1LL * r * x.l;    
      return res;
    }
  };

  vector<node> tree;
  int n;
  SegTree(int _n) : n(_n) {
    tree.resize(n << 1);  
  }
  node get(int l, int r) {
    node res_l, res_r;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        res_l = res_l + tree[l];
        ++l;
      }
      if (r & 1) {
        --r;        
        res_r = tree[r] + res_r;
      }
    }
    return res_l + res_r;
  }
  void modify(int p, int dl, int dr) {
    tree[p += n].modify(dl, dr);
    p >>= 1;
    while (p > 0) {
      tree[p] = tree[p << 1] + tree[p << 1 | 1];
      p >>= 1;
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int Q, D;
  cin >> Q >> D;
  vector<int> A(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> A[i];
    --A[i];
  }

  const int MAX = *max_element(A.begin(), A.end()) + D + 1;
  SegTree st(MAX);
  vector<int> in(MAX);
  long long ans = 0;
  for (auto i : A) {
    int mul = (in[i] ? -1 : 1);
    in[i] ^= 1;
    auto G = [&](int x) {
      return 1LL * x * (x - 1) / 2;
    };
    if (D > 1) {
      debug("I", st.get(i + 1, i + D).r);
      debug("K", st.get(max(0, i - D), i - 1).r);
      long long delta = G(st.get(max(0, i - D), i - 1).r) + G(st.get(i + 1, i + D).r);
      delta += st.get(i + 1, i + D - 1).m;
      debug("J", st.get(i + 1, i + D - 1).m); 
      ans += delta * mul;
    }
    st.modify(i, 0, mul);
    st.modify(i + D, mul, 0);
    cout << ans << '\n';
  }
}