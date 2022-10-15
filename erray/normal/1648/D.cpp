// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;


template<typename node> 
struct SegTree {
  vector<node> tree;
  int n;
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1));
  }  
  void modify(int p, node x) {
    p += n;
    tree[p] = x;
    p >>= 1;
    while (p >= 1) {
      tree[p] = tree[p << 1] + tree[p << 1 | 1];
      p >>= 1;
    }  
  }

  node get(int l, int r) {
    l += n;
    r += n + 1;
    node left, right;
    while (l < r) {
      if (l & 1) {
        left = left + tree[l];
        ++l;
      }
      if (r & 1) {
        --r;
        right = tree[r] + right;
      }
      l >>= 1;
      r >>= 1;
    }
    node res = left + right;
    return res;
  }
};
 

const long long inf = (long long) 1e16;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  array<vector<int>, 3> A;
  for (int j = 0; j < 3; ++j) {
    A[j].resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[j][i];
    }
  }

  vector<long long> start(N);
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      start[i] = start[i - 1] - A[1][i - 1];
    }
    start[i] += A[0][i];
  }

  vector<long long> end(N);
  for (int i = N - 1; i >= 0; --i) {
    if (i < N - 1) {
      end[i] = end[i + 1] - A[1][i + 1];
    }
    end[i] += A[2][i];
  }


  vector<int> L(Q), R(Q), K(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> L[i] >> R[i] >> K[i];
    --L[i], --R[i];
  }

  debug(start);
  debug(end);
  vector<long long> best = start;
  {
    struct node {
      long long mx = -inf;
      node operator+(const node& ot) {
        node res;
        res.mx = max(mx, ot.mx);
        return res;
      }
    };

    SegTree<node> st(N);
    for (int i = 0; i < N; ++i) {
      st.modify(i, node{best[i]});
    }

    vector<array<int, 3>> qs(Q);
    for (int i = 0; i < Q; ++i) {
      qs[i] = {L[i], R[i], K[i]};
    }

    sort(qs.begin(), qs.end());
    for (auto[l, r, k] : qs) {
      long long res = st.get(l, r).mx - k;
      debug(l, r, k, res);
      if (r + 1 < N && best[r + 1] < res) {
        best[r + 1] = res;
        st.modify(r + 1, node{res});
      }
    }
  }
  
  struct node {
    long long l = -inf, r = -inf;
    long long ans = -inf;
    node operator+(const node& ot) {
      node res;
      res.l = max(l, ot.l);
      res.r = max(r, ot.r);
      res.ans = max({l + ot.r, ans, ot.ans});
      return res;             
    }
  };

  SegTree<node> st(N);
  debug(best, end);  
  for (int i = 0; i < N; ++i) {
    st.modify(i, node{best[i], end[i], best[i] + end[i]});
  }

  long long ans = -inf;
  for (int i = 0; i < Q; ++i) {
    ans = max(ans, st.get(L[i], R[i]).ans - K[i]);
  }
  cout << ans + accumulate(A[1].begin(), A[1].end(), 0LL) << '\n';
}