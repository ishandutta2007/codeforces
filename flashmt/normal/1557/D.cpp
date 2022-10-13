#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree
{
  int low, mid, high;
  T value, save;
  SegmentTree *l, *r;

  T merge(T u, T v)
  {
    return max(u, v);
  }

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = save = {0, 0};
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void updateNode(T v)
  {
    value = max(value, v);
    save = max(save, v);
  }

  void pushDown()
  {
    if (!save.first)
      return;
    l->updateNode(save);
    r->updateNode(save);
    save = {0, 0};
  }

  void update(int x, int y, T v)
  {
    if (low == x && high == y)
    {
      updateNode(v);
      return;
    }
    pushDown();
    if (x <= mid)
      l->update(x, min(y, mid), v);
    if (mid < y)
      r->update(max(x, mid + 1), y, v);
    value = merge(l->value, r->value);
  }

  T get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    pushDown();
    if (y <= mid) return l->get(x, y);
    else if (x > mid) return r->get(x, y);
    else return merge(l->get(x, mid), r->get(mid + 1, y));
  }
};

void refine(vector<pair<int, int>> &a)
{
  sort(begin(a), end(a));
  int n = 1;
  for (int i = 1; i < a.size(); i++)
    if (a[i].first >= a[n - 1].second) a[n++] = a[i];
    else a[n - 1].second = max(a[n - 1].second, a[i].second);
  a.resize(n);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> a(n + 1);
  for (int i = 0; i < m; i++)
  {
    int id, l, r;
    cin >> id >> l >> r;
    a[id].push_back({l - 1, r});
  }

  map<int, int> allX;
  for (int i = 1; i <= n; i++)
    if (!a[i].empty())
    {
      refine(a[i]);
      for (auto [l, r] : a[i])
        allX[l] = allX[r] = 0;
    }
  int numX = 0;
  for (auto [k, _] : allX)
    allX[k] = numX++;

  int ans = 0, bestId = -1;
  SegmentTree<pair<int, int>> tree(0, numX);
  vector<int> tr(n + 1);
  for (int i = 1; i <= n; i++)
  {
    if (a[i].empty())
      continue;

    int f = 1;
    for (auto [l, r] : a[i])
    {
      l = allX[l];
      r = allX[r];
      auto [cur, ii] = tree.get(l + 1, r);
      if (cur + 1 > f)
      {
        f = cur + 1;
        tr[i] = ii;
      }
    }

    if (f > ans)
    {
      ans = f;
      bestId = i;
    }

    for (auto [l, r] : a[i])
    {
      l = allX[l];
      r = allX[r];
      tree.update(l + 1, r, {f, i});
    }
  }

  vector<int> removed(n + 1, 1);
  for (int i = bestId; i; i = tr[i])
    removed[i] = 0;

  cout << n - ans << endl;
  for (int i = 1; i <= n; i++)
    if (removed[i])
      cout << i << ' ';
}