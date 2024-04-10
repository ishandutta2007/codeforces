#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a[1111][5];
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++)
      cin >> a[i][j];

  vector <int> ans;
  for (int i = 0; i < n; i++)
  {
    int bad = 0;
    for (int j = 0; j < n && !bad; j++)
      for (int k = j + 1; k < n; k++)
      {
        int sum = 0;
        for (int p = 0; p < 5; p++)
          sum += (a[j][p] - a[i][p]) * (a[k][p] - a[i][p]);
        if (sum > 0)
        {
          bad = 1;
          break;
        }
      }

    if (!bad)
      ans.push_back(i + 1);
  }

  cout << ans.size() << endl;
  for (int x : ans)
    cout << x << ' ';
}