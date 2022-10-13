#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, ans[100100];
  vector<int> id[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    id[x].push_back(i);
  }

  int color = 0;
  for (int i = 0; i < n; i++)
    if (!id[i].empty())
    {
      int each = n - i, numColor = id[i].size() / each;
      if (numColor * each != id[i].size() || color + numColor > n)
      {
        cout << "Impossible" << endl;
        return 0;
      }
      for (int j = 0; j < id[i].size(); j++)
        ans[id[i][j]] = color + j / each;
      color += numColor;
    }

  cout << "Possible" << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] + 1 << ' ';
}