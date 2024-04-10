#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<int, int>> pairs[200200];
  for (int i = 1; i <= 500; i++)
    for (int j = i + 2; i * j <= 200000; j++)
      if (i % 2 == j % 2)
        pairs[i * j].push_back({(j - i) / 2, (j + i) / 2});

  for (int i = 1; i <= 200000; i++)
    sort(pairs[i].begin(), pairs[i].end(), greater<pair<int, int>>());

  int n, a[100100] = {0};
  cin >> n;
  for (int i = 2; i <= n; i += 2)
  {
    int x, found = 0;
    cin >> x;
    while (!pairs[x].empty())
    {
      auto u = pairs[x].back();
      pairs[x].pop_back();
      if (u.first > a[i - 2])
      {
        a[i - 1] = u.first;
        a[i] = u.second;
        found = 1;
        break;
      }
    }

    if (!found)
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++)
    cout << 1LL * a[i] * a[i] - 1LL * a[i - 1] * a[i - 1] << ' ';
}