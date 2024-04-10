#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> x(n), y(n), xx(n), yy(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> xx[i] >> yy[i];

  vector<int> allX = x, allY = y;
  sort(allX.begin(), allX.end());
  sort(allY.begin(), allY.end());

  for (int xId = n - 2; xId < n; xId++)
    for (int yId = n - 2; yId < n; yId++)
    {
      int curX = allX[xId], curY = allY[yId], cnt = 0;
      for (int i = 0; i < n; i++)
        cnt += 1LL * (curX - x[i]) * (curX - xx[i]) <= 0 && 1LL * (curY - y[i]) * (curY - yy[i]) <= 0;
      if (cnt >= n - 1)
      {
        cout << curX << ' ' << curY << endl;
        return 0;
      }
    }

  assert(0);
}