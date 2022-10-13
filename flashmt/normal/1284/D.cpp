#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree
{
  const T DEFAULT = 0;
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
      return;
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
    T t = x <= mid ? l->get(x, min(y, mid)) : DEFAULT;
    T u = mid < y ? r->get(max(x, mid + 1), y) : DEFAULT;
    return merge(t, u);
  }
};

int n, sa[100100], ea[100100], sb[100100], eb[100100];

void solve()
{
  vector<pair<int, int>> e;
  map<int, int> m;
  for (int i = 1; i <= n; i++)
  {
    e.push_back({sa[i] - 1, i});
    e.push_back({ea[i], -i});
    m[sb[i]] = m[eb[i]] = 0;
  }
  int cur = 0;
  for (auto [k, _] : m)
    m[k] = cur++;

  SegmentTree<int> *tree = new SegmentTree<int>(0, cur - 1);
  for (int i = 1; i <= n; i++)
    tree->update(m[sb[i]], m[eb[i]], 1);

  sort(begin(e), end(e));
  for (auto [x, i] : e)
    if (i > 0) tree->update(m[sb[i]], m[eb[i]], -1);
    else
    {
      i = -i;
      if (tree->get(m[sb[i]], m[eb[i]]))
      {
        cout << "NO" << endl;
        exit(0);
      }
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
  solve();
  swap(sa, sb);
  swap(ea, eb);
  solve();
  cout << "YES" << endl;
}