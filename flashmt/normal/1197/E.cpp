#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;
const int oo = 1 << 30;

int n;
pair<int, int> a[200200], tree[200200];

void update(pair<int, int> &x, pair<int, int> y)
{
  if (y.first < x.first) x = y;
  else if (y.first == x.first)
  {
    x.second += y.second;
    if (x.second >= BASE)
      x.second -= BASE;
  }
}

void add(int x, pair<int, int> v)
{
  for (int i = x; i <= n; i += i & -i)
    update(tree[i], v);
}

pair<int, int> get(int x)
{
  pair<int, int> res(oo, 0);
  for (int i = x; i; i -= i & -i)
    update(res, tree[i]);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  map<int, int> allOut;
  int maxIn = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].first >> a[i].second;
    allOut[a[i].first] = 0;
    maxIn = max(maxIn, a[i].second);
    tree[i] = {oo, 0};
  }

  int id = 0;
  for (auto u : allOut)
    allOut[u.first] = ++id;

  sort(a + 1, a + n + 1);
  pair<int, int> ans(oo, 0);
  for (int i = 1; i <= n; i++)
  {
    pair<int, int> best(a[i].second, 1);
    auto j = allOut.upper_bound(a[i].second);
    if (j != allOut.begin())
    {
      auto u = get(prev(j)->second);
      u.first += a[i].second;
      update(best, u);
    }

    if (a[i].first > maxIn)
      update(ans, best);

    best.first -= a[i].first;
    add(allOut[a[i].first], best);
  }

  cout << ans.second << endl;
}