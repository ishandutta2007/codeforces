#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

struct SegmentTree
{
  int low, mid, high;
  long long v;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    v = oo;
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void add(int x, long long value)
  {
    if (low == high) v = value;
    else
    {
      if (x <= mid) l->add(x, value);
      else r->add(x, value);
      v = min(v, value);
    }
  }

  long long get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    long long t = oo, u = oo;
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
  int n;
  vector<pair<int, int>> a;
  cin >> n;
  long long sumC = 0;
  for (int i = 0; i < n; i++)
  {
    int x, c;
    cin >> x >> c;
    a.push_back({x, c});
    sumC += c;
  }

  sort(a.begin(), a.end());
  map<int, int> id;
  for (int i = 0; i < n; i++)
    id[a[i].first] = id[a[i].first + a[i].second] = 0;
  int num = 0;
  for (auto [k, _] : id)
    id[k] = num++;

  vector<long long> f(n, oo);
  SegmentTree *small = new SegmentTree(0, num - 1);
  SegmentTree *large = new SegmentTree(0, num - 1);
  for (int i = 0; i < n; i++)
  {
    if (!i) f[0] = 0;
    else
    {
      int curId = id[a[i].first];
      long long vSmall = small->get(0, curId);
      long long vLarge = large->get(curId, num - 1);
      f[i] = min(vSmall + a[i].first, vLarge);
    }
    small->add(id[a[i].first + a[i].second], f[i] - a[i].first - a[i].second);
    large->add(id[a[i].first + a[i].second], f[i]);
  }

  cout << f[n - 1] + sumC << endl;
}