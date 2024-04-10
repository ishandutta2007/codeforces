#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  vector<int> len(n);
  for (int i = 0; i < n; i++)
  {
    cin >> len[i];
    a[i].resize(len[i]);
    for (int &x : a[i])
    {
      cin >> x;
      x--;
    }
  }

  vector<vector<int>> adj(m);
  for (int i = 0; i < n - 1; i++)
  {
    int found = 0;
    for (int j = 0; j < min(len[i], len[i + 1]); j++)
      if (a[i][j] != a[i + 1][j])
      {
        adj[a[i + 1][j]].push_back(a[i][j]);
        found = 1;
        break;
      }

    if (!found && len[i] > len[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  vector<int> val(m, -1), ans;
  auto assign = [&](int x, int v)
  {
    if (val[x] < 0) val[x] = v;
    else if (val[x] != v)
    {
      cout << "No" << endl;
      exit(0);
    }
  };

  for (int i = 0; i < m; i++)
  {
    for (int j : adj[i])
      if (j > i)
      {
        assign(j, 1);
        assign(i, 0);
      }
      else if (!val[j]) assign(i, 0);
    if (val[i])
      ans.push_back(i);
  }

  cout << "Yes" << endl;
  cout << size(ans) << endl;
  for (int x : ans)
    cout << x + 1 << ' ';
}