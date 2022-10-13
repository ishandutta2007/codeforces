#include <bits/stdc++.h>
using namespace std;

int a[1010][1010], m, n;

int main()
{
  ios::sync_with_stdio(0);
  int k, x, y;
  cin >> m >> n >> k;
  for (int turn = 1; turn <= k; turn++)
  {
    cin >> x >> y;
    a[x][y] = 1;
    for (int i = x - 1; i <= x; i++)
      for (int j = y - 1; j <= y; j++)
      {
        int cnt = 0;
        for (int dx = 0; dx < 2; dx++)
          for (int dy = 0; dy < 2; dy++)
            cnt += a[i + dx][j + dy];
        if (cnt == 4)
        {
          cout << turn << endl;
          return 0;
        }
      }
  }
  
  cout << 0 << endl;
}