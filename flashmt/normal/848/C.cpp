#include <bits/stdc++.h>
using namespace std;

int n, q, a[100100];
set <int> s[100100];

struct Query
{
  int type, x, y;
} queries[100100];

struct SegmentTree
{
  int low, mid, high, bitSize;
  long long sumBit;
  SegmentTree *l, *r;
  vector <int> queryValues;
  vector <long long> bit;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low < high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void addBIT(int x, int v)
  {
    sumBit += v;
    for (int i = x; i <= bitSize; i += i & -i)
      bit[i] += v;
  }

  long long getBIT(int x)
  {
    long long res = 0;
    for (int i = x; i; i -= i & -i)
      res += bit[i];
    return res;
  }

  void addQueryValue(int x, int y, int value)
  {
    if (low == x && high == y) queryValues.push_back(value);
    else
    {
      if (x <= mid)
        l -> addQueryValue(x, min(y, mid), value);
      if (mid < y)
        r -> addQueryValue(max(x, mid + 1), y, value);
    }
  }

  void refine()
  {
    sort(queryValues.begin(), queryValues.end());
    bitSize = unique(queryValues.begin(), queryValues.end()) - queryValues.begin();
    queryValues.resize(bitSize);
    bit = vector<long long>(bitSize + 1);
    sumBit = 0;
    if (low < high)
    {
      l -> refine();
      r -> refine();
    }
  }

  void updatePoint(int x, int y, int val)
  {
    if (bitSize)
    {
      int idValue = upper_bound(queryValues.begin(), queryValues.end(), y) - queryValues.begin();
      if (idValue)
        addBIT(idValue, val);
    }

    if (low == high)
      return;
    if (x <= mid) l -> updatePoint(x, y, val);
    else r -> updatePoint(x, y, val);
  }

  long long query(int x, int y, int z)
  {
    if (low == x && high == y)
    {
      int idValue = upper_bound(queryValues.begin(), queryValues.end(), z) - queryValues.begin();
      long long res = sumBit;
      if (idValue > 1)
        res -= getBIT(idValue - 1);
      return res;
    }

    long long res = 0;
    if (x <= mid)
      res += l -> query(x, min(y, mid), z);
    if (mid < y)
      res += r -> query(max(x, mid + 1), y, z);
    return res;
  }
} *tree;

int getPrev(int i)
{
  auto it = s[a[i]].find(i);
  return it == s[a[i]].begin() ? 0 : *(--it);
}

void remove(int i)
{
  auto it = s[a[i]].find(i);
  int l = 0, r = n + 1;
  // Remove right
  ++it;
  if (it != s[a[i]].end())
  {
    r = *it;
    tree -> updatePoint(r, i, i - r);
  }
  // Remove left
  --it;
  if (it != s[a[i]].begin())
  {
    l = *(--it);
    tree -> updatePoint(i, l, l - i);
  }
  // Add merged
  if (l && r <= n)
    tree -> updatePoint(r, l, r - l);
  s[a[i]].erase(i);
}

void update(int i, int x)
{
  s[x].insert(i);
  a[i] = x;
  auto it = s[x].find(i);
  int l = 0, r = n + 1;
  // Add right
  ++it;
  if (it != s[x].end())
  {
    r = *it;
    tree -> updatePoint(r, i, r - i);
  }
  // Add left
  --it;
  if (it != s[a[i]].begin())
  {
    l = *(--it);
    tree -> updatePoint(i, l, i - l);
  }
  // Remove merged
  if (l && r <= n)
    tree -> updatePoint(r, l, l - r);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int type, x, y;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    s[a[i]].insert(i);
  }

  tree = new SegmentTree(1, n);
  for (int i = 1; i <= q; i++)
  {
    cin >> type >> x >> y;
    queries[i] = {type, x, y};
    if (type == 2)
      tree -> addQueryValue(x, y, x);
  }

  tree -> refine();

  for (int i = 1; i <= n; i++)
  {
    int prev = getPrev(i);
    if (prev)
      tree -> updatePoint(i, prev, i - prev);
  }

  for (int i = 1; i <= q; i++)
    if (queries[i].type == 1)
    {
      remove(queries[i].x);
      update(queries[i].x, queries[i].y);
    }
    else cout << tree -> query(queries[i].x, queries[i].y, queries[i].x) << '\n';
}