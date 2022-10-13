#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

struct SegmentTree
{
  int low, mid, high;
  int minValue, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    minValue = save = 0;
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void init(vector<int> &initialValues)
  {
    save = 0;
    if (low == high) minValue = initialValues[low];
    else
    {
      l->init(initialValues);
      r->init(initialValues);
      minValue = min(l->minValue, r->minValue);
    }
  }

  void pushDown()
  {
    if (save)
    {
      l->minValue += save;
      l->save += save;
      r->minValue += save;
      r->save += save;
      save = 0;
    }
  }

  void update(int x, int y, int value)
  {
    if (low == x && high == y)
    {
      minValue += value;
      save += value;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), value);
      if (mid < y)
        r->update(max(x, mid + 1), y, value);
      minValue = min(l->minValue, r->minValue);
    }
  }

  int get(int x, int y)
  {
    if (low == x && high == y)
      return minValue;
    pushDown();
    int t = oo, u = oo;
    if (x <= mid)
      t = l->get(x, min(y, mid));
    if (mid < y)
      u = r->get(max(x, mid + 1), y);
    return min(t, u);
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), last(n + 1, -1), prev(n), f(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    prev[i] = last[a[i]];
    if (i)
      f[i] = f[i - 1];
    if (prev[i] >= 0)
      f[i] += i - prev[i];
    last[a[i]] = i;
  }

  SegmentTree *tree = new SegmentTree(0, n - 1);
  for (int seg = 2; seg <= k; seg++)
  {
    vector<int> newF(n);
    tree->init(f);
    for (int i = 0; i < n; i++)
    {
      if (prev[i] > 0)
        tree->update(0, prev[i] - 1, i - prev[i]);
      if (i)
        newF[i] = tree->get(0, i - 1);
    }
    f = newF;
  }

  cout << f[n - 1] << endl;
}