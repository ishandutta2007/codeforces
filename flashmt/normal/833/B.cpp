#include <bits/stdc++.h>
using namespace std;
const int N = 35035;

int n, k, a[N], f[55][N], l[N], last[N];

struct SegmentTree
{
  int low, high, mid, value, addedValue;
  SegmentTree *l, *r;
  SegmentTree(int low, int high, int f[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    addedValue = 0;
    if (low == high) value = f[low];
    else
    {
      l = new SegmentTree(low, mid, f);
      r = new SegmentTree(mid + 1, high, f);
      value = max(l -> value, r -> value);
    }
  }

  void add(int x, int y, int v)
  {
    if (low == x && high == y) 
    {
      value += v;
      addedValue += v;
    }
    else 
    {
      if (x <= mid) l -> add(x, min(y, mid), v);
      if (mid < y) r -> add(max(x, mid + 1), y, v);
      value = max(l -> value, r -> value) + addedValue;
    }
  }

  int get(int x, int y)
  {
    if (low == x && high == y) return value;
    int u = 0, v = 0;
    if (x <= mid) u = l -> get(x, min(y, mid));
    if (mid < y) v = r -> get(max(x, mid + 1), y);
    return max(u, v) + addedValue;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (last[a[i]])
      l[i] = last[a[i]];
    last[a[i]] = i;
  }

  for (int i = 1; i <= k; i++)
  {
    SegmentTree *tree = new SegmentTree(0, n, f[i - 1]);
    for (int j = 1; j <= n; j++)
    {
      tree -> add(l[j], j - 1, 1);
      f[i][j] = tree -> get(0, j - 1);
    }
  }

  cout << f[k][n] << endl;
}