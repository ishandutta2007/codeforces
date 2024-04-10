#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n, a[111][111];
  cin >> n >> m;
  vector<pair<int, int>> stations;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  vector<int> ans(m + 1);
  for (int j = 0; j < n - 1; j++)
  {
    vector<pair<int, int>> stations;
    int sumDif = 0;
    for (int i = 0; i < m; i++)
    {
      sumDif += a[i][j] - a[i][n - 1];
      stations.push_back({a[i][j] - a[i][n - 1], i});
    }

    vector<int> toRemove;
    sort(stations.begin(), stations.end());
    for (auto [dif, id] : stations)
      if (sumDif < 0)
      {
        sumDif -= dif;
        toRemove.push_back(id);
      }

    if (toRemove.size() < ans.size())
      ans = toRemove;
  }

  cout << ans.size() << endl;
  for (auto id : ans)
    cout << id + 1 << ' ';
}