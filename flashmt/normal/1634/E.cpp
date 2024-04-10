#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 2e5 + 5;

map<int, int> a[N];
set<pair<int, int>> b[N];
vector<int> ans[N];
map<int, int> num;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int n;
    cin >> n;
    ans[i].resize(n);
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      if (!num.count(x))
        num[x] = size(num);
      a[i][j] = num[x];
      b[num[x]].insert({i, j});
    }
  }

  for (int i = 0; i < m; i++)
  {
    int x = i;
    while (!empty(a[i]))
    {
      if (empty(a[x]))
      {
        cout << "NO" << endl;
        return 0;
      }

      int id = begin(a[x])->first, y = a[x][id];
      a[x].erase(id);
      b[y].erase({x, id});
      ans[x][id] = 0;

      if (empty(b[y]))
      {
        cout << "NO" << endl;
        return 0;
      }

      tie(x, id) = *begin(b[y]);
      a[x].erase(id);
      b[y].erase({x, id});
      ans[x][id] = 1;
    }
  }

  cout << "YES\n";
  for (int i = 0; i < m; i++)
  {
    for (int x : ans[i])
      cout << "LR"[x];
    cout << '\n';
  }
}