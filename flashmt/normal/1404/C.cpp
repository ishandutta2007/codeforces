#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high;
  int save;
  pair<int, int> value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    value = {0, low};
    if (low == high)
      return;
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
  }

  void pushDown()
  {
    if (!save)
      return;
    l->value.first += save;
    l->save += save;
    r->value.first += save;
    r->save += save;
    save = 0;
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y)
    {
      value.first += v;
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

  pair<int, int> get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    pushDown();
    auto t = x <= mid ? l->get(x, min(y, mid)) : make_pair(-oo, -1);
    auto u = mid < y ? r->get(max(x, mid + 1), y) : make_pair(-oo, -1);
    return max(t, u);
  }
};


vector<pair<int, int>> queries[300300];
int n, bit[300300];

void add(int x, int v)
{
  for (int i = x + 1; i <= n; i += i & -i)
    bit[i] += v;
}

int get(int x)
{
  int res = 0;
  for (int i = x + 1; i; i -= i & -i)
    res += bit[i];
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] = i + 1 - a[i];
  }
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    queries[x].push_back({n - 1 - y, i});
  }

  SegmentTree *tree = new SegmentTree(0, n - 1);
  vector<int> alive(n);
  for (int i = 0; i < n; i++)
  {
    int prev = tree->get(i, i).first;
    if (a[i] < 0 || a[i] + prev > 0) tree->update(i, i, -oo);
    else
    {
      alive[i] = 1;
      add(i, 1);
      tree->update(i, i, a[i]);
      if (i + 1 < n)
        tree->update(i + 1, n - 1, -1);
    }
  }

  vector<int> ans(q);
  for (int i = 0; i < n; i++)
  {
    for (auto [y, id] : queries[i])
      ans[id] = get(y) - get(i - 1);

    if (!alive[i] || i == n - 1)
      continue;

    tree->update(i + 1, n - 1, 1);
    while (1)
    {
      auto [v, x] = tree->get(i + 1, n - 1);
      if (v <= 0)
        break;
      add(x, -1);
      alive[x] = 0;
      tree->update(x, x, -oo);
      if (x + 1 < n)
        tree->update(x + 1, n - 1, 1);
    }
  }

  for (int x : ans)
    cout << x << '\n';
}