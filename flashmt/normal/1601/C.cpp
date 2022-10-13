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
    return min(u, v);
  }

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    value = low;
    if (low == high)
    {
      l = r = NULL;
      return;
    }
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
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
};

template<typename T>
struct FenwickTree
{
  int n, indexBase;
  vector<T> a;

  FenwickTree(int n, int indexBase = 1): n(n), indexBase(indexBase)
  {
    a = vector<T>(n + 1, 0);
  }

  void add(int x, T v)
  {
    for (int i = x + 1 - indexBase; i <= n; i += i & -i)
      a[i] += v;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<pair<int, int>> allA(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      allA[i] = {a[i], i};
    }
    for (int i = 0; i < m; i++)
      cin >> b[i];

    sort(begin(allA), end(allA));
    sort(begin(b), end(b));

    long long ans = 0;
    SegmentTree<int> segTree(0, n);
    int iPrefix = 0, iSuffix = 0;
    for (int x : b)
    {
      while (iPrefix < n)
      {
        auto [curA, id] = allA[iPrefix];
        if (curA >= x)
          break;
        segTree.update(0, id, 1);
        iPrefix++;
      }

      while (iSuffix < n)
      {
        auto [curA, id] = allA[iSuffix];
        if (curA > x)
          break;
        segTree.update(id + 1, n, -1);
        iSuffix++;
      }

      ans += segTree.value;
    }

    int numA = 0;
    for (int i = 0; i < n; i++)
    {
      if (i == 0 || allA[i].first != allA[i - 1].first)
        numA++;
      a[allA[i].second] = numA;
    }

    FenwickTree<long long> fenwickTree(numA);
    for (int i = 0; i < n; i++)
    {
      ans += i - fenwickTree.get(a[i]);
      fenwickTree.add(a[i], 1);
    }
    cout << ans << endl;
  }
}