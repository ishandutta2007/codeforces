#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 40;

struct SegmentTree
{
  int low, mid, high;
  long long save;
  pair<long long, int> minVal;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, long long s[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    if (low == high) minVal = {s[low], -low};
    else
    {
      l = new SegmentTree(low, mid, s);
      r = new SegmentTree(mid + 1, high, s);
      minVal = min(l->minVal, r->minVal);
    }
  }

  void pushDown()
  {
    l->minVal.first += save;
    l->save += save;
    r->minVal.first += save;
    r->save += save;
    save = 0;
  }

  void update(int x, int y, long long add)
  {
    if (low == x && high == y)
    {
      minVal.first += add;
      save += add;
    }
    else
    {
      if (save)
        pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), add);
      if (mid < y)
        r->update(max(x, mid + 1), y, add);
      minVal = min(l->minVal, r->minVal);
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long s[200200];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  SegmentTree *tree = new SegmentTree(0, n - 1, s);
  vector<int> ans(n, 0);
  for (int i = 1; i <= n; i++)
  {
    auto u = tree->minVal;
    int id = -u.second;
    ans[id] = i;
    if (id + 1 < n)
      tree->update(id + 1, n - 1, -i);
    tree->update(id, id, oo);
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}