#include <bits/stdc++.h>
using namespace std;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

int main()
{
  int m, n;
  string a[500];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  function<int(int, int)> isValid = [&](int i, int j)
  {
    return i >= 0 && i < m && j >= 0 && j < n && a[i][j] == '*';
  };

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] =='*')
      {
        int cnt = 0;
        for (int k = 0; k < 4; k++)
          cnt += isValid(i + DX[k], j + DY[k]);

        if (cnt == 4)
        {
          int ans = 1;
          for (int k = 0; k < 4; k++)
          {
            int ii = i + DX[k], jj = j + DY[k];
            if (!isValid(ii, jj))
              ans = 0;
            while (isValid(ii, jj))
            {
              a[ii][jj] = '.';
              ii += DX[k];
              jj += DY[k];
            }
          }
          a[i][j] = '.';

          for (int ii = 0; ii < m; ii++)
            for (int jj = 0; jj < n; jj++)
              if (a[ii][jj] == '*')
                ans = 0;

          cout << (ans ? "YES" : "NO") << endl;
          return 0;
        }
      }

  cout << "NO" << endl;
}