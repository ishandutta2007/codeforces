#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

vector<int> a[N];
int removed[N];

void dfs(int x, int par = -1)
{
  removed[x] = size(a[x]) <= 3;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      if (size(a[y]) >= 3 || !removed[y])
        removed[x] = 0;
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  int root = 0;
  for (int i = 1; i < n; i++)
    if (size(a[i]) > size(a[root]))
      root = i;
  dfs(root);

  int bad = -1;
  for (int x = 0; x < n; x++)
    if (!removed[x])
    {
      int neighbor = 0;
      for (int y : a[x])
        if (!removed[y])
          neighbor++;

      if (neighbor >= 3)
        bad = x;
    }

  if (bad < 0) cout << "Yes" << endl;
  else
  {
    fill(removed, removed + n, 0);
    dfs(bad);
    for (int x = 0; x < n; x++)
      if (!removed[x])
      {
        int neighbor = 0;
        for (int y : a[x])
          if (!removed[y])
            neighbor++;

        if (neighbor >= 3)
        {
          cout << "No" << endl;
          return 0;
        }
      }

    cout << "Yes" << endl;
  }
}