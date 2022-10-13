#include <bits/stdc++.h>
using namespace std;
const int DX[] = {1, 0, -1, -1, 0, 1};
const int DY[] = {1, 1, 0, -1, -1, 0};

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int x, y;
    long long c[6];
    cin >> x >> y;
    for (int i = 0; i < 6; i++)
      cin >> c[i];

    long long ans = 1LL << 62;
    for (int i = 0; i < 6; i++)
      for (int j = i + 1; j < 6; j++)
        if (abs(i - j) != 3)
        {
          if (!DX[i])
          {
            int stepJ = x / DX[j];
            if (stepJ < 0)
              continue;
            int stepI = (y - DY[j] * stepJ) / DY[i];
            if (stepI >= 0)
              ans = min(ans, c[i] * stepI + c[j] * stepJ);
          }
          else if (!DY[i])
          {
            int stepJ = y / DY[j];
            if (stepJ < 0)
              continue;
            int stepI = (x - DX[j] * stepJ) / DX[i];
            if (stepI >= 0)
              ans = min(ans, c[i] * stepI + c[j] * stepJ);
          }
          else if (!DX[j])
          {
            int stepI = x / DX[i];
            if (stepI < 0)
              continue;
            int stepJ = (y - DY[i] * stepI) / DY[j];
            if (stepJ >= 0)
              ans = min(ans, c[i] * stepI + c[j] * stepJ);
          }
          else
          {
            int stepI = y / DY[i];
            if (stepI < 0)
              continue;
            int stepJ = (x - DX[i] * stepI) / DX[j];
            if (stepJ >= 0)
              ans = min(ans, c[i] * stepI + c[j] * stepJ);
          }
        }

    cout << ans << endl;
  }
}