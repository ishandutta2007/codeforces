#include <bits/stdc++.h>
using namespace std;
const int LOG = 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> p(n, vector<int>(30));
  vector<int> isLeaf(n, 1);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i][0];
    isLeaf[--p[i][0]] = 0;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int numLeaf = accumulate(begin(isLeaf), end(isLeaf), 0);
  int maxA = *max_element(begin(a), end(a));
  int turn = (maxA - n) / numLeaf;

  for (int j = 0; j < LOG - 1; j++)
    for (int i = 0; i < n; i++)
      p[i][j + 1] = p[p[i][j]][j];

  vector<int> to(n), used(n), ans(n);
  set<int> values;
  for (int i = 1; i <= n; i++)
    values.insert(i);
  for (int i = 0; i < n; i++)
  {
    int x = i;
    for (int j = LOG - 1; j >= 0; j--)
      if (turn >> j & 1)
        x = p[x][j];
    if (!used[x])
    {
      used[x] = 1;
      ans[i] = a[x];
      values.erase(a[x]);
    }
    to[i] = x;
  }

  for (int i = 0; i < n; i++)
    if (!ans[i])
    {
      ans[i] = *values.upper_bound(a[to[i]]);
      values.erase(ans[i]);
    }

  for (int x : ans)
    cout << x << ' ';
}