#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 50;
const int A = 1000000;

struct SegmentTree
{
  int low, mid, high;
  long long value, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, vector<long long> &b): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = save = 0;
    if (low == high) value = -b[low];
    else
    {
      l = new SegmentTree(low, mid, b);
      r = new SegmentTree(mid + 1, high, b);
      value = max(l->value, r->value);
    }
  }

  void pushDown()
  {
    if (!save)
      return;
    l->value += save;
    l->save += save;
    r->value += save;
    r->save += save;
    save = 0;
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y)
    {
      value += v;
      save += v;
      return;
    }
    pushDown();
    if (x <= mid)
      l->update(x, min(y, mid), v);
    if (mid < y)
      r->update(max(x, mid + 1), y, v);
    value = max(l->value, r->value);
  }

  long long get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    pushDown();
    long long t = x <= mid ? l->get(x, min(y, mid)) : -oo;
    long long u = mid < y ? r->get(max(x, mid + 1), y) : -oo;
    return max(t, u);
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(A, oo), b(A, oo);
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    a[x] = min(a[x], 1LL * y);
  }
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    b[x] = min(b[x], 1LL * y);
  }

  SegmentTree *tree = new SegmentTree(0, A - 1, b);
  vector<vector<pair<int, int>>> monsters(A, vector<pair<int, int>>());
  for (int i = 0; i < p; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    monsters[--x].push_back({--y, z});
  }

  long long ans = -oo;
  for (int i = 0; i < A; i++)
  {
    if (a[i] < oo)
      ans = max(ans, tree->value - a[i]);
    for (auto [y, z] : monsters[i])
      if (y + 1 < A)
        tree->update(y + 1, A - 1, z);
  }

  cout << ans << endl;
}