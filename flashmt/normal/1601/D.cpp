#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

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
    save = 0;
    if (low == high)
    {
      value = -low;
      return;
    }
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
    value = max(l->value, r->value);
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

  void update(int x, int y, T v)
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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> a(n + 1);
  a[0] = {d, -oo};
  for (int i = 1; i <= n; i++)
  {
    int skill, neat;
    cin >> skill >> neat;
    neat = max(neat, d);
    a[i] = {neat, -skill};
  }
  sort(begin(a), end(a));

  vector<pair<int, int>> allS;
  for (int i = 1; i <= n; i++)
    allS.push_back({-a[i].second, i});
  sort(begin(allS), end(allS));

  SegmentTree<int> tree(0, n);
  vector<int> f(n + 1);
  for (int i = 0, j = 0; i <= n; i++)
  {
    int curNeat = a[i].first, curSkill = -a[i].second;
    while (j < size(allS))
    {
      auto [skillJ, id] = allS[j];
      if (skillJ >= curNeat)
        break;
      j++;
      tree.update(id, n, 1);
    }

    if (i == 0)
      continue;

    int bound = upper_bound(begin(a), end(a), make_pair(curSkill, oo)) - begin(a);
    bound = min(i, bound) - 1;
    if (bound >= 0)
    {
      int curCnt = tree.get(i, i);
      f[i] = tree.get(0, bound) - curCnt;
      if (curSkill < curNeat)
        f[i]++;
      tree.update(i, i, f[i]);
    }
  }

  cout << *max_element(begin(f), end(f)) << endl;
}