#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

struct SegmentTree
{
  int low, mid, high;
  long long save;
  pair<long long, int> v;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, vector<long long> &initialValue): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    if (low == high) v = {initialValue[low], low};
    else
    {
      l = new SegmentTree(low, mid, initialValue);
      r = new SegmentTree(mid + 1, high, initialValue);
      v = max(l->v, r->v);
    }
  }

  void pushDown()
  {
    l->v.first += save;
    l->save += save;
    r->v.first += save;
    r->save += save;
    save = 0;
  }

  void update(int x, int y, long long diff)
  {
    if (low == x && high == y)
    {
      v.first += diff;
      save += diff;
      return;
    }

    if (save)
      pushDown();

    if (x <= mid)
      l->update(x, min(y, mid), diff);
    if (mid < y)
      r->update(max(x, mid + 1), y, diff);
    v = max(l->v, r->v);
  }

  pair<long long, int> get(int x, int y)
  {
    if (low == x && high == y)
      return v;

    if (save)
      pushDown();

    pair<long long, int> t(-oo, 0), u(-oo, 0);
    if (x <= mid)
      t = l->get(x, min(y, mid));
    if (mid < y)
      u = r->get(max(x, mid + 1), y);
    return max(t, u);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<tuple<int, int, int>> a;
  cin >> n;
  map<int, int> allX;
  for (int i = 0; i < n; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    if (y > x)
      swap(x, y);
    a.push_back({y, x, c});
    allX[x] = 0;
  }
  sort(a.begin(), a.end());

  int numX = 0;
  vector<int> sortedX;
  for (auto u : allX)
  {
    allX[u.first] = numX++;
    sortedX.push_back(u.first);
  }

  int minY = get<0>(a[0]);
  vector<long long> initialValue(numX, 0);
  for (int i = 0; i < n; i++)
  {
    int x = get<1>(a[i]), c = get<2>(a[i]);
    initialValue[allX[x]] += c;
  }
  for (int i = 1; i < numX; i++)
    initialValue[i] += initialValue[i - 1];
  for (int i = 0; i < numX; i++)
    initialValue[i] -= sortedX[i] - minY;

  SegmentTree *tree = new SegmentTree(0, numX - 1, initialValue);
  long long ans = -1;
  int from, to;
  for (int i = 0; i < n;)
  {
    int curY = get<0>(a[i]);
    auto it = allX.lower_bound(curY);
    if (it != allX.end())
    {
      auto best = tree->get(it->second, numX - 1);
      if (best.first > ans)
      {
        ans = best.first;
        from = curY;
        to = sortedX[best.second];
      }
    }

    int j = i;
    while (j < n && get<0>(a[j]) == curY)
    {
      int x = get<1>(a[j]), c = get<2>(a[j]);
      tree->update(allX[x], numX - 1, -c);
      j++;
    }

    if (j < n)
    {
      int newY = get<0>(a[j]);
      auto it = allX.lower_bound(newY);
      if (it != allX.end())
        tree->update(it->second, numX - 1, newY - curY);
    }
    i = j;
  }

  if (ans < 0)
  {
    int maxY = get<0>(a[n - 1]);
    cout << 0 << endl << maxY + 1 << ' ' << maxY + 1 << ' ' << maxY + 1 << ' ' << maxY + 1 << endl;
  }
  else cout << ans << endl << from << ' ' << from << ' ' << to << ' ' << to << endl;
}