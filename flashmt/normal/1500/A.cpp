#include <bits/stdc++.h>
using namespace std;
const int A = 2500250;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<pair<int, int>> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x, i + 1});
  }
  sort(a.begin(), a.end());

  auto write = [&](int x, int y, int z, int w)
  {
    cout << "YES" << endl;
    cout << a[x].second << ' ' << a[y].second << ' ' << a[z].second << ' ' << a[w].second << endl;
  };

  if (n <= 3200)
  {
    vector<pair<int, int>> seen(A * 2, make_pair(-1, -1));
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
      {
        int sum = a[i].first + a[j].first;
        auto [u, v] = seen[sum];
        if (u >= 0 && u != i && v != j && v != i)
        {
          write(i, j, u, v);
          return 0;
        }
        if (u < 0)
          seen[sum] = {i, j};
      }
  }
  else
  {
    vector<int> seen(A, -1);
    for (int i = 1; i < n; i++)
    {
      int diff = a[i].first - a[i - 1].first;
      if (seen[diff] >= 0 && seen[diff] < i - 1)
      {
        write(i, seen[diff] - 1, i - 1, seen[diff]);
        return 0;
      }
      if (seen[diff] < 0)
        seen[diff] = i;
    }
  }

  cout << "NO" << endl;
}