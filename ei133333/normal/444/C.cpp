#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

struct SegmentTree
{
  vector< int64 > val, seg, lazy;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    val.assign(2 * sz - 1, -1);
    for(int i = 0; i < n; i++) val[i + sz - 1] = i + 1;
    seg.assign(2 * sz - 1, 0);
    lazy.assign(2 * sz - 1, 0);
  }

  void push(int k)
  {
    if(k < sz - 1) {
      if(~val[k]) val[2 * k + 1] = val[2 * k + 2] = val[k];
    }
  }

  void paint(int a, int b, int x, int k, int l, int r)
  {
    push(k);
    if(a >= r || b <= l) return;
    if(a <= l && r <= b && ~val[k]) {
      lazy[k] += llabs(x - val[k]);
      val[k] = x;
      push(k);
      return;
    }
    int mid = (l + r) >> 1;
    val[k] = -1;
    paint(a, b, x, 2 * k + 1, l, mid);
    paint(a, b, x, 2 * k + 2, mid, r);
    seg[k] = seg[2 * k + 1] + seg[2 * k + 2];
    seg[k] += lazy[2 * k + 1] * (mid - l);
    seg[k] += lazy[2 * k + 2] * (r - mid);
    if(val[2 * k + 1] == val[2 * k + 2]) val[k] = val[2 * k + 1];
    else val[k] = -1;
  }

  int64 query(int a, int b, int k, int l, int r)
  {
    push(k);
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) return (seg[k] + lazy[k] * (r - l));
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) +
            query(a, b, 2 * k + 2, (l + r) >> 1, r) +
            lazy[k] * (min(b, r) - max(a, l)));
  }

  void paint(int a, int b, int x)
  {
    paint(a, b, x, 0, 0, sz);
  }

  int64 query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }
};

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);
  SegmentTree tree(N);
  for(int i = 0; i < M; i++) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    --l;
    if(type == 1) {
      int x;
      scanf("%d", &x);
      tree.paint(l, r, x);
    } else {
      printf("%lld\n", tree.query(l, r));
    }
  }
}