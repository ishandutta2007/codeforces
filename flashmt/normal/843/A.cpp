#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, a[100100], id = 0;
  map<int, int> m;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    m[a[i]] = 0;
  }
  for (auto u : m)
    m[u.first] = id++;
  for (int i = 0; i < n; i++)
    a[i] = m[a[i]];

  vector<int> ans[100100];
  int group = 0, flag[100100] = {0};
  for (int i = 0; i < n; i++)
    if (!flag[i])
    {
      int x = i;
      while (!flag[x]) 
      {
        flag[x] = 1;
        ans[group].push_back(x);
        x = a[x];
      }
      group++;
    }

  cout << group << '\n';
  for (int i = 0; i < group; i++)
  {
    cout << ans[i].size() << ' ';
    for (auto x : ans[i])
      cout << x + 1 << ' ';
    cout << '\n';
  }
}