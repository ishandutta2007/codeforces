#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

struct Data
{
  long long sum, maxAll, maxL, maxR;
};

Data merge(Data l, Data r)
{
  long long sum = l.sum + r.sum;
  long long maxL = max(l.maxL, l.sum + r.maxL);
  long long maxR = max(r.maxR, r.sum + l.maxR);
  long long maxAll = max({l.maxAll, r.maxAll, maxL, maxR, l.maxR + r.maxL});
  return {sum, maxAll, maxL, maxR};
}

vector<Data> build(int level, int low, int high, vector<int> &a)
{
  if (level == 0)
  {
    long long mx = max(0, a[low]);
    return {{a[low], mx, mx, mx}};
  }

  int mid = (low + high) / 2;
  vector<Data> res(1 << level);
  auto leftChild = build(level - 1, low, mid, a);
  auto rightChild = build(level - 1, mid, high, a);
  for (int i = 0; i < 1 << level; i++)
  {
    auto curLeft = leftChild[i & ((1 << level - 1) - 1)];
    auto curRight = rightChild[i & ((1 << level - 1) - 1)];
    if (i >> level - 1 & 1)
      swap(curLeft, curRight);
    res[i] = merge(curLeft, curRight);
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (int &x : a)
    cin >> x;

  auto ans = build(n, 0, 1 << n, a);
  int q, sumXor = 0;
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    sumXor ^= 1 << x;
    cout << ans[sumXor].maxAll << '\n';
  }
}