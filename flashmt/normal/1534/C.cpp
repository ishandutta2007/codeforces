#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    vector<vector<int>> id(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
      {
        int x;
        cin >> x;
        a[i][j] = --x;
        id[i][x] = j;
      }

    int ans = 1;
    vector<int> flag(n, 0);
    for (int i = 0; i < n; i++)
      if (!flag[i])
      {
        int col = i;
        while (!flag[col])
        {
          flag[col] = 1;
          col = id[0][a[1][col]];
        }
        ans = ans * 2 % BASE;
      }

    cout << ans << endl;
  }
}