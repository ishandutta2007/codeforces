#include <bits/stdc++.h>
using namespace std;

int n, tree[500500];

void add(int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i] = max(tree[i], v);
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res = max(res, tree[i]);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
      tree[i] = 0;

    set<pair<int, int>> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      int curLen = get(x) + 1;
      ans = max(ans, curLen);
      add(x, curLen);
      while (!s.empty())
      {
        auto u = *s.begin();
        if (u.first > x)
          break;
        s.erase(u);
        add(u.first, u.second + 1);
      }
      s.insert({x, curLen});
      if (!i)
        add(1, 1);
    }

    cout << ans << endl;
  }
}