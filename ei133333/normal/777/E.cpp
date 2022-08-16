#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

struct SegmentTree
{
  vector< int64 > seg;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, -INF);
  }

  int64 rmq(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (-INF);
    if(a <= l && r <= b) return (seg[k]);
    return (max(rmq(a, b, 2 * k + 1, l, (l + r) >> 1),
                rmq(a, b, 2 * k + 2, (l + r) >> 1, r)));
  }

  int64 rmq(int a, int b)
  {
    return (rmq(a, b, 0, 0, sz));
  }

  void update(int k, int64 x)
  {
    k += sz - 1;
    seg[k] = max(seg[k], x);
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = max(seg[2 * k + 1], seg[2 * k + 2]);
    }
  }
};

int main()
{
  int n;
  int a[100000], b[100000], h[100000];

  vector< int > nums;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> h[i];
    nums.push_back(a[i]);
    nums.push_back(b[i]);
  }

  vector< int > latte(n);
  iota(begin(latte), end(latte), 0);
  sort(begin(latte), end(latte), [&](int x, int y)
  {
    if(b[x] == b[y]) return (a[y] < a[x]);
    return (b[x] > b[y]);
  });

  sort(begin(nums), end(nums));
  nums.erase(unique(begin(nums), end(nums)), end(nums));

  for(int i = 0; i < n; i++) {
    a[i] = lower_bound(begin(nums), end(nums), a[i]) - begin(nums);
    b[i] = lower_bound(begin(nums), end(nums), b[i]) - begin(nums);
  }

  SegmentTree tree(nums.size());
  for(int i = 0; i < nums.size(); i++) {
    tree.update(i, 0);
  }

  for(int i : latte) tree.update(a[i], tree.rmq(0, b[i]) + h[i]);

  cout << tree.rmq(0, nums.size()) << endl;
}