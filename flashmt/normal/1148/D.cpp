#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> tree[600600];

void add(int x, pair<int, int> v)
{
  for (int i = x; i <= n * 2; i += i & -i)
    tree[i] = max(tree[i], v);
}

pair<int, int> get(int x)
{
  pair<int, int> res(0, -1);
  for (int i = x; i; i -= i & -i)
    res = max(res, tree[i]);
  return res;
}

vector<int> solve(vector<tuple<int, int, int>> a)
{
  sort(a.begin(), a.end());
  fill(tree, tree + n * 2 + 1, make_pair(0, -1));
  pair<int, int> f[300300];
  int best = -1;
  for (int i = 0; i < a.size(); i++)
  {
    int x = get<0>(a[i]), y = get<1>(a[i]);
    f[i] = get(y);
    add(x, {++f[i].first, i});
    if (best < 0 || f[i] > f[best])
      best = i;
  }

  vector<int> res;
  while (best >= 0)
  {
    res.push_back(get<2>(a[best]));
    best = f[best].second;
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y;
  cin >> n;
  vector<tuple<int, int, int>> a[2];
  for (int i = 1; i <= n; i++)
  {
    cin >> x >> y;
    if (x < y) a[0].push_back({x, y, i});
    else a[1].push_back({y, x, i});
  }

  vector<int> ans0 = solve(a[0]), ans1 = solve(a[1]);
  reverse(ans1.begin(), ans1.end());
  if (ans1.size() > ans0.size())
    ans0 = ans1;
  cout << ans0.size() << '\n';
  for (auto x : ans0)
    cout << x << ' ';
}