#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

long long calc(pair<int, int> a[], int x0, int x1, int y0, int y1)
{
  long long res = 0;
  res += llabs(a[0].first - x0) + llabs(a[0].second - y0);
  res += llabs(a[1].first - x0) + llabs(a[1].second - y1);
  res += llabs(a[2].first - x1) + llabs(a[2].second - y0);
  res += llabs(a[3].first - x1) + llabs(a[3].second - y1);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    vector<pair<int, int>> a;
    vector<int> allX, allY;
    for (int i = 0; i < 4; i++)
    {
      int x, y;
      cin >> x >> y;
      a.push_back({x, y});
      allX.push_back(x);
      allY.push_back(y);
    }
    sort(allX.begin(), allX.end());
    sort(allY.begin(), allY.end());

    long long ans = oo;
    int id[4] = {0, 1, 2, 3};
    pair<int, int> b[4];
    do
    {
      for (int i = 0; i < 4; i++)
        b[i] = a[id[i]];

      for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
          for (int k = 0; k < 4; k++)
          {
            // fix 2x 1y
            int side = allX[j] - allX[i];
            ans = min(ans, calc(b, allX[i], allX[j], allY[k], allY[k] + side));
            ans = min(ans, calc(b, allX[i], allX[j], allY[k] - side, allY[k]));
            // fix 2y 1x
            side = allY[j] - allY[i];
            ans = min(ans, calc(b, allX[k], allX[k] + side, allY[i], allY[j]));
            ans = min(ans, calc(b, allX[k] - side, allX[k], allY[i], allY[j]));
          }
    } while (next_permutation(id, id + 4));

    cout << ans << endl;
  }
}