#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int checkXY(int x, int y, int range[])
{
  int z = x - y;
  return x >= 0 && y >= 0 && x + y > 0 && z >= range[0] && z <= range[1];
}

int checkXZ(int x, int z, int range[])
{
  int y = x - z;
  return x >= 0 && y >= 0 && x + y > 0 && y >= range[0] && y <= range[1];
}

int checkYZ(int y, int z, int range[])
{
  int x = y + z;
  return x >= 0 && y >= 0 && x + y > 0 && x >= range[0] && x <= range[1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int xMax = -oo, xMin = oo;
  int yMax = -oo, yMin = oo;
  int zMax = -oo, zMin = oo;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (char c : s)
      if (c == 'B') x++;
      else y++;
    xMax = max(x, xMax);
    xMin = min(x, xMin);
    yMax = max(y, yMax);
    yMin = min(y, yMin);
    zMax = max(x - y, zMax);
    zMin = min(x - y, zMin);
  }

  int low = 0, high = 1000000, ans = high, ansX = 0, ansY = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int x[2] = {xMax - mid, xMin + mid};
    int y[2] = {yMax - mid, yMin + mid};
    int z[2] = {zMax - mid, zMin + mid};
    int saveX = -1, saveY = -1;

    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
      {
        if (checkXY(x[i], y[j], z))
        {
          saveX = x[i];
          saveY = y[j];
        }
        if (checkXZ(x[i], z[j], y))
        {
          saveX = x[i];
          saveY = x[i] - z[j];
        }
        if (checkYZ(y[i], z[j], x))
        {
          saveX = y[i] + z[j];
          saveY = y[i];
        }
      }

    if (saveX >= 0 && x[0] <= x[1] && y[0] <= y[1] && z[0] <= z[1])
    {
      ans = mid;
      ansX = saveX;
      ansY = saveY;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  assert(ans >= 0 && ansY >= 0 && ansX + ansY > 0);
  cout << ans << endl;
  while (ansX--)
    cout << 'B';
  while (ansY--)
    cout << 'N';
  cout << endl;
}