#include <bits/stdc++.h>
using namespace std;
const int K = 320;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  unordered_map<int, int> values;
  int numValues = 0;
  for (int i = 0; i < n; i++)
  {
    int sz;
    cin >> sz;
    a[i] = vector<int>(sz);
    for (int j = 0; j < sz; j++)
    {
      cin >> a[i][j];
      if (!values.count(a[i][j]))
        values[a[i][j]] = numValues++;
      a[i][j] = values[a[i][j]];
    }
    sort(a[i].begin(), a[i].end());
  }

  vector<vector<int>> id(numValues, vector<int>());
  for (int i = 0; i < n; i++)
    for (int x : a[i])
      id[x].push_back(i);

  vector<int> seenValue(numValues, -1), seenId(numValues, -1);
  for (int v = 0; v < numValues; v++)
    for (int i : id[v])
      if (a[i].size() <= K)
        for (int j = 0; a[i][j] < v; j++)
        {
          int u = a[i][j];
          if (seenValue[u] == v)
          {
            cout << seenId[u] + 1 << ' ' << i + 1 << '\n';
            return;
          }
          seenValue[u] = v;
          seenId[u] = i;
        }

  vector<int> has(numValues, - 1);
  for (int i = 0; i < n; i++)
    if (a[i].size() > K)
    {
      for (int x : a[i])
        has[x] = i;
      for (int j = 0; j < n; j++)
        if (a[j].size() <= K || j > i)
        {
          int cntHas = 0;
          for (int x : a[j])
            cntHas += has[x] == i;
          if (cntHas >= 2)
          {
            cout << i + 1 << ' ' << j + 1 << '\n';
            return;
          }
        }
    }

  cout << "-1\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
    solve();
}