#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct SegmentTree
{
  int sz;
  vector< tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.resize(2 * sz - 1);
  }

  int query(int a, int b, int lower, int upper, int k, int l, int r)  // [a,b)?lower??upper????????
  {
    if(a >= r || b <= l) {
      return (0);
    } else if(a <= l && r <= b) {
      return (seg[k].order_of_key(upper) - seg[k].order_of_key(lower));
    } else {
      return (query(a, b, lower, upper, 2 * k + 1, l, (l + r) >> 1) + query(a, b, lower, upper, 2 * k + 2, (l + r) >> 1, r));
    }
  }

  int query(int a, int b, int l, int r)
  {
    return (query(a, b, l, r, 0, 0, sz));
  }


  void update(int k, int x, bool type)
  {
    k += sz - 1;
    if(type) seg[k].insert(x);
    else seg[k].erase(x);
    while(k > 0) {
      k = (k - 1) >> 1;
      if(type) seg[k].insert(x);
      else seg[k].erase(x);
    }
  }
};

typedef long long int64;

signed main()
{
  int N, Q;
  scanf("%d %d", &N, &Q);

  int64 sum = 0;
  int S[200000];
  SegmentTree tree(N);
  for(int i = 0; i < N; i++) S[i] = i, tree.update(i, i, true);

  for(int i = 0; i < Q; i++) {
    int L, R;
    scanf("%d %d", &L, &R);
    --L, --R;
    if(L > R) swap(L, R);
    if(L != R) {
      if(S[L] < S[R]) sum += 1LL * 2 * tree.query(L + 1, R, S[L], S[R]) + 1;
      else sum -= 1LL * 2 * tree.query(L + 1, R, S[R], S[L]) + 1;
      tree.update(L, S[L], false);
      tree.update(R, S[R], false);
      swap(S[L], S[R]);
      tree.update(L, S[L], true);
      tree.update(R, S[R], true);
    }
    printf("%lld\n", sum);
  }
}