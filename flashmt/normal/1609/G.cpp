#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree
{
  int low, mid, high;
  T sum, maxValue, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, vector<T> &initial): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    if (low == high)
    {
      sum = maxValue = initial[low];
      return;
    }
    l = new SegmentTree(low, mid, initial);
    r = new SegmentTree(mid + 1, high, initial);
    sum = l->sum + r->sum;
    maxValue = max(l->maxValue, r->maxValue);
  }

  void updateNode(T v)
  {
    maxValue += v;
    sum += v * (high - low + 1);
    save += v;
  }

  void pushDown()
  {
    if (!save)
      return;
    l->updateNode(save);
    r->updateNode(save);
    save = 0;
  }

  void update(int x, int y, T v)
  {
    if (low == x && high == y) updateNode(v);
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), v);
      if (mid < y)
        r->update(max(x, mid + 1), y, v);
      sum = l->sum + r->sum;
      maxValue = max(l->maxValue, r->maxValue);
    }
  }

  T get(int x, int y)
  {
    if (low == x && high == y)
      return sum;
    pushDown();
    if (y <= mid) return l->get(x, y);
    else if (mid < x) return r->get(x, y);
    else return l->get(x, mid) + r->get(mid + 1, y);
  }

  int find(T v)
  {
    if (maxValue < v)
      return high + 1;
    if (low == high)
      return low;
    pushDown();
    return l->maxValue >= v ? l->find(v) : r->find(v);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<long long> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  long long sumAllB = accumulate(begin(b), end(b), 0LL);
  vector<long long> da(n - 1), db(m - 1);
  for (int i = 0; i < n - 1; i++)
    da[i] = a[i + 1] - a[i];
  for (int i = 0; i < m - 1; i++)
    db[i] = b[i + 1] - b[i];

  SegmentTree<long long> tree(0, m - 2, db);
  while (q--)
  {
    int t, k, d;
    cin >> t >> k >> d;
    if (t == 1)
    {
      for (int i = n - k, add = d; i < n; i++, add += d)
      {
        a[i] += add;
        if (i)
          da[i - 1] += d;
      }
    }
    else
    {
      if (k == m)
        b[0] += d;
      tree.update(max(0, m - 1 - k), m - 2, d);
      sumAllB += k * (k + 1LL) / 2 * d;
    }

    long long ans = sumAllB;
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
      int jj = tree.maxValue < da[i] ? m - 1 : tree.find(da[i]);
      ans += a[i] * (jj - j + 1);
      ans += b[0];
      if (jj)
        ans += tree.get(0, jj - 1);
      // debug(i, j, jj, ans);
      j = jj;
    }
    ans += a[n - 1] * (m - j);

    cout << ans << '\n';
  }
}