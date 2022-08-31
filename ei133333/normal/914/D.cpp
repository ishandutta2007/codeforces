#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1 << 30;

struct SegNode
{
  int v;

  SegNode(int v) : v(v) {}

  SegNode operator*(const SegNode &r) const
  {
    return (__gcd(v, r.v));
  }
} e(0);

struct SegmentTree
{
  int sz;
  vector< SegNode > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, e);
  }

  void update(int k, const SegNode &x)
  {
    k += sz - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
  }

  SegNode query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (e);
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) * query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  SegNode query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }

  void set(int k, SegNode x)
  {
    seg[k + sz - 1] = x;
  }

  void build()
  {
    for(int k = sz - 2; k >= 0; k--) {
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
  }

  int lower_bound(int a, int b, int x, int k, int l, int r)
  {
    if(a >= r || b <= l) return (-3);
    if(a <= l && r <= b) {
      if(seg[k].v % x == 0) return (r - 1);
      if(l + 1 == r) return (-2);
    }
    auto latte = lower_bound(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    if(latte == -3) return (lower_bound(a, b, x, 2 * k + 2, (l + r) >> 1, r));
    if(latte == -2) return (-2);
    if(latte + 1 == (l + r) >> 1) {
      auto malta = lower_bound(a, b, x, 2 * k + 2, (l + r) >> 1, r);
      return (malta < 0 ? latte : malta);
    } else {
      return (latte);
    }
  }

  int lower_bound(int a, int b, int x)
  {
    return (lower_bound(a, b, x, 0, 0, sz));
  }

};

int main()
{
  int N, A[500000];
  scanf("%d", &N);
  SegmentTree seg(N);
  for(int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    seg.set(i, x);
  }
  seg.build();
  int Q;
  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int t;
    scanf("%d", &t);
    if(t == 2) {
      int x, y;
      scanf("%d %d", &x, &y);
      --x;
      seg.update(x, y);
    } else {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      --l;
      int ok = max(l - 1, seg.lower_bound(l, r, x));
      if(__gcd(seg.query(ok + 2, r).v, x) == x) puts("YES");
      else puts("NO");
    }
  }
}