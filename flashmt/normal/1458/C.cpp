#include <bits/stdc++.h>
using namespace std;

int n, a[1010][1010], ans[1010][1010];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        cin >> a[i][j];
        a[i][j]--;
      }

    string op;
    cin >> op;
    int x = 0, y = 0, z = 0;
    vector<int> dirs = {0, 1, 2};
    for (char c : op)
    {
      if (c == 'L') y = (y + n - 1) % n;
      else if (c == 'R') y = (y + 1) % n;
      else if (c == 'U') x = (x + n - 1) % n;
      else if (c == 'D') x = (x + 1) % n;
      else if (c == 'I')
      {
        swap(y, z);
        swap(dirs[1], dirs[2]);
      }
      else
      {
        swap(x, z);
        swap(dirs[0], dirs[2]);
      }
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        vector<int> coor = {i, j, a[i][j]};
        vector<int> finalCoor = {x, y, z};
        for (int k = 0; k < 3; k++)
          finalCoor[k] = (finalCoor[k] + coor[dirs[k]]) % n;

        ans[finalCoor[0]][finalCoor[1]] = finalCoor[2];
      }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cout << ans[i][j] + 1 << " \n"[j == n - 1];
  }
}