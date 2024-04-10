#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  string s;
  cin >> test;
  while (test--)
  {
    cin >> s;
    int n = s.size();
    vector<int> x(1, 0), y(1, 0);
    int curX = 0, curY = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'W') curY++;
      else if (s[i] == 'D') curX++;
      else if (s[i] == 'S') curY--;
      else curX--;
      x.push_back(curX);
      y.push_back(curY);
    }

    vector<int> maxX(n + 1, x[n]), minX(n + 1, x[n]);
    vector<int> maxY(n + 1, y[n]), minY(n + 1, y[n]);
    for (int i = n - 1; i >= 0; i--)
    {
      maxX[i] = max(maxX[i + 1], x[i]);
      minX[i] = min(minX[i + 1], x[i]);
      maxY[i] = max(maxY[i + 1], y[i]);
      minY[i] = min(minY[i + 1], y[i]);
    }
    long long ans = 1LL * (maxX[0] - minX[0] + 1) * (maxY[0] - minY[0] + 1);

    int curMaxX = 0, curMinX = 0, curMaxY = 0, curMinY = 0;
    for (int i = 1; i < n; i++)
    {
      curMaxX = max(curMaxX, x[i]);
      curMinX = min(curMinX, x[i]);
      curMaxY = max(curMaxY, y[i]);
      curMinY = min(curMinY, y[i]);

      long long yLen = max(curMaxY, maxY[i + 1]) - min(curMinY, minY[i + 1]) + 1;
      ans = min(ans, yLen * (max(curMaxX, max(maxX[i + 1], x[i]) + 1) - min(curMinX, minX[i + 1] + 1) + 1));
      ans = min(ans, yLen * (max(curMaxX, maxX[i + 1] - 1) - min(curMinX, min(x[i], minX[i + 1]) - 1) + 1));

      long long xLen = max(curMaxX, maxX[i + 1]) - min(curMinX, minX[i + 1]) + 1;
      ans = min(ans, xLen * (max(curMaxY, max(y[i], maxY[i + 1]) + 1) - min(curMinY, minY[i + 1] + 1) + 1));
      ans = min(ans, xLen * (max(curMaxY, maxY[i + 1] - 1) - min(curMinY, min(y[i], minY[i + 1]) - 1) + 1));
    }
    cout << ans << '\n';
  }
}