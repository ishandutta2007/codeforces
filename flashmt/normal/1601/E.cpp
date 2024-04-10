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
    return u + v;
  }

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = save = 0;
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
    l->value += save * (mid - low + 1);
    l->save += save;
    r->value += save * (high - mid);
    r->save += save;
    save = 0;
  }

  void update(int x, int y, T v)
  {
    if (low == x && high == y)
    {
      value += v * (high - low + 1);
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
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--; r--;
    queries[l].push_back({(r - l) / k + 1, i});
  }

  vector<int> b(n); // b[i] is minimum of a[i - k + 1 ... i]
  deque<int> dq;
  for (int i = 0; i < n; i++)
  {
    while (!empty(dq) && a[i] <= a[dq.back()])
      dq.pop_back();
    dq.push_back(i);
    while (i - dq.front() >= k)
      dq.pop_front();
    b[i] = a[dq.front()];
  }

  vector<long long> ans(q);
  for (int mod = 0; mod < k; mod++) // solve for l % k == mod
  {
    int bound = (n - 1) / k;
    if (bound * k + mod >= n)
      bound--;

    SegmentTree<long long> tree(0, bound);
    vector<pair<int, int>> stack = {{0, bound + 1}};
    for (int i = bound; i >= 0; i--)
    {
      int cur = i * k + mod;

      // push a[cur]
      while (a[cur] <= stack.back().first)
      {
        auto [value, id] = stack.back();
        stack.pop_back();
        tree.update(id, stack.back().second - 1, -value);
      }
      tree.update(i, stack.back().second - 1, a[cur]);
      stack.push_back({a[cur], i});

      // query
      for (auto [need, id] : queries[cur])
        ans[id] = tree.get(i, i + need - 1);

      // push b[cur] and overwrite a[cur]
      while (b[cur] <= stack.back().first)
      {
        auto [value, id] = stack.back();
        stack.pop_back();
        tree.update(id, stack.back().second - 1, -value);
      }
      tree.update(i, stack.back().second - 1, b[cur]);
      stack.push_back({b[cur], i});
    }
  }

  for (auto x : ans)
    cout << x << '\n';
}