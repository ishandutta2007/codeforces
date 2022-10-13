#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 5;

int n, a[100100], flag[100100];
vector<pair<int, int>> f[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  f[1].push_back({-1, 0});
  for (int i = 1; i <= n; i++)
  {
    sort(f[i].begin(), f[i].end());
    if (i == n)
    {
      cout << -f[i][0].first << endl;
      return 0;
    }

    int cnt = 0;
    for (auto [score, value] : f[i])
      if (flag[value] != i)
      {
        flag[value] = i;
        f[i + 1].push_back({score - (a[i] != a[i + 1]), value});
        f[i + 1].push_back({score - (value != a[i + 1]), a[i]});
        if (++cnt == LIMIT)
          break;
      }
  }
}