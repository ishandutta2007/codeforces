#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high, value, minValue;
  long long sum;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, int initialValues[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high) sum = value = minValue = initialValues[low];
    else
    {
      l = new SegmentTree(low, mid, initialValues);
      r = new SegmentTree(mid + 1, high, initialValues);
      value = 0;
      sum = l->sum + r->sum;
      minValue = r->minValue;
    }
  }

  void pushDown()
  {
    if (value)
    {
      l->value = l->minValue = r->value = r->minValue = value;
      l->sum = (mid - low + 1LL) * value;
      r->sum = 1LL * (high - mid) * value;
      value = 0;
    }
  }

  void update(int x, int y, int newValue)
  {
    if (low == x && high == y)
    {
      value = minValue = newValue;
      sum = (high - low + 1LL) * value;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), newValue);
      if (mid < y)
        r->update(max(x, mid + 1), y, newValue);
      sum = l->sum + r->sum;
      minValue = r->minValue;
    }
  }

  // find leftmost node whose value <= upper
  int findValue(int x, int y, int upper)
  {
    if (low == high)
      return value <= upper ? low : oo;
    pushDown();
    if (x == low && y == high)
      return l->minValue <= upper ? l->findValue(low, mid, upper) : r->findValue(mid + 1, high, upper);

    int lRes = oo, rRes = oo;
    if (x <= mid)
      lRes = l->findValue(x, min(y, mid), upper);
    if (mid < y)
      rRes = r->findValue(max(x, mid + 1), y, upper);
    return min(lRes, rRes);
  }

  long long getSum(int x, int y)
  {
    if (x == low && y == high)
      return sum;
    pushDown();
    long long res = 0;
    if (x <= mid)
      res += l->getSum(x, min(y, mid));
    if (mid < y)
      res += r->getSum(max(x, mid + 1), y);
    return res;
  }

  // fint rightmost node such that sum[0..node] <= targetSum
  pair<int, long long> findSum(long long targetSum)
  {
    if (low == high)
      return value <= targetSum ? make_pair(low, sum) : make_pair(-1, -1LL);
    pushDown();
    if (l->sum > targetSum)
      return l->findSum(targetSum);
    auto res = r->findSum(targetSum - l->sum);
    res.second += l->sum;
    return max(make_pair(mid, l->sum), res);
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, a[200200];
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  SegmentTree *tree = new SegmentTree(0, n - 1, a);
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int store, value;
      cin >> store >> value;
      store--;
      int u = tree->findValue(0, store, value);
      if (u <= store)
        tree->update(u, store, value);
    }
    else
    {
      int from, budget, ans = 0;
      cin >> from >> budget;
      from--;
      while (from < n)
      {
        int storeLeft = tree->findValue(from, n - 1, budget);
        if (storeLeft == oo)
          break;
        long long curSum = (storeLeft ? tree->getSum(0, storeLeft - 1) : 0);
        auto [storeRight, sumRight] = tree->findSum(curSum + budget);
        ans += storeRight - storeLeft + 1;
        budget -= sumRight - curSum;
        from = storeRight + 1;
      }
      cout << ans << '\n';
    }
  }
}