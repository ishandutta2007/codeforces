#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

template<typename T>
struct SegmentTree
{
  int low, mid, high;
  T cnt, sum, sumSqr, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    cnt = sum = sumSqr = save = 0;
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void updateNode()
  {
    if (l)
      cnt = l->cnt + r->cnt;
    sum = l ? l->sum + r->sum : 0;
    sumSqr = 2 * save * sum + save * save * cnt;
    sum += cnt * save;
    if (l)
      sumSqr += l->sumSqr + r->sumSqr;
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y) save += v;
    else
    {
      if (x <= mid)
        l->update(x, min(y, mid), v);
      if (mid < y)
        r->update(max(x, mid + 1), y, v);
    }
    updateNode();
  }

  void set(int x)
  {
    if (low == high) cnt ^= 1;
    else if (x <= mid) l->set(x);
    else r->set(x);
    updateNode();
  }
};

const int A = 2e5;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q, d;
  cin >> q >> d;
  vector<int> flag(A);
  SegmentTree<long long> tree(0, A - 1);
  while (q--)
  {
    int x;
    cin >> x;
    x--;
    if (x)
      tree.update(max(0, x - d), x - 1, flag[x] ? -1 : 1);
    tree.set(x);
    flag[x] ^= 1;
    cout << (tree.sumSqr - tree.sum) / 2 << '\n';
  }
}