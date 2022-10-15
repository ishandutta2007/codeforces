// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<long long> sum(N);
  vector<array<int, 4>> QS(Q);
  for (int i = 0; i < Q; ++i) {
    string T;
    cin >> T;
    if (T == "Color") {
      cin >> QS[i][1] >> QS[i][2] >> QS[i][3];
      --QS[i][1], --QS[i][2], --QS[i][3]; 
      QS[i][0] = 0;
    } else if (T == "Add") {
      cin >> QS[i][1] >> QS[i][2];
      --QS[i][1];
      QS[i][0] = 1;
      sum[QS[i][1]] += QS[i][2];
    } else {
      cin >> QS[i][1];
      --QS[i][1];
      QS[i][0] = 2;
    }
  }

  struct node {
    long long tag = 0;
    int c = 0;
  };
  auto Pull = [&](node& res, node x, node y) {
    res.c = (x.c == y.c ? x.c : -1);
  };

  vector<node> tree(N * 2);
  #define def int mid = (l + r) >> 1, rv = v + ((mid - l + 1) << 1)
  auto Push = [&](int v, int l, int r) {
    def;
    if (tree[v].tag != 0) {
      tree[v + 1].tag += tree[v].tag;
      tree[rv].tag += tree[v].tag;
      tree[v].tag = 0;
    }
    if (tree[v].c != -1) {
      tree[v + 1].c = tree[v].c;
      tree[rv].c = tree[v].c;
    }
  };

  function<void(int, int, int, int, int, int)> Modify = [&](int v, int l, int r, int ll, int rr, int x) {
    debug(v, l, r, ll, rr, x);
    if (l >= ll && rr >= r && tree[v].c != -1) {
      tree[v].tag -= sum[tree[v].c];
      tree[v].c = x;
      tree[v].tag += sum[tree[v].c];
      debug(tree[v].tag);
      return;
    }                             
    def;
    Push(v, l, r);
    if (mid >= ll) {
      Modify(v + 1, l, mid, ll, rr, x);
    }
    if (mid < rr) {
      Modify(rv, mid + 1, r, ll, rr, x); 
    }
    Pull(tree[v], tree[v + 1], tree[rv]);
  };

  auto Use_modify = [&](int l, int r, int x) {
    assert(l >= 0 && r < N && l <= r);
    Modify(0, 0, N - 1, l, r, x);
  };


  auto Get = [&](int x) {
    int v = 0, l = 0, r = N - 1;
    while (l != r) {
      def;
      Push(v, l, r);
      if (x <= mid) {
        v = v + 1;
        r = mid;
      } else {
        v = rv;
        l = mid + 1;
      }
    }
    return tree[v].tag - sum[tree[v].c];
  };

  tree[0].tag = sum[0];

  for (auto q : QS) {
    debug(sum);
    if (q[0] == 0) {
      Use_modify(q[1], q[2], q[3]);
    } else if (q[0] == 1) {
      sum[q[1]] -= q[2];
    } else {
      cout << Get(q[1]) << '\n';
    }
  }
}